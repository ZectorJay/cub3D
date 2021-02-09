/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 06:42:40 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 18:28:23 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		fix_params(t_both *both, float *add, float *another_one,
				int *flag)
{
	float	rays;

	if (SPR_NUM[SP_COUNTER].len < MINI_MAP_SCALE / 15)
		SPR_NUM[SP_COUNTER].len = MINI_MAP_SCALE / 15;
	rays = ((float)RES_X * 10) / SPR_NUM[SP_COUNTER].len;
	*add = (float)(MINI_MAP_SCALE / rays) * (QUALITY * 0.6);
	*another_one = fix_sprite(both);
	*flag = 0;
	if (*another_one != 0)
	{
		*flag = 1;
		SPR_NUM[SP_COUNTER].position += (int)(MINI_MAP_SCALE / COUNTER_END)
		- ((MINI_MAP_SCALE * QUALITY)/(SPR_NUM[SP_COUNTER].len));
		ENDING += ((MINI_MAP_SCALE * QUALITY) / (SPR_NUM[SP_COUNTER].len) * COUNTER_END);
		ENDING -= COUNTER_END;
	}
}

void			sprite_changer(t_both *both)
{
	float	another_one;
	float	add;
	int		flag;

	SP_COUNTER = -1;
	while (SPR_NUM[++SP_COUNTER].x_hit)
	{
		ENDING = 0;
		COUNTER_END = (MINI_MAP_SCALE / (float)SPR_NUM[SP_COUNTER].rays);
		flag = 0;
		fix_params(both, &add, &another_one, &flag);

		while ((int)(ENDING += COUNTER_END) <= MINI_MAP_SCALE)
		{
			if (flag == 0)
				another_one = draw_left(both, another_one, add);
			else
				another_one = draw_right(both, another_one, add);
		}
	}
}

void			fix_par(t_both *both, float *bugabuga, float *scale_texture)
{
	LEVEL = RES_Y / (SPR_NUM[SP_COUNTER].len / (2 * COLUMN_HEIGHT));
	DRAW_Y = (int)(HRES_Y - LEVEL / 2);
	END = (int)(HRES_Y + LEVEL / 1.7);
	*bugabuga = 0;
	*scale_texture = (float)((SPRITE.height) / (END - (float)DRAW_Y)) / QUALITY;
}

void			sprite3d(t_both *both, float another_one)
{
	float scale_texture;
	float plus;

	fix_par(both, &plus, &scale_texture);
	while (DRAW_Y++ < END)
	{
		SCALER = RES_X / RAYS;
		DRAW_X = SCALER * SPR_NUM[SP_COUNTER].position;
		while (SCALER-- > 0)
		{
			if (DRAW_Y > 0 && DRAW_X < RES_X &&
			DRAW_X > 0 && DRAW_Y < RES_Y && another_one > 0 &&
			SPRITE.color_mass[(int)another_one][(int)plus] > 0)
				my_pixel_put(&both->img, DRAW_X, DRAW_Y,
				SPRITE.color_mass[(int)another_one][(int)plus]);
			plus += scale_texture;
			DRAW_X++;
		}
	}
}
