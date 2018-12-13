/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 06:02:21 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/28 07:32:37 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** bonuses done :
**   1) *   wildcard_length_modifier
**   2) n   print_len (refer to ft_printf.c : *va_arg(ap, int *) = p->len;)
**   3) m   ft_printf_putstr(strerror(errno), p)
**   4) {}  color
**   5) fF  ldtoa
*/

static double	ft_dabs(double n)
{
	return (n < 0 ? -n : n);
}

/*
** bonus function that handles float
** calculates the size of what should be sent to the buffer
** the decimals are calculated with p->preci
** decimal is first calculated as the right part, then we multiply it by
** 10 power p->preci + 1 in order to get the rounding.
*/

static void		ldtoa_fill(double n, t_printf *p, long value, int b)
{
	int		len;
	char	s[48];

	p->c = 'a' - 10 - ((p->f & F_UPCASE) >> 1);
	len = p->printed - 1 - p->preci;
	while (p->preci--)
	{
		s[len + p->preci + 1] = value % b + ((value % b < 10) ? '0' : p->c);
		value /= b;
	}
	s[len] = '.';
	value = (long)(n < 0 ? -n : n);
	while (++p->preci < len)
	{
		s[len - p->preci - 1] = value % b + ((value % b < 10) ? '0' : p->c);
		value /= b;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	if (b == 16 && (p->len += 2))
		buffer(p, "0x", 2);
	buffer(p, s, p->printed);
}

void			pf_putdouble(t_printf *p)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (double)va_arg(p->ap, double);
	(p->f & F_ZERO) ? p->preci = p->min_length : 0;
	if (!(p->f & F_APP_PRECI))
		p->preci = 7;
	len = 1;
	tmp = (long)(n < 0 ? -n : n);
	while (tmp && ++len)
		tmp /= 10;
	p->printed = p->preci + len + ((n < 0) ? 1 : 0);
	decimal = ft_dabs(n);
	decimal = (decimal - (long)(ft_dabs(n))) * ft_pow(10, p->preci + 1);
	decimal = ((long)decimal % 10 > 4) ? decimal / 10 + 1 : decimal / 10;
	value = (long)decimal;
	ldtoa_fill(n, p, value, 10);
}

void			buffer(t_printf *p, void *new, size_t size)
{
	long		new_i;
	int			diff;

	new_i = 0;
	while (PF_BUF_SIZE - p->buffer_index < size)
	{
		diff = PF_BUF_SIZE - p->buffer_index;
		ft_memcpy((char *)(p->buff + p->buffer_index), \
												(char *)(new + new_i), diff);
		size -= diff;
		new_i += diff;
		p->buffer_index += diff;
		p->len += diff;
		if (write(p->fd, p->buff, p->buffer_index) == -1)
			return ;
		p->buffer_index = 0;
	}
	ft_memcpy((char *)(p->buff + p->buffer_index), (char *)(new + new_i), size);
	p->buffer_index += size;
	p->len += size;
}

/*
** 32 is ascii for space and 48 for 0, flag 0 is 16 bits if set.
*/

void			padding(t_printf *p, int n)
{
	if (p->padding)
	{
		p->c = 32 | (p->f & F_ZERO);
		if (!n && !(p->f & F_MINUS))
			while (p->padding--)
				buffer(p, &p->c, 1);
		else if (n && (p->f & F_MINUS))
			while (p->padding--)
				buffer(p, &p->c, 1);
	}
}
