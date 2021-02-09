/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:23:56 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 23:42:25 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	swap_sprites(t_both *both, int end, int i)
{
		t_sprite_info tmp;

		tmp.x_hit = SPR_NUM[i].x_hit;
		tmp.f_x_hit = SPR_NUM[i].f_x_hit;
		tmp.y_hit = SPR_NUM[i].y_hit;
		tmp.f_y_hit = SPR_NUM[i].f_y_hit;
		tmp.len = SPR_NUM[i].len;
		tmp.first_angle = SPR_NUM[i].first_angle;
		tmp.angle = SPR_NUM[i].angle;
		tmp.position = SPR_NUM[i].position;
		tmp.rays = SPR_NUM[i].rays;

		SPR_NUM[i].x_hit =	both->get_info[end].x_hit; 
		SPR_NUM[i].f_x_hit = SPR_NUM[end].f_x_hit;
		SPR_NUM[i].y_hit = SPR_NUM[end].y_hit;
		SPR_NUM[i].f_y_hit = SPR_NUM[end].f_y_hit; 
		SPR_NUM[i].len = SPR_NUM[end].len;
		SPR_NUM[i].first_angle = SPR_NUM[end].first_angle;
		SPR_NUM[i].angle = SPR_NUM[end].angle;
		SPR_NUM[i].position = SPR_NUM[end].position;
		SPR_NUM[i].rays = SPR_NUM[end].rays;

		both->get_info[end].x_hit = tmp.x_hit;;
		both->get_info[end].f_x_hit = tmp.f_x_hit;
		both->get_info[end].y_hit = tmp.y_hit;
		both->get_info[end].f_y_hit = tmp.f_y_hit;
		both->get_info[end].len = tmp.len;
		both->get_info[end].first_angle = tmp.first_angle;
		both->get_info[end].angle = tmp.angle;
		both->get_info[end].position = tmp.position;
		both->get_info[end].rays = tmp.rays;
}

void	sort_sprite(t_both *both)
{
	int i;
	float max;
	int end;

	end = -1;
	i = 0;
	max = 0;
	while (SPR_NUM[++end].len)
	{
		SP_COUNTER = end;
		max = SPR_NUM[end].len;
		i = 0;
		while(SPR_NUM[++SP_COUNTER].x_hit)
			if (max < SPR_NUM[SP_COUNTER].len)
			{
				max = SPR_NUM[SP_COUNTER].len;
				i = SP_COUNTER;
			}
		if (i != 0)
			swap_sprites(both, end, i);
	}
}

static void	fix_params(t_both *both, float *c_cos, float *c_sin,
			int finder, t_sprite_info *sprite)
{
	SPRITE_OLD_X = PX + PLAYER_SCALE;
	SPRITE_OLD_Y = PY + PLAYER_SCALE;
	*c_cos = cos(sprite->first_angle - (FIX_ANGLE * finder));
	*c_sin = sin(sprite->first_angle - (FIX_ANGLE * finder));
}
//GAVNO BESPOLEZNOE
int	find_start_pos(t_both *both, t_sprite_info *sprite)
{
	float c_cos;
	float c_sin;
	int finder;	

int	pidor = 0;


	finder = sprite->position;
	sprite->start_pos = sprite->position;
	fix_params(both, &c_cos, &c_sin, finder, sprite);
	printf("sprite_X - %d, sprite_Y = %d\n", sprite->x_hit, sprite->y_hit);
	while (ft_strchr("102", KARTA[Y_STOP][X_STOP]))
	{
		pidor++;
		SPRITE_OLD_X -= c_cos;
		SPRITE_OLD_Y -= c_sin;
		if(pidor % 300 == 0)
		{
			printf("X - %d, Y = %d\n", SPRITE_OLD_X/MINI_MAP_SCALE, SPRITE_OLD_Y/MINI_MAP_SCALE);
			sleep(1);
		}
		if ((int)(((SPRITE_OLD_X - c_cos)/MINI_MAP_SCALE)) == (int)sprite->x_hit &&
		(int)((SPRITE_OLD_Y - c_sin)/MINI_MAP_SCALE) == (int)sprite->y_hit)
		{
			printf("HUY\n");
			sprite->start_pos--;
			finder++;
			if (finder > (sprite->position + MINI_MAP_SCALE))
				break;
			fix_params(both, &c_cos, &c_sin, finder, sprite);
		}
	}
	return (sprite->start_pos);
}