/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:14:50 by jbrousse          #+#    #+#             */
/*   Updated: 2023/12/26 18:20:22 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//Settings	

# define MAX_ITERATION 500

# define COLOR_ITER 500

# define MAX_REC_SIZE 25

# define HEIGHT 1080
# define WIDTH 1080

// Commands

# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_UP 4

# define ESC_KEY 65307
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_C 99
# define KEY_V 118

// Errors Codes

# define ERRNO_MALLOC 12
# define ERRNO_MLX 5
# define ERRNO_ARG 22
# define ERRNO_CONFIG 13

#endif