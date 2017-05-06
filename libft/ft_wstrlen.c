/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 23:58:17 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/06 16:01:10 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** returns the len of a string containing widechars
*/

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	while (len += (ft_wcharlen(*s) > 0))
		++s;
	return (len);
}
