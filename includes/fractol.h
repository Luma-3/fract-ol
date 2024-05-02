/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:17 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/02 19:15:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# include "libft.h"
# include "mlx.h"

# include "config.h"

# define HELP_MSG "******************************** FRACTOL HELP ********************************\n\
==============================================================================\n\
Usage: ./fractol [fractal type] [color palette] (julia real) (julia imaginary)\n\
---\n\
Type : julia, mandelbrot, burningship\n\
Color : mono, rainbow\n\
---\n\
For the Julia fractal, both real and imaginary parameters are mandatory!\n\
==============================================================================\n\
******************************** FRACTOL HELP ********************************\n"

typedef struct s_display
{
	void			*mlx;
	void			*win;
}					t_display;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_pixel
{
	int			iteration;
	int			x;
	int			y;
}				t_pixel;

typedef struct s_fractol
{
	int			(*type)(t_complex *z, t_complex *c);
	t_complex	c;
	double		zoom;
	double		pos_x;
	double		pos_y;
	void		(*palette_creator)(t_rgb *rgb, double shift);
	t_rgb		*palette;
	double		color_shift;
	int			rect_size;
	t_display	*display;
	t_img		*img;
}				t_fractol;

void			init_fract(t_fractol *fract);

int				mandelbrot(t_complex *c, t_complex *z);
int				julia(t_complex *z, t_complex *c);
int				burningship(t_complex *c, t_complex *z);

int				calcule_iter(t_coord *coord, t_fractol *fract);
void			mariani_silver(t_coord coord, int rect_size, t_fractol *fract);

int				mouse_hook(int keycode, int x, int y, t_fractol *fract);
int				key_hook(int keycode, t_fractol *fract);

double			normalize(double value, double max);

// Graphic

int				create_argb(int a, t_rgb color);

void			render(t_fractol *fract, int rect_size);
void			color_zone(t_fractol *fract, t_coord *coord, int rect_size,
					int nb_iter);

void			create_rainbow_palette(t_rgb *rgb, double shift);
void			create_mono_palette(t_rgb *rgb, double shift);

int				get_color(t_rgb *palette, int iteration);

t_rgb			linear_interpolate(t_rgb color1, t_rgb color2, double ratio);

// Display			

int				open_display(t_display *display);
int				close_display(t_display *display);
int				cross_close(t_fractol *fract);
int				create_img(t_img *img, t_display *display);

void			put_pixel(t_img *img, int x, int y, int color);

// Parsing

int				parse(int argc, char **argv, t_fractol *fract);
void			print_error(int exit_code);

#endif