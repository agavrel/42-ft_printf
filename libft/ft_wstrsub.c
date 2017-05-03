/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 03:28:29 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/27 19:49:40 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t *s, unsigned start, unsigned len)
{
	wchar_t		*str;
	unsigned	i;

	if (!(str = ft_memalloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	i = 0;
	while (ft_wcharlen(s[i + start]) < len)
	{
		str[i] = s[i + start];
		i += ft_wcharlen(str[i]);
	}
	str[i] = '\0';
	return (str);
}
