/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formula.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:23:58 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/12 12:09:28 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

float		vector_len(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float		get_3d_y(t_vector a)
{
	return (a.y / 2.0f - a.x / 2 - (4.0f / 3.0f * a.z));
}

float		get_3d_x(t_vector a)
{
	return (a.x + a.y);
}
