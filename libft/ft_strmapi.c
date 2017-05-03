/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:14:23 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/02 22:52:40 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mem;
	int		i;

	if (!(mem = (char *)ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		mem[i] = f(i, s[i]);
	mem[i] = '\0';
	return (mem);
}
