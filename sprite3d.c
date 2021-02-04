/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 06:42:40 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/04 14:02:11 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
**
** Как вариант - собрать лучи, падающие на стены в массив.
** начинать рисовать с середины спрайта
** Или пустить луч от игрока до места, где собираюсь нарисовать спрайт
** если там будет стена, то пропустить (не рисовать) в том месте спрайт
** Угол, под которым пускать луч у меня есть в массиве. (или нет. Лел)
** У меня есть последний угол и сколько лучей было кинуто. Воть. Это может помочь
** От последнего луча (угол которого известен) попробовать кинуть луч вправо.
**
**
**
** Если расстояние до стены будет 100500, а до спрайта было 500, то
** значит мы перестали считать лучи потому, что видим крайнюю правую
** часть спрайта. Начинаем рисовать справа-налево. И НАОБОРОТ
*/

void	check_diff(t_both *both, t_sprite_info sprite)
{
	int y;

	y = RES_Y/3;
	while (y++ < RES_Y * 2/3)
		my_pixel_put(&both->img, sprite.position * (RES_X/RAYS), y, 0xFF0000);
}

float	fix_sprite(t_both *both)
{
	float len;
	OLD1 = px + PLAYER_SCALE;
	OLD2 = py + PLAYER_SCALE;

	len = 0;
	C_COS = cos(SPR_NUM[SP_COUNTER].first_angle - (2 * FIX_ANGLE));
	C_SIN = sin(SPR_NUM[SP_COUNTER].first_angle - (2 * FIX_ANGLE));
	if (SPR_NUM[SP_COUNTER].position < 3)
		return (MINI_MAP_SCALE);
	while (KARTA[y_stop][x_stop] != '1' && KARTA[y_stop][x_stop])
	{
		len += 0.1;
		OLD1 -= C_COS;
		OLD2 -= C_SIN;
		if (KARTA[y_stop][x_stop] == '1')
			if (len < SPR_NUM[SP_COUNTER].len)
				return (both->sprite.width);
			
	}
	return (0);
}



float	draw_left(t_both *both, float another_one, float pizda)
{
	sprite3d(both, another_one);
	SPR_NUM[SP_COUNTER].position++;
		another_one += pizda;
	return(another_one);
}


float	draw_right(t_both *both, float another_one, float pizda)
{
	sprite3d(both, another_one);
	SPR_NUM[SP_COUNTER].position--;
	another_one -= pizda;
	return(another_one);
}

void	fix_params(t_both *both, float *pizda, float *another_one)
{
	float	rays;

	rays = (RES_X * 10 / QUALITY)/SPR_NUM[SP_COUNTER].len;
	*pizda = (float)(MINI_MAP_SCALE / rays);
	*another_one = fix_sprite(both);
	if (SPR_NUM[SP_COUNTER].len < MINI_MAP_SCALE/10)
		SPR_NUM[SP_COUNTER].len = MINI_MAP_SCALE/10;
}


void	sprite_changer(t_both *both)
{
	float	another_one;
	float	pizda;
	float	ending;
	float	counter_end;
	int		flag = 0;

	SP_COUNTER = -1;
	while (SPR_NUM[++SP_COUNTER].x_hit)
	{
		// printf("len = %f\n", SPR_NUM[SP_COUNTER].len);
		ending = 0;
		counter_end = (MINI_MAP_SCALE / (float)SPR_NUM[SP_COUNTER].rays);
		flag = 0;
		fix_params(both, &pizda, &another_one);
		if (another_one != 0)
		{
			flag = 1;
			SPR_NUM[SP_COUNTER].position += (MINI_MAP_SCALE / counter_end);
			ending -= counter_end;
		}
		check_diff(both, SPR_NUM[SP_COUNTER]);
		while((int)(ending += counter_end) <= MINI_MAP_SCALE)
		{
			if (flag == 0)
				another_one = draw_left(both, another_one, pizda);
			else
				another_one = draw_right(both, another_one, pizda);
		}
		check_diff(both, SPR_NUM[SP_COUNTER]);
	}
}

void	sprite3d(t_both *both, float another_one)
{
	int end;
	float scale_texture;
	float bugabuga;
	LEVEL = RES_Y / (SPR_NUM[SP_COUNTER].len / (2 * COLUMN_HEIGHT));
	if ((int)LEVEL >= RES_Y || (int)LEVEL < 0)
		LEVEL = RES_Y;
	DRAW_Y = (int)(HRES_Y - LEVEL/2);
	end = (int)(HRES_Y + LEVEL/2);
	bugabuga = 0;
	float endf = end;
	float yf = DRAW_Y;
	scale_texture = (float)((both->sprite.height)/(endf - yf))/QUALITY;
	while (DRAW_Y++ < end)
	{
		SCALER = RES_X / RAYS;
		DRAW_X = SCALER * SPR_NUM[SP_COUNTER].position;
		while (SCALER--)
		{
			if (DRAW_Y > 0 && DRAW_X < RES_X && DRAW_X > 0 && DRAW_Y < RES_Y &&
			 another_one > 0 && both->sprite.color_mass[(int)another_one][(int)bugabuga] > 0)
				my_pixel_put(&both->img, DRAW_X, DRAW_Y, both->sprite.color_mass[(int)another_one][(int)bugabuga]);
			bugabuga += scale_texture;
			DRAW_X++;
		}
	}
}