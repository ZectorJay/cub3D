/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:51:30 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/07 12:20:33 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_img(t_both *both, t_data *something, int size_x, int size_y)
{
	something->img = mlx_new_image(CONNECT, size_x, size_y);
	something->addr = mlx_get_data_addr(something->img,
	&something->bits_per_pixel, &something->line_length,
	&something->endian);
}

void	paint_square(int x, int y, t_data *img, int color)
{
	int first;
	int second;
	int old;

	old = x;
	first = MINI_MAP_SCALE;
	second = MINI_MAP_SCALE;
	while (first-- > 0)
	{
		second = MINI_MAP_SCALE;
		x = old;
		while (second-- > 0)
		{
			my_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	paint_move(t_both *both)
{
	if (PRESS_A)
		a_move(both);
	if (PRESS_S)
		s_move(both);
	if (PRESS_D)
		d_move(both);
	if (PRESS_W)
		w_move(both);
	if (PRESS_ROT)
		rotate_player(both);
}
