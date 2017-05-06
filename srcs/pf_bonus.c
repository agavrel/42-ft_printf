/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 06:02:21 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/06 06:02:23 by angavrel         ###   ########.fr       */
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
** bonus function that handles colors
*/

void			color(t_printf *p)
{
	int len;

	p->printed = 5;
	if (!ft_strncmp(p->format, "{red}", (len = 4)))
		buffer(p, PF_RED, p->printed);
	else if (!ft_strncmp(p->format, "{green}", (len = 6)))
		buffer(p, PF_GREEN, p->printed);
	else if (!ft_strncmp(p->format, "{yellow}", (len = 7)))
		buffer(p, PF_YELLOW, p->printed);
	else if (!ft_strncmp(p->format, "{blue}", (len = 5)))
		buffer(p, PF_BLUE, p->printed);
	else if (!ft_strncmp(p->format, "{purple}", (len = 7)))
		buffer(p, PF_PURPLE, p->printed);
	else if (!ft_strncmp(p->format, "{cyan}", (len = 5)))
		buffer(p, PF_CYAN, p->printed);
	else if (!ft_strncmp(p->format, "{eoc}", (len = 4)))
		buffer(p, PF_EOC, --p->printed);
	else if (!(len = 0))
		p->printed = 0;
	p->format += len;
	p->len += p->printed;
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
