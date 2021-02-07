/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:12:20 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/07 14:36:23 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sky(int y, t_both *both)
{
	int x;
	int z;
	int scale;

	x = 0;
	z = 0;
	while (z++ < y)
	{
		scale = RES_X / RAYS;
		x = NUM * scale;
		while (scale--)
		{
			my_pixel_put(&both->img, x, z, SKY_COLOR);
			x++;
		}
	}
}

void	draw_floor(int y, t_both *both)
{
	int x;
	int z;
	int scale;

	x = 0;
	z = RES_Y;
	while (z-- > y)
	{
		scale = RES_X / RAYS;
		x = NUM * scale;
		while (scale--)
		{
			my_pixel_put(&both->img, x, z, FLOOR_COLOR);
			x++;
		}
	}
}

float	doing_stuff(int y, int end, t_both *both)
{
	float endf;
	float yf;

	draw_sky(y, both);
	draw_floor(end, both);
	endf = (float)end;
	yf = (float)y;
	if (both->flag_wall == 1)
		return ((float)((WEST.height) / (endf - yf))) / QUALITY;
	else if (both->flag_wall == 2)
		return ((float)((NORTH.height) / (endf - yf))) / QUALITY;
	else if (both->flag_wall == 3)
		return ((float)((EAST.height) / (endf - yf))) / QUALITY;
	else if (both->flag_wall == 4)
		return ((float)((SOUTH.height) / (endf - yf))) / QUALITY;
	return (0);
}

void	drawing(t_both *both, float plus)
{
	if (DRAW_Y > 0 && DRAW_Y < RES_Y)
	{
		if (both->flag_wall == 1)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y,
			WEST.color_row[(int)plus]);
		else if (both->flag_wall == 2)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y,
			NORTH.color_row[(int)plus]);
		else if (both->flag_wall == 3)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y,
			EAST.color_row[(int)plus]);
		else if (both->flag_wall == 4)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y,
			SOUTH.color_row[(int)plus]);
	}
}

void	try3d(t_both *both, float len)
{
	float	scale_texture;
	float	plus;

	LEVEL = RES_Y / (len / COLUMN_HEIGHT);
	if ((int)LEVEL >= 6 * RES_Y || (int)LEVEL < 0)
		LEVEL = 6 * RES_Y;
	DRAW_Y = (int)(HRES_Y - LEVEL);
	ROW_FLAG = (int)(HRES_Y + LEVEL);
	plus = 0;
	scale_texture = doing_stuff(DRAW_Y, ROW_FLAG, both);
	skip_steps(both, &plus, scale_texture);
	while (DRAW_Y++ < ROW_FLAG)
	{
		SCALER = RES_X / RAYS;
		DRAW_X = SCALER * NUM;
		while (SCALER--)
		{
			drawing(both, plus);
			plus += scale_texture;
			DRAW_X++;
		}
	}
}
