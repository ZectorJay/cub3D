/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:51:30 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 04:19:10 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void my_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_img(t_both *both, t_data *something, int size_x, int size_y)
{
	something->img = mlx_new_image(connect, size_x, size_y);
	something->addr = mlx_get_data_addr(something->img, &something->bits_per_pixel, &something->line_length,
    &something->endian);
}

void paint_square(int x, int y, t_data *img, int color)
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
	if (press_a)
		a_move(both);
	if (press_s)
		s_move(both);
	if (press_d)
		d_move(both);
	if (press_w)
		w_move(both);
	if (press_rot)
		rotate_player(both);
}