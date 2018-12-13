/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 06:02:33 by angavrel          #+#    #+#             */
/*   Updated: 2017/10/14 16:37:34 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		pf_putnb(t_printf *p)
{
	__intmax_t	n;

	if (p->f & F_LONG || p->f & F_LONG2)
		n = (p->f & F_LONG2) ? ((__intmax_t)va_arg(p->ap, long long)) :
			((__intmax_t)va_arg(p->ap, long));
	else if (p->f & F_SHORT || p->f & F_SHORT2)
		n = (p->f & F_SHORT2) ? (__intmax_t)((char)va_arg(p->ap, int)) :
			(__intmax_t)((short)va_arg(p->ap, int));
	else if (p->f & F_INTMAX)
		n = (va_arg(p->ap, __intmax_t));
	else if (p->f & F_SIZE_T)
		n = ((__intmax_t)va_arg(p->ap, ssize_t));
	else
		n = ((__intmax_t)va_arg(p->ap, int));
	(p->f & F_ZERO) ? p->preci = p->min_length : 0;
	itoa_printf(n, p, 0);
}

void		pf_putnb_base(t_printf *p)
{
	__uintmax_t	n;

	if (p->f & F_LONG || p->f & F_LONG2)
		n = (p->f & F_LONG2) ? ((__intmax_t)va_arg(p->ap, unsigned long long)) :
			((__intmax_t)va_arg(p->ap, unsigned long));
	else if (p->f & F_SHORT || p->f & F_SHORT2)
		n = (p->f & F_SHORT2) ? (__uintmax_t)((unsigned char)va_arg(p->ap, int))
			: (__uintmax_t)((unsigned short)va_arg(p->ap, int));
	else if (p->f & F_INTMAX)
		n = (va_arg(p->ap, __uintmax_t));
	else if (p->f & F_SIZE_T)
		n = ((__uintmax_t)va_arg(p->ap, size_t));
	else
		n = (__uintmax_t)va_arg(p->ap, unsigned int);
	itoa_base_printf(n, p->base, p);
}

static void	itoa_base_fill(__uintmax_t tmp, int b, char s[PF_BUF_SIZE],
	t_printf *p)
{
	int		len;

	if (tmp && !(p->f & F_POINTER) && (p->f & F_ZERO) && (p->f & F_SHARP) &&
	b == 16 && !(p->f & F_LONG2) && p->printed > 3)
		p->printed -= 2;
	len = p->printed;
	p->c = 'a' - 10 - ((p->f & F_UPCASE) >> 1);
	while (len--)
	{
		s[len] = tmp % b + ((tmp % b < 10) ? '0' : p->c);
		tmp /= b;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
}

void		itoa_printf(__intmax_t n, t_printf *p, int len)
{
	char		s[21];
	__uintmax_t	tmp;

	tmp = n < 0 ? -n : n;
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	if ((n < 0 || p->f & F_PLUS || p->f & F_SPACE) && p->f & F_ZERO)
		--p->preci;
	p->printed = MAX(len, p->preci);
	if (n < 0 || p->f & F_PLUS || p->f & F_SPACE)
		++p->printed;
	p->padding = (p->printed > p->min_length) ? 0 : p->min_length - p->printed;
	padding(p, 0);
	tmp = n < 0 ? -n : n;
	itoa_base_fill(tmp, 10, s, p);
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, p->printed);
	padding(p, 1);
}

void		itoa_base_printf(__uintmax_t n, int b, t_printf *p)
{
	__uintmax_t	tmp;
	char		s[21];
	int			ext;

	p->printed = 0;
	tmp = n;
	while (tmp && ++p->printed)
		tmp /= b;
	(p->f & F_ZERO) ? p->preci = p->min_length : 0;
	ext = (p->printed >= p->preci) ? 0 : 1;
	p->printed = MAX(p->preci, p->printed);
	((p->f & F_SHARP) && b == 8 && !ext) ? --p->min_length : 0;
	((p->f & F_SHARP) && b == 8 && !n && (p->f & F_APP_PRECI)) ?
	++p->printed : 0;
	((p->f & F_SHARP) && b == 16 && !(p->f & F_ZERO)) ? p->min_length -= 2 : 0;
	p->padding = MAX(0, (p->min_length - p->printed));
	padding(p, 0);
	if ((n || (p->f & F_POINTER))
		&& (p->f & F_SHARP) && ((b == 8 && !ext) || (b == 16)))
		buffer(p, "0", 1);
	if ((n || (p->f & F_POINTER)) && (p->f & F_SHARP) && b == 16)
		buffer(p, (p->f & F_UPCASE) ? "X" : "x", 1);
	itoa_base_fill(n, b, s, p);
	buffer(p, s, p->printed);
	padding(p, 1);
}
