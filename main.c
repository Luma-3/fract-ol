/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:33:27 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/08 23:39:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>

int	close_window(void *win, void *mlx);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 600, 300, "Hello world!");
	if (!mlx_win)
		return (1);
	// mlx_hook(mlx_win, 17, 0, close_window, mlx);
	// mlx_loop(mlx);
	// mlx_destroy_display(mlx_win);
	return (0);
}

int	close_window(void *win, void *mlx)
{
	mlx_destroy_window(mlx, win);
	exit(0);
	return (0);
}