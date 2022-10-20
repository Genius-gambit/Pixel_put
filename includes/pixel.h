/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:00:54 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/20 18:25:08 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx_opengl/mlx.h"

# ifdef OSX
#  include "../minilibx_opengl/mlx.h"
#  define W 13
#  define D 2
#  define A 0
#  define S 1
#  define P 35
#  define ARROW_L 123
#  define ARROW_R 124
#  define ESC 53
# endif

# ifdef LINUX
#  include "../minilibx_linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define D 100
#  define E 101
#  define S 115
#  define A 97
#  define P 112
#  define ARROW_R 65363
#  define ARROW_L 65361
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

#endif