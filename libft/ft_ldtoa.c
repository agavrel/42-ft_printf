/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:29:32 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/28 19:29:52 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ldtoa(double n, int precision)
{
	char		*s;
	long long	tmp;
	long long	t;
	int			length;

	if (!precision)
		return (ft_itoa((int)n));
	tmp = ft_round(n, precision);
	t = (tmp < 0) ? -tmp : tmp;
	length = (n < 0 ? 3 : 2);
	while (tmp /= 10)
		++length;
	(n < 1 && n > -1) ? length = 3 + precision : 0;
	(n >= 0 && n < 1) ? length = 2 + precision : 0;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[length] = '\0';
	while (length--)
	{
		s[length] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
