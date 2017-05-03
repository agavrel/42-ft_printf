/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:26:30 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/12 12:11:26 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the number is received as long long. If l was negative, casting n as
** unsigned int will overflow it to positive value.
** if the number was negative it will take base 10.
** lowUP is to tell if it should be uppercase (1) or lowercase (0) if b > 10
*/

char	*ft_ulltoa_base(unsigned long long n, int b, int lowup)
{
	char				*s;
	unsigned long long	tmp;
	int					length;

	lowup = (lowup) ? 'A' - 10 : 'a' - 10;
	length = 1;
	tmp = n;
	while (tmp /= b)
		++length;
	if (!(s = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	s[length] = '\0';
	while (length--)
	{
		s[length] = (n % b < 10) ? n % b + '0' : n % b + lowup;
		n /= b;
	}
	return (s);
}
