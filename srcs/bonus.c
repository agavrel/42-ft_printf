/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:55:33 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/04 13:36:19 by angavrel         ###   ########.fr       */
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

/*
** returns position of a character in a string
*/

int				ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

/*
** bonus function that handles colors
*/

void			color(t_printf *p)
{
	int	len;

	if (!ft_strncmp(p->format, "{red}", (len = ft_strlen("{red}"))))
		buffer(p, PF_RED, len);
	else if (!ft_strncmp(p->format, "{green}", (len = ft_strlen("{green}"))))
		buffer(p, PF_GREEN, len);
	else if (!ft_strncmp(p->format, "{yellow}", (len = ft_strlen("{yellow}"))))
		buffer(p, PF_YELLOW, len);
	else if (!ft_strncmp(p->format, "{blue}", (len = ft_strlen("{blue}"))))
		buffer(p, PF_BLUE, len);
	else if (!ft_strncmp(p->format, "{purple}", (len = ft_strlen("{purple}"))))
		buffer(p, PF_PURPLE, len);
	else if (!ft_strncmp(p->format, "{cyan}", (len = ft_strlen("{cyan}"))))
		buffer(p, PF_CYAN, len);
	else if (!ft_strncmp(p->format, "{eoc}", (len = ft_strlen("{eoc}"))))
		buffer(p, PF_EOC, len);
	else
		len = 0;
	p->format += len - 1;
	p->len += len;
}

static double	ft_dabs(double n)
{
	return (n < 0 ? -n : n);
}

/*
** bonus function that handles float
** calculates the size of what should be sent to the buffer
** the decimals are calculated with p->precision
** decimal is first calculated as the right part, then we multiply it by
** 10 power p->precision + 1 in order to get the rounding.
*/

static void		ldtoa_fill(double n, t_printf *p, long value)
{
	int		len;
	int		accuracy;
	char	s[48];

	len = p->printed - 1 - p->precision;
	accuracy = p->printed - 1 - len;
	while (accuracy--)
	{
		s[len + accuracy + 1] = value % 10 + '0';
		value /= 10;
	}
	(p->precision > 0) ? s[len] = '.' : 0;
	value = (long)(n < 0 ? -n : n);
	while (++accuracy < len)
	{
		s[len - accuracy - 1] = value % 10 + '0';
		value /= 10;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, len + 1 + 6);
}

void			pf_putdouble(t_printf *p)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (double)va_arg(p->ap, double);
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	if (!(p->f & F_APP_PRECI))
		p->precision = 6;
	len = (p->precision > 0) ? 1 : 0;
	tmp = (long)(n < 0 ? -n : n);
	while (tmp && ++len)
		tmp /= 10;
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	p->printed = p->precision + len + ((n < 0) ? 1 : 0);
	decimal = ft_dabs(n);
	decimal = (decimal - (long)(ft_dabs(n))) * ft_pow(10, p->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;
	ldtoa_fill(n, p, value);
}
