/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:18:56 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 10:03:06 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

/*
** 32 is ascii for space and 48 for 0, flag 0 is 16 bits if set.
*/

void	padding(t_printf *p, int n)
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
