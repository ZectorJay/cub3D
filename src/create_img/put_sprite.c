/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:58:23 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 07:26:06 by hmickey          ###   ########.fr       */
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

		both->get_info[end].x_hit = both->get_info[i].x_hit;;
		both->get_info[end].f_x_hit = both->get_info[i].f_x_hit;
		both->get_info[end].y_hit = both->get_info[i].y_hit;
		both->get_info[end].f_y_hit = both->get_info[i].f_y_hit;
		both->get_info[end].len = both->get_info[i].len;
		both->get_info[end].first_angle = both->get_info[i].first_angle;
		both->get_info[end].angle = both->get_info[i].angle;
		both->get_info[end].position = both->get_info[i].position;
		both->get_info[end].rays = both->get_info[i].rays;
}



void	make_avarage_len(t_both *both)
{
	int i;
	int end;

	end = -1;
	while (SPR_NUM[++end].x_hit)
	{
		i = 0;
		if(SPR_NUM[end].av_len[0] > 0)
			SPR_NUM[end].len = SPR_NUM[end].av_len[i];
		i++;
		while (SPR_NUM[end].av_len[i] > 0 &&
		SPR_NUM[end].av_len[i] < SPR_NUM[end].av_len[i - 1] + 10
		&& SPR_NUM[end].av_len[i] > SPR_NUM[end].av_len[i - 1] - 10)
		{
			SPR_NUM[end].len += SPR_NUM[end].av_len[i];
			i++;
		}
		free(SPR_NUM[end].av_len);
		SPR_NUM[end].len /= (float)i;
	}
}

void	sort_sprite(t_both *both)
{
	// SP_COUNTER = -1;
	int i;
	float max;
	int end;

	end = -1;
	i = 0;
	max = 0;

}





void	clear_sprites(t_both *both)
{
	SP_COUNTER = -1;
	while (++SP_COUNTER < 50)
	{
		both->get_info[SP_COUNTER].x_hit = 0;
		both->get_info[SP_COUNTER].y_hit = 0;
		both->get_info[SP_COUNTER].len = 0;
		both->get_info[SP_COUNTER].angle = 0;	
		both->get_info[SP_COUNTER].rays = 0;	
		both->get_info[SP_COUNTER].position = 0;
	}
	SP_COUNTER = 0;
}

int		check_previous_sprites(t_both *both)
{
	int counter;

	counter = 0;
	if(!SPR_NUM[counter].x_hit)
		return(-1);
	while(SPR_NUM[counter].x_hit)
	{
		if (x_stop == SPR_NUM[counter].x_hit)
			if (y_stop == SPR_NUM[counter].y_hit)
				return(counter);
		counter++;
	}
	return(-1);
}

void	find_sprite(t_both *both, float angle, float len)
{
	int counter;

	if ((counter = check_previous_sprites(both)) != -1)
		if (angle != SPR_NUM[counter].angle)
		{
			SPR_NUM[counter].rays++;
			SPR_NUM[counter].angle = angle;
			SPR_NUM[counter].av_len[LEN_COUNTER] = len;
			LEN_COUNTER++;
		}
}

void	check_sprite(t_both *both, float len, float angle)
{
	if(check_previous_sprites(both) == -1)
	{
		both->get_info[SP_COUNTER].x_hit = x_stop;
		both->get_info[SP_COUNTER].f_x_hit = (float)(OLD1/MINI_MAP_SCALE);
		both->get_info[SP_COUNTER].y_hit = y_stop;
		both->get_info[SP_COUNTER].f_y_hit = (float)(OLD2/MINI_MAP_SCALE);
		both->get_info[SP_COUNTER].len = 0;//len;
		check_sprite_row(both, OLD1 + C_COS, OLD2 + C_SIN);
		SPR_NUM[SP_COUNTER].row_flag = ROW_FLAG;
		// printf("ROW - %d\n", ROW_FLAG);
		SPR_NUM[SP_COUNTER].av_len = malloc(sizeof(float) * RAYS);
		both->get_info[SP_COUNTER].first_angle = angle;
		both->get_info[SP_COUNTER].angle = angle;
		both->get_info[SP_COUNTER].position = NUM;
		both->get_info[SP_COUNTER].rays = 1;
		SPR_NUM[SP_COUNTER].len_counter = 0;
		SP_COUNTER++;
	}
	find_sprite(both, angle, len);
}