/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:31:22 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/05 23:50:39 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** 00000000 -- 0000007F: 	0xxxxxxx
** 00000080 -- 000007FF: 	110xxxxx 10xxxxxx
** 00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
** 00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
** nb_bytes <= MB_CUR_MAX define in stdlib.h
*/

static void	pf_putwchar(t_printf *p, unsigned int wc, int wlen, int nb_bytes)
{
	char	tmp[4];

	if (nb_bytes <= wlen && nb_bytes <= MB_CUR_MAX)
	{
		if (nb_bytes == 1)
			tmp[0] = wc;
		else
		{
			if (nb_bytes == 2)
				tmp[0] = ((wc & (0x1f << 6)) >> 6) | 0xC0;
			else
			{
				if (nb_bytes == 3)
					tmp[0] = ((wc >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((wc >> 18) & 7) | 0xF0;
					tmp[1] = ((wc >> 12) & 0x3f) | 0x80;
				}
				tmp[nb_bytes - 2] = ((wc >> 6) & 0x3f) | 0x80;
			}
			tmp[nb_bytes - 1] = (wc & 0x3f) | 0x80;
		}
		buffer(p, tmp, nb_bytes);
	}
}

/*
** prints string and returns its len, if no len will print (null) and return 6
*/

void		pf_puterror(char *s, t_printf *p)
{
	if (!s)
	{
		if (!(p->f & F_ZERO))
			buffer(p, "(null)", 6);
		else
			while (p->min_length--)
				buffer(p, "0", 1);
	}
	else
		buffer(p, s, ft_strlen(s));
}

/*
** print wide string and returns total len
** please refer to libft for ft_wcharlen and ft_wstrlen
*/

void		pf_putwstr(t_printf *p)
{
	wchar_t		*s;
	int			charlen;

	if (!(s = va_arg(p->ap, wchar_t *)))
		pf_puterror(0, p);
	else
	{
		p->printed = (int)(ft_wstrlen((unsigned *)s));
		if (p->f & F_APP_PRECI)
			p->printed = p->printed > p->precision ? p->precision : p->printed;
		if ((p->padding = (p->min_length - p->printed)) < 0)
			p->padding = 0;
		p->f = (p->min_length > p->precision) ?
			p->f & ~F_APP_PRECI : p->f | F_APP_PRECI;
		padding(p, 0);
		charlen = 0;
		while ((p->c = *s++) && (p->printed -= charlen) > 0)
		{
			charlen = ft_wcharlen(p->c);
			pf_putwchar(p, p->c, p->printed, charlen);
		}
		padding(p, 1);
	}
}

/*
** print regular string and returns its len
*/

void		pf_putstr(t_printf *p)
{
	unsigned	*s;

	if (!(s = va_arg(p->ap, unsigned*)))
		pf_puterror(0, p);
	else
	{
		p->printed = (int)(ft_strlen((char*)s));
		if (p->f & F_APP_PRECI)
			p->printed = p->printed > p->precision ? p->precision : p->printed;
		if ((p->padding = (p->min_length - p->printed)) > 0)
		{
			p->c = 32 | (p->f & F_ZERO);
			if (!(p->f & F_MINUS))
				while (p->padding--)
					buffer(p, &p->c, 1);
			else
			{
				buffer(p, s, p->printed);
				while (p->padding--)
					buffer(p, &p->c, 1);
				return ;
			}
		}
		buffer(p, s, p->printed);
	}
}

/*
** returns a single character len and display it
** refer to libft for putwchar amd wcharlen functions
*/

void		pf_character(t_printf *p, unsigned c)
{
	if ((p->f & F_LONG || p->f & F_LONG2) && !(p->printed = ft_wcharlen(c))
			&& !(p->padding = 0))
		p->len = -1;
	else
		p->printed = 1;
	if ((p->padding = p->min_length - p->printed) < 0)
		p->padding = 0;
	padding(p, 0);
	pf_putwchar(p, c, p->printed, p->printed);
	padding(p, 1);
}
