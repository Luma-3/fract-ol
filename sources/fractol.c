/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:10:37 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/26 11:43:43 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	normalize(double value, double max)
{
	return (2 * (value / max) - 1);
}

int	calcule_iter(t_coord *coord, t_fractol *fract)
{
	t_complex	y;

	y.r = fract->pos_x + ((double)coord->x - WIDTH / 2) * fract->zoom / WIDTH;
	y.i = fract->pos_y + ((double)coord->y - HEIGHT / 2) * fract->zoom / HEIGHT;
	return (fract->type(&y, &fract->c));
}

void	init_fract(t_fractol *fract)
{
	int	rect_size;

	rect_size = MAX_REC_SIZE;
	fract->palette = ft_calloc(MAX_ITERATION + 1, sizeof(t_rgb));
	if (!fract->palette)
		return ;
	while (rect_size > 6)
	{
		if (WIDTH % rect_size == 0 && HEIGHT % rect_size == 0)
			break ;
		rect_size--;
	}
	fract->rect_size = rect_size;
	fract->zoom = 4.0;
	fract->pos_x = 0.0;
	fract->pos_y = 0.0;
	fract->color_shift = 0.0;
	fract->palette_creator(fract->palette, fract->color_shift);
}
