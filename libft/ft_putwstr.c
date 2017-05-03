/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 04:32:50 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 10:17:23 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *s)
{
	int		len;

	len = ft_wstrlen((unsigned *)s);
	(!len) ? write(1, "(null)", 6) : write(1, s, len);
	return ((!len) ? 6 : len);
}
