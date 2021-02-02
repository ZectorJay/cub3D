/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 06:42:40 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 13:19:33 by hmickey          ###   ########.fr       */
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

void	sprite_changer(t_both *both)
{
	SP_COUNTER = -1;
	float another_one = 0;

	float	pizda;
	float	rays;
	float	ending;

	rays = (float)SPR_NUM[SP_COUNTER].rays;
	check_diff(both, SPR_NUM[SP_COUNTER + 1]);
	while (SPR_NUM[++SP_COUNTER].x_hit)
	{
		ending = 0;

		rays = (float)SPR_NUM[SP_COUNTER].rays;
			pizda = (float)(MINI_MAP_SCALE / rays);
		another_one = SPR_NUM[SP_COUNTER].row_flag;
		if (another_one >= MINI_MAP_SCALE - 1 || another_one < 0)
			another_one = 0;
		printf("another one: %f, pizda = %f\n", another_one, pizda);
		printf("first angle: %f, last angle = %f\n",
		SPR_NUM[SP_COUNTER].first_angle, SPR_NUM[SP_COUNTER].angle);
		while((int)ending < MINI_MAP_SCALE)
		{
			sprite3d(both, another_one);
			SPR_NUM[SP_COUNTER].position++;
			if (pizda < 1)
				another_one += pizda;
			else
				another_one++;
			if (another_one >= MINI_MAP_SCALE)
				break ;
			ending += pizda;
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
	DRAW_Y = (int)(HRES_Y - LEVEL/6);
	end = (int)(HRES_Y + LEVEL/2);
	bugabuga = 0;
	float endf = end;
	float yf = DRAW_Y;
	scale_texture = (float)((both->sprite.height)/(endf - yf))/QUALITY;
	// printf("gonna draw %d row\n", (int)another_one);
	while (DRAW_Y++ < end)
	{
		SCALER = RES_X / RAYS;
		DRAW_X = SCALER * SPR_NUM[SP_COUNTER].position;
		while (SCALER--)
		{
			if (DRAW_Y > 0 && DRAW_X < RES_X && DRAW_X > 0 &&
			 another_one > 0 && both->sprite.color_mass[(int)another_one][(int)bugabuga] > 0
			 && another_one < MINI_MAP_SCALE && bugabuga < MINI_MAP_SCALE)
				my_pixel_put(&both->img, DRAW_X, DRAW_Y, both->sprite.color_mass[(int)another_one][(int)bugabuga]);
			bugabuga += scale_texture;
			DRAW_X++;
		}
	}
}