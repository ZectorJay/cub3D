/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:48:52 by hmickey           #+#    #+#             */
/*   Updated: 2021/01/26 17:4:44 by hmickey          ###   ########.fr       */
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
		return ((float)((both->west.height) / (endf - yf)))/QUALITY;
	else if (both->flag_wall == 2)
		return ((float)((both->north.height) / (endf - yf)))/QUALITY;
	else if (both->flag_wall == 3)
		return ((float)((both->east.height) / (endf - yf)))/QUALITY;
	else if (both->flag_wall == 4)
		return ((float)((both->south.height) / (endf - yf)))/QUALITY;
	else
		error_message("WTF", both);
	return (0);
}

void	drawing(t_both *both, float bugabuga)
{
	if (both->flag_wall == 1)
	{
		if (DRAW_Y > 0)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y, both->west.color_row[(int)bugabuga]);
		}
	else if (both->flag_wall == 2)
	{
		if (DRAW_Y > 0)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y, both->north.color_row[(int)bugabuga]);
	}
	else if (both->flag_wall == 3)
	{
		if (DRAW_Y > 0)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y, both->east.color_row[(int)bugabuga]);
	}
	else if (both->flag_wall == 4)
	{
		if (DRAW_Y > 0)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y, both->south.color_row[(int)bugabuga]);
	}
	else
		if (DRAW_Y > 0)
			my_pixel_put(&both->img, DRAW_X, DRAW_Y, 0x000000);
}

void	try3d(t_both *both, float len)
{
	int end;
	float scale_texture;
	float bugabuga;
	LEVEL = RES_Y / (len / COLUMN_HEIGHT);
	if ((int)LEVEL >= RES_Y || (int)LEVEL < 0)
		LEVEL = RES_Y;
	DRAW_Y = (int)(HRES_Y - LEVEL);
	end = (int)(HRES_Y + LEVEL);
	bugabuga = 0;
	scale_texture = doing_stuff(DRAW_Y, end, both);
	while (DRAW_Y++ < end && DRAW_Y < RES_Y)
	{
		SCALER = RES_X / RAYS;
		DRAW_X = SCALER * NUM;
		while (SCALER--)
		{
			drawing(both, bugabuga);
				bugabuga += scale_texture;
			DRAW_X++;
		}
	}
}