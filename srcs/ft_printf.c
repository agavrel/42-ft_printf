/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:18:44 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 06:34:46 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

/*
** 						~ PRINTF LOOP ~
**
** printf will return p.len: the total len of what was displayed by printf
** if there is a % we will parse user input, else we will display it.
*/

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	p.fd = 1;
	p.format = (char *)format;
	va_start(p.ap, format);
	while (*p.format)
	{
		if (*p.format == '%')
		{
			++p.format;
			if (!p.format[0] || (p.format[0] == ' ' && (!p.format[1]
			|| (!p.format[2] && p.format[1] == 'h'))))
				break ;
			else
				parse_optionals(&p);
		}
		else
			buffer(&p, &p.format[0], 1);
		++p.format;
	}
	write(p.fd, p.buff, p.buffer_index);
	va_end(p.ap);
	return (p.len);
}

/*
** function that displays pointer address
*/

void	print_pointer_address(t_printf *p)
{
	void			*pointer;

	pointer = va_arg(p->ap, void *);
	p->f &= ~F_SHARP;
	p->min_length -= (p->f & F_ZERO ? 2 : 0);
	p->padding = (p->printed > p->min_length - 3) ? 0 :
		p->min_length - 3 - p->printed;
	p->f |= F_SHARP;
	itoa_base_printf((uintmax_t)pointer, 16, p);
}

/*
** function if no conversion specifier was found.
*/

void	cs_not_found(t_printf *p)
{
	if ((p->padding = p->min_length - 1) > 0)
	{
		padding(p, 0);
		buffer(p, p->format, 1);
		padding(p, 1);
	}
	else
		buffer(p, p->format, 1);
}
