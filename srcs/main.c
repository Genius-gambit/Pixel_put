/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:25 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/20 18:24:07 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pixel.h"

int	key_hook(int key, t_vars *vars)
{
	printf("Key: %d\n", key);
	if (key == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	my_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * vars->line_length + x * (vars->bits_per_pixel / 8);
	dst = vars->addr + offset;
	*(unsigned int *)dst = color;
}

void	print_circle(t_vars *vars)
{
	double	x;
	int		dist;
	double	y;
	double	ang;

	dist = 70;
	ang = 360;
	x = 350;
	y = 350;
	while (dist > 0)
	{
		ang = 360;
		while (ang > 0)
		{
			my_pixel_put(vars, x + (cos(ang) * dist),
				y + (sin(ang) * dist), 0x00FF0000);
			ang--;
		}
		dist--;
	}
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 700, 700, "Pixel");
	vars.img = mlx_new_image(vars.mlx, 700, 700);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.line_length, &vars.endian);
	print_circle(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
