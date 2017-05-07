/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 23:58:17 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/06 16:25:32 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the len of a string containing widechars
*/

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
 	while (*s != L'\0')
 	{
 		len += ft_wcharlen(*s);
 		++s;
	}
	return (len);
}
