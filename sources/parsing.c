/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:21:39 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/26 16:59:06 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_verif(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;
	int	dot;

	if (argc != 5)
		return (-1);
	j = 3;
	while (++j < 5)
	{
		len = ft_strlen(argv[j]);
		i = -1;
		dot = 0;
		while (++i < len)
		{
			if (!ft_isdigit(argv[j][i]) && argv[j][i] != '.' &&
				argv[j][i] != '-')
				return (ERRNO_ARG);
			if (argv[j][i] == '.')
				if (++dot > 1)
					return (ERRNO_ARG);
		}
	}
	return (EXIT_SUCCESS);
}

static int	parse_type(int argc, char **argv, t_fractol *fract)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		fract->type = mandelbrot;
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (julia_verif(argc, argv) != 0)
			return (ERRNO_ARG);
		fract->type = julia;
		fract->c.r = ft_strtod(argv[3]);
		fract->c.i = ft_strtod(argv[4]);
	}
	else if (ft_strncmp(argv[1], "burningship", 12) == 0)
		fract->type = burningship;
	else
		return (ERRNO_ARG);
	return (EXIT_SUCCESS);
}

static int	parse_color(char **argv, t_fractol *fract)
{
	if (ft_strncmp(argv[2], "rainbow", 8) == 0)
		fract->palette_creator = &create_rainbow_palette;
	else if (ft_strncmp(argv[2], "mono", 5) == 0)
		fract->palette_creator = &create_mono_palette;
	else
		return (ERRNO_ARG);
	return (0);
}

int	parse(int argc, char **argv, t_fractol *fract)
{
	int	exit_code;

	exit_code = 0;
	if (COLOR_ITER > MAX_ITERATION)
		return (ERRNO_CONFIG);
	if (argc < 3 || argc > 5)
		return (ERRNO_ARG);
	exit_code = parse_type(argc, argv, fract);
	if (exit_code != 0)
		return (exit_code);
	exit_code = parse_color(argv, fract);
	return (exit_code);
}

void	print_error(int exit_code)
{
	if (exit_code == ERRNO_ARG)
		perror("Error : Wrong arguments");
	else if (exit_code == ERRNO_MALLOC)
		perror("Error : Malloc failed");
	else if (exit_code == ERRNO_MLX)
		perror("Error : Mlx failed");
	else if (exit_code == ERRNO_CONFIG)
		ft_printf("Error : Config file is invalid\n");
	else
		ft_printf("Error : No Description! Code : %d\n", exit_code);
}
