/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:18:05 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:52 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship(t_complex *c, t_complex *z)
{
	int			i;
	double		tmp;

	i = -1;
	*z = (t_complex){0.0, 0.0};
	while (++i < MAX_ITERATION)
	{
		if ((z->r * z->r + z->i * z->i) > 4.0)
			break ;
		z->r = fabs(z->r);
		z->i = fabs(z->i);
		tmp = 2.0 * z->r * z->i + c->i;
		z->r = z->r * z->r - z->i * z->i + c->r;
		z->i = tmp;
	}
	return (i);
}
