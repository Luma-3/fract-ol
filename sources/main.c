/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:19:46 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 18:26:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fcntl.h"

static int	init_display(t_fractol *fract, t_display *display, t_img *img)
{
	if (open_display(display) == -1)
		return (-1);
	if (create_img(img, display) == -1)
		return (-1);
	fract->display = display;
	fract->img = img;
	return (0);
}

static void	print_help(void)
{
	ft_putendl_fd(HELP_MSG, 1);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;
	t_display	display;
	t_img		img;

	errno = parse(argc, argv, &fract);
	if (errno != 0)
	{
		if (errno == ERRNO_ARG)
			print_help();
		print_error(errno);
		return (errno);
	}
	if (init_display(&fract, &display, &img) == -1)
		return (1);
	init_fract(&fract);
	mlx_key_hook(fract.display->win, &key_hook, &fract);
	mlx_hook(fract.display->win, 17, 1L << 17, &cross_close, &fract);
	mlx_mouse_hook(fract.display->win, &mouse_hook, &fract);
	render(&fract, fract.rect_size);
	mlx_loop(fract.display->mlx);
	return (0);
}
