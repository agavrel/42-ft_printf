/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:55:33 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 10:08:55 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

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
	p->printed = 5;
	if (!ft_strncmp(p->format, "{red}", ft_strlen("{red}")))
		COLOR(PF_RED, 5);
	else if (!ft_strncmp(p->format, "{green}", ft_strlen("{green}")))
		COLOR(PF_GREEN, 7);
	else if (!ft_strncmp(p->format, "{yellow}", ft_strlen("{yellow}")))
		COLOR(PF_YELLOW, 8);
	else if (!ft_strncmp(p->format, "{blue}", ft_strlen("{blue}")))
		COLOR(PF_BLUE, 6);
	else if (!ft_strncmp(p->format, "{purple}", ft_strlen("{purple}")))
		COLOR(PF_PURPLE, 8);
	else if (!ft_strncmp(p->format, "{cyan}", ft_strlen("{cyan}")))
		COLOR(PF_CYAN, 6);
	else if (!ft_strncmp(p->format, "{eoc}", ft_strlen("{eoc}")))
		COLOR(PF_EOC, 5);
	else
		p->printed = 0;
	p->len += p->printed;
	--p->format;
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
	value = (long)(ABS(n));
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
	tmp = (long)(ABS(n));
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
