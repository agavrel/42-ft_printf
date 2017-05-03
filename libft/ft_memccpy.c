/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:05:15 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/26 21:44:44 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*s;
	char			*d;
	unsigned int	i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		if (s[i++] == (char)c)
			return ((char *)dest + i);
	}
	return (NULL);
}
