/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 04:27:59 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/12 09:50:47 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	wchar_t	*s;
	int		i;

	if (!(s = (wchar_t *)malloc(sizeof(wchar_t) *
		(1 + ft_wstrlen((unsigned *)s1) + ft_wstrlen((unsigned *)s2)))))
		return (NULL);
	i = 0;
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}
