/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_converter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:07:01 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/16 02:15:20 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_hex2rgb(int hex)
{
	t_rgb	rgb;

	rgb.r = (hex >> 16) & 0xFF;
	rgb.g = (hex >> 8) & 0xFF;
	rgb.b = hex & 0xFF;
	return (rgb);
}

int		ft_rgb2hex(t_rgb rgb)
{
	return (((int)rgb.r << 16) + ((int)rgb.g << 8) + rgb.b);
}

t_rgb	ft_hsb2rgb(t_hsb hsb)
{
	t_rgb		rgb;
	t_vector	i;

	i.w = (int)(hsb.h / 60);
	i.w = (hsb.h / 60) - i.w;
	i.x = 0xff * (hsb.b * (1 - hsb.s));
	i.y = 0xff * (hsb.b * (1 - i.w * hsb.s));
	i.z = 0xff * (hsb.b * (1 - (1 - i.w) * hsb.s));
	hsb.b *= 0xff;
	hsb.h = (int)((hsb.h) / 60);
	if (hsb.h == 0)
		rgb = (t_rgb) {.r = hsb.b, .g = i.z, .b = i.x};
	else if (hsb.h == 1)
		rgb = (t_rgb) {.r = i.y, .g = hsb.b, .b = i.x};
	else if (hsb.h == 2)
		rgb = (t_rgb) {.r = i.x, .g = hsb.b, .b = i.z};
	else if (hsb.h == 3)
		rgb = (t_rgb) {.r = i.x, .g = i.y, hsb.b};
	else if (hsb.h == 4)
		rgb = (t_rgb) {.r = i.z, .g = i.x, hsb.b};
	else if (hsb.h == 5)
		rgb = (t_rgb) {.r = hsb.b, .g = i.x, .b = i.y};
	else
		rgb = (t_rgb) {.r = 0, .g = 0, .b = 0};
	return (rgb);
}

int		ft_hsb2hex(t_hsb hsb)
{
	return (ft_rgb2hex(ft_hsb2rgb(hsb)));
}

int		ft_shade_color(int c, double n)
{
	t_rgb	rgb;

	n = (1 - ft_fclamp(n, 0, 1));
	rgb.r = ((int)(n * ((c >> 16) & 0xff)) << 16);
	rgb.g = ((int)(n * ((c >> 8) & 0xff)) << 8);
	rgb.b = n * (c & 0xff);
	return (rgb.r + rgb.g + rgb.b);
}
