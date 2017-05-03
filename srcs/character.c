/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:18:56 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 06:38:57 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	padding(t_printf *p, int n)
{
	if (!n && !(p->f & F_MINUS))
		while (p->padding--)
			buffer(p, (p->f & F_ZERO) ? "0" : " ", 1);
	else if (n && (p->f & F_MINUS))
		while (p->padding--)
			buffer(p, (p->f & F_ZERO) ? "0" : " ", 1);
}

/*
** handles %%
*/

void	percent_char(t_printf *p)
{
	if ((p->padding = p->min_length - 1) < 0)
		p->padding = 0;
	padding(p, 0);
	buffer(p, "%", 1);
	padding(p, 1);
}

/*
** returns a single character len and display it
** refer to libft for putwchar amd wcharlen functions
*/

void	pf_character(t_printf *p)
{
	unsigned	c;
	int			len;

	c = va_arg(p->ap, unsigned);
	len = (p->f & LM_LONG || p->f & LM_LONG2) ? ft_wcharlen(c) : 1;
	if ((p->padding = p->min_length - len) < 0)
		p->padding = 0;
	padding(p, 0);
	(p->f & LM_LONG || p->f & LM_LONG2) ? buffer(p, &c, 4) : buffer(p, &c, 1);
	padding(p, 1);
}
