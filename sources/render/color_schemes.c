/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:25:09 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/26 16:46:02 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_argb(int a, t_rgb color)
{
	return ((a << 24) | (color.r << 16) | (color.g << 8) | color.b);
}

t_rgb	linear_interpolate(t_rgb color1, t_rgb color2, double ratio)
{
	t_rgb	result;

	result.r = (unsigned char)((1.0 - ratio) * color1.r + ratio * color2.r);
	result.g = (unsigned char)((1.0 - ratio) * color1.g + ratio * color2.g);
	result.b = (unsigned char)((1.0 - ratio) * color1.b + ratio * color2.b);
	return (result);
}

void	create_rainbow_palette(t_rgb *rgb, double shift)
{
	float	frequency;
	int		i;

	frequency = 0.1;
	i = -1;
	while (++i < COLOR_ITER)
	{
		rgb[i].r = (unsigned char)(sin(frequency * i + shift) * 127 + 128);
		rgb[i].g = (unsigned char)(sin(frequency * i + 4 + shift) * 127 + 128);
		rgb[i].b = (unsigned char)(sin(frequency * i + 8 + shift) * 127 + 128);
	}
}

void	create_mono_palette(t_rgb *rgb, double shift)
{
	int		i;
	float	frequency;

	(void)shift;
	i = -1;
	frequency = 255.0 / (float)COLOR_ITER;
	while (++i < COLOR_ITER)
	{
		rgb[i].r = (unsigned char)(frequency * i);
		rgb[i].g = (unsigned char)(frequency * i);
		rgb[i].b = (unsigned char)(frequency * i);
	}
}
