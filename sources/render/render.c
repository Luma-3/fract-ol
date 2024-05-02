/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:12:49 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/21 16:38:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_rgb *palette, int iteration)
{
	double	ratio;
	int		index;
	t_rgb	rgb;

	if (iteration == MAX_ITERATION)
		return (0x000000);
	ratio = (double)iteration / (double)MAX_ITERATION;
	index = (int)(ratio * (MAX_ITERATION - 1));
	rgb = linear_interpolate(palette[index], palette[index + 1], ratio);
	return (create_argb(0x00, rgb));
}

void	color_zone(t_fractol *fract, t_coord *coord, int rect_size, int nb_iter)
{
	int	x;
	int	y;
	int	color;

	x = coord->x - 1;
	while (++x < rect_size + coord->x + 1)
	{
		y = coord->y - 1;
		while (++y < rect_size + coord->y + 1)
		{
			color = get_color(fract->palette, nb_iter);
			put_pixel(fract->img, x, y, color);
		}
	}
}

void	render(t_fractol *fract, int rect_size)
{
	int	rect_x;
	int	rect_y;

	mlx_clear_window(fract->display->mlx, fract->display->win);
	rect_x = 0;
	while (rect_x < WIDTH)
	{
		rect_y = 0;
		while (rect_y < HEIGHT)
		{
			mariani_silver((t_coord){rect_x, rect_y}, rect_size, fract);
			rect_y += rect_size;
		}
		rect_x += rect_size;
	}
	mlx_put_image_to_window(fract->display->mlx, fract->display->win,
		fract->img->img, 0, 0);
}
