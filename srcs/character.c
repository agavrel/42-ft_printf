/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:18:56 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 09:01:26 by angavrel         ###   ########.fr       */
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
** returns a single character len and display it
** refer to libft for putwchar amd wcharlen functions
*/

void	pf_character(t_printf *p, unsigned c)
{
	p->printed = (p->f & LM_LONG || p->f & LM_LONG2) ? ft_wcharlen(c) : 1;
	if ((p->padding = p->min_length - p->printed) < 0)
		p->padding = 0;
	padding(p, 0);
	pf_putwchar(p, c, p->printed, p->printed);
	padding(p, 1);
}
