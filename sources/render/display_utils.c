/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:11:28 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/20 14:59:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	open_display(t_display *display)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		return (-1);
	display->win = mlx_new_window(display->mlx, WIDTH, HEIGHT, "Fractol");
	if (!display->win)
	{
		free(display->mlx);
		return (-1);
	}
	return (0);
}

int	create_img(t_img *img, t_display *display)
{
	img->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (close_display(display), -1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	if (!img->addr)
	{
		mlx_destroy_image(display->mlx, img->img);
		return (close_display(display), -1);
	}
	return (0);
}

int	cross_close(t_fractol *fract)
{
	free(fract->palette);
	mlx_destroy_image(fract->display->mlx, fract->img->img);
	close_display(fract->display);
	return (0);
}

int	close_display(t_display *display)
{
	mlx_destroy_window(display->mlx, display->win);
	mlx_destroy_display(display->mlx);
	free(display->mlx);
	exit(0);
}
