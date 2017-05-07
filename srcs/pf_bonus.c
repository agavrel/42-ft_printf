/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 06:02:21 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/07 16:12:11 by angavrel         ###   ########.fr       */
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

static void		ldtoa_fill(double n, t_printf *p, long value, int b)
{
	int		len;
	char	s[48];

	p->c = 'a' - 10 - ((p->f & F_UPCASE) >> 1);
	len = p->printed - 1 - p->precision;
	while (p->precision--)
	{
		s[len + p->precision + 1] = value % b + ((value % b < 10) ? '0' : p->c);
		value /= b;
	}
	s[len] = '.';
	value = (long)(n < 0 ? -n : n);
	while (++p->precision < len)
	{
		s[len - p->precision - 1] = value % b + ((value % b < 10) ? '0' : p->c);
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

void			pf_putdouble(t_printf *p, int base)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (double)va_arg(p->ap, double);
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	if (!(p->f & F_APP_PRECI))
		p->precision = 6 + base - 10 + 1;
	len = 1;
	tmp = (long)(n < 0 ? -n : n);
	while (tmp && ++len)
		tmp /= base;
	p->printed = p->precision + len + ((n < 0) ? 1 : 0);
	decimal = ft_dabs(n);
	decimal = (decimal - (long)(ft_dabs(n))) * ft_pow(base, p->precision + 1);
	decimal = ((long)decimal % base > 4) ? decimal / base + 1 : decimal / base;
	value = (long)decimal;
	ldtoa_fill(n, p, value, base);
}
