/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:31:23 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/21 11:56:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	verif_bud(t_complex c)
{
	double	cr_plus_1;

	c.r *= 4.0;
	c.i *= 4.0;
	cr_plus_1 = c.r + 1;
	return (cr_plus_1 * cr_plus_1 + c.i * c.i < (1 / 16));
}

int	mandelbrot(t_complex *c, t_complex *z)
{
	int			i;
	double		tmp;

	i = -1;
	*z = (t_complex){0.0, 0.0};
	if (verif_bud(*c))
		return (MAX_ITERATION);
	while (++i < MAX_ITERATION)
	{
		if ((z->r * z->r + z->i * z->i) > 4.0)
			break ;
		tmp = 2.0 * z->r * z->i + c->i;
		z->r = z->r * z->r - z->i * z->i + c->r;
		z->i = tmp;
	}
	return (i);
}
