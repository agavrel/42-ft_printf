/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 13:48:13 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/23 06:48:44 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** inspired by https://github.com/lattera/glibc/blob/master/string/strlen.c
*/

#include <string.h>
#include <stdlib.h>

static const char	*byte_zero(const unsigned long *longword_ptr,
	unsigned long lomagic, unsigned long himagic)
{
	unsigned long			longword;
	const char				*cp;

	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic))
		{
			cp = (const char *)(longword_ptr - 1);
			if (!cp[0])
				return (cp);
			if (!cp[1])
				return (cp + 1);
			if (!cp[2] || !cp[3])
				return (cp + (!cp[2] ? 2 : 3));
			if (sizeof(longword) > 4)
			{
				if (!cp[4] || !cp[5])
					return (cp + (!cp[4] ? 4 : 5));
				if (!cp[6] || !cp[7])
					return (cp + (!cp[6] ? 6 : 7));
			}
		}
	}
}

size_t				ft_strlen(const char *str)
{
	const char				*char_ptr;
	const unsigned long		*longword_ptr;
	unsigned long			longword;
	unsigned long			himagic;
	unsigned long			lomagic;

	char_ptr = str;
	while ((unsigned long int)char_ptr & (sizeof(longword) - 1))
	{
		if (!(*char_ptr))
			return (char_ptr - str);
		++char_ptr;
	}
	longword_ptr = (unsigned long *)char_ptr;
	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof(longword) > 4)
	{
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}
	if (sizeof(longword) > 8)
		abort();
	return (byte_zero(longword_ptr, lomagic, himagic) - str);
}
