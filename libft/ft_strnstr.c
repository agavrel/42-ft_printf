/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:19:36 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/27 21:42:21 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	n = ft_strlen(little);
	while (*big && (len-- >= n))
		if (ft_strncmp(big++, little, n) == 0)
			return ((char *)big++ - 1);
	return (NULL);
}
