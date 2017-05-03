/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:37:42 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/21 20:40:10 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesort_array(char **tab, size_t n)
{
	int		sorted;
	size_t	i;
	char	*s;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < n - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				s = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = s;
				sorted = 0;
			}
			i++;
		}
	}
}
