/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:12:16 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/26 21:41:17 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src > dst)
		while (len--)
			((char *)dst)[i++] = *((char *)src++);
	else
		while (len--)
			*((char *)dst + len) = *((char *)src + len);
	return (dst);
}
