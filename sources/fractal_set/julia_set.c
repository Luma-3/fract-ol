/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:02:20 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/20 15:11:10 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex *z, t_complex *c)
{
	int		i;
	double	tmp;

	i = -1;
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
