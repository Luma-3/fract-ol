/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_checking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:55:22 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/21 16:38:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	small_rectsize(t_coord coord, t_fractol *fract)
{
	int	x;
	int	y;
	int	nb_iter;
	int	color;

	x = coord.x - 1;
	while (++x < coord.x + 4)
	{
		y = coord.y - 1;
		while (++y < coord.y + 4)
		{
			nb_iter = calcule_iter(&(t_coord){x, y}, fract);
			color = get_color(fract->palette, nb_iter);
			put_pixel(fract->img, x, y, color);
		}
	}
}

void	get_border(t_pixel *border, t_coord *coord, int rect_size)
{
	int	x;
	int	y;

	x = -1;
	while (++x < rect_size)
	{
		border[x] = (t_pixel){0, coord->x + x, coord->y};
		border[x + rect_size] = (t_pixel){0, coord->x + x, coord->y
			+ rect_size};
	}
	y = -1;
	while (++y < rect_size)
	{
		border[2 * rect_size + y] = (t_pixel){0, coord->x, coord->y + y};
		border[2 * rect_size + y + rect_size] = (t_pixel){0, coord->x
			+ rect_size, coord->y + y};
	}
}

void	divide_border(t_coord coord, t_fractol *fract, int old_rect_size)
{
	int		i;
	int		rect_size;
	t_coord	new_coord[4];

	i = 0;
	rect_size = ceil(old_rect_size / 2);
	new_coord[0] = (t_coord){coord.x, coord.y};
	new_coord[1] = (t_coord){coord.x + rect_size, coord.y};
	new_coord[2] = (t_coord){coord.x, coord.y + rect_size};
	new_coord[3] = (t_coord){coord.x + rect_size, coord.y + rect_size};
	if (rect_size < 3)
		small_rectsize(coord, fract);
	while (i < 4)
	{
		if (rect_size > 2)
			mariani_silver(new_coord[i], rect_size, fract);
		i++;
	}
}

int	rectangle_checking(t_pixel *border, t_fractol *fract, int border_size,
		int rect_size)
{
	int		i;
	t_coord	coord;

	i = -1;
	while (++i < border_size)
	{
		coord = (t_coord){border[i].x, border[i].y};
		border[i].iteration = calcule_iter(&coord, fract);
	}
	i = -1;
	while (++i < border_size - 1)
	{
		if (border[i].iteration != border[i + 1].iteration)
			break ;
	}
	if (i == border_size - 1)
		color_zone(fract, &(t_coord){border[0].x, border[0].y}, rect_size,
			border[0].iteration);
	else
		return (1);
	return (0);
}

void	mariani_silver(t_coord coord, int rect_size, t_fractol *fract)
{
	t_pixel	*border;
	int		border_size;

	border_size = 4 * rect_size;
	border = malloc(border_size * sizeof(t_pixel));
	if (!border)
		return ;
	get_border(border, &coord, rect_size);
	if (rectangle_checking(border, fract, border_size, rect_size))
	{
		free(border);
		divide_border(coord, fract, rect_size);
	}
	else
		free(border);
}
