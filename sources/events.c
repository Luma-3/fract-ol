/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:56:40 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/21 16:54:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *fract, double shift)
{
	fract->color_shift += shift;
	fract->palette_creator(fract->palette, fract->color_shift);
}

void	zoom(t_fractol *fract, double zoom)
{
	fract->zoom *= zoom;
}

void	move(t_fractol *fract, double distance, char dir)
{
	if (dir == 'u')
		fract->pos_y -= distance;
	else if (dir == 'd')
		fract->pos_y += distance;
	else if (dir == 'l')
		fract->pos_x -= distance;
	else if (dir == 'r')
		fract->pos_x += distance;
}

int	key_hook(int keycode, t_fractol *fract)
{
	if (keycode == ESC_KEY)
	{
		free(fract->palette);
		mlx_destroy_image(fract->display->mlx, fract->img->img);
		close_display(fract->display);
	}
	else if (keycode == KEY_MINUS)
		zoom(fract, 2);
	else if (keycode == KEY_PLUS)
		zoom(fract, 0.5);
	else if (keycode == KEY_UP)
		move(fract, 0.01 * fract->zoom, 'u');
	else if (keycode == KEY_DOWN)
		move(fract, 0.01 * fract->zoom, 'd');
	else if (keycode == KEY_LEFT)
		move(fract, 0.01 * fract->zoom, 'l');
	else if (keycode == KEY_RIGHT)
		move(fract, 0.01 * fract->zoom, 'r');
	else if (keycode == KEY_C)
		color_shift(fract, 0.1);
	else if (keycode == KEY_V)
		color_shift(fract, -0.1);
	render(fract, fract->rect_size);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *fract)
{
	double	dx;
	double	dy;

	dx = normalize(x, WIDTH);
	dy = normalize(y, HEIGHT);
	if (keycode == MOUSE_WHEEL_DOWN)
	{
		zoom(fract, 0.5);
		fract->pos_x += dx * fract->zoom * 0.75;
		fract->pos_y += dy * fract->zoom * 0.75;
	}
	else if (keycode == MOUSE_WHEEL_UP)
		zoom(fract, 2);
	render(fract, fract->rect_size);
	return (0);
}
