/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 06:42:40 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 07:37:58 by hmickey          ###   ########.fr       */
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

int		get_color_row(t_both *both)
{
	OLD1 = px + PLAYER_SCALE;
	OLD2 = py + PLAYER_SCALE;

	while(KARTA[y_stop][x_stop] == '2')
	{
		OLD1 -= cos(SPR_NUM[SP_COUNTER].first_angle);
		OLD2 -= sin(SPR_NUM[SP_COUNTER].first_angle);
		if(KARTA[y_stop][x_stop] == '1')
			return (0);
	}
	printf("OLD1 = %f, OLD2 = %f\n", OLD1, OLD2);
	return ((int)((int)OLD1 % MINI_MAP_SCALE));
}


int		check_diff(t_both *both)
{
	return (0);
}

void	sprite_changer(t_both *both)
{
	SP_COUNTER = -1;
	float another_one = 0;

	float pizda;
	float rays;
	rays = (float)SPR_NUM[SP_COUNTER].rays;
	while (SPR_NUM[++SP_COUNTER].x_hit)
	{
		rays = (float)SPR_NUM[SP_COUNTER].rays;
		pizda = (float)(MINI_MAP_SCALE / rays);
		// another_one = 0;
		another_one = SPR_NUM[SP_COUNTER].row_flag;
		printf("another_one = %f\n", another_one);
		if ((int)another_one > MINI_MAP_SCALE/2)
		{
			printf("WTF?!\n");
			while (another_one > 0)
			{
				sprite3d(both, another_one);
				SPR_NUM[SP_COUNTER].position++;
				another_one -= pizda;
			}
		}
		else
			while(another_one < MINI_MAP_SCALE)
			{
				sprite3d(both, another_one);
				SPR_NUM[SP_COUNTER].position++;
				another_one += pizda;
			}
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
	DRAW_Y = (int)(HRES_Y - LEVEL/4);
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
			if (DRAW_Y > 0 && DRAW_X < RES_X && DRAW_X > 0 &&
			 another_one > 0 && both->sprite.color_mass[(int)another_one][(int)bugabuga] > 0
			 && another_one < MINI_MAP_SCALE)
				my_pixel_put(&both->img, DRAW_X, DRAW_Y, both->sprite.color_mass[(int)another_one][(int)bugabuga]);
			bugabuga += scale_texture;
			DRAW_X++;
		}
	}
}