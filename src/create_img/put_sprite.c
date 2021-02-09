/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:58:23 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 17:21:45 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	clear_sprites(t_both *both)
{
	SP_COUNTER = -1;
	while (++SP_COUNTER < 350)
	{
		both->get_info[SP_COUNTER].x_hit = 0;
		both->get_info[SP_COUNTER].y_hit = 0;
		both->get_info[SP_COUNTER].len = 0;
		both->get_info[SP_COUNTER].angle = 0;	
		both->get_info[SP_COUNTER].rays = 0;	
		both->get_info[SP_COUNTER].position = 0;
		both->get_info[SP_COUNTER].f_x_hit = 0;
		both->get_info[SP_COUNTER].f_y_hit = 0;
		both->get_info[SP_COUNTER].first_angle = 0;
		both->get_info[SP_COUNTER].av_len = NULL;
		both->get_info[SP_COUNTER].len_counter = 0;
		// free(&both->get_info[SP_COUNTER]);
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
		if (X_STOP == SPR_NUM[counter].x_hit)
			if (Y_STOP == SPR_NUM[counter].y_hit)
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
		both->get_info[SP_COUNTER].x_hit = X_STOP;
		both->get_info[SP_COUNTER].f_x_hit = (float)(OLD1/MINI_MAP_SCALE);
		both->get_info[SP_COUNTER].y_hit = Y_STOP;
		both->get_info[SP_COUNTER].f_y_hit = (float)(OLD2/MINI_MAP_SCALE);
		both->get_info[SP_COUNTER].len = 0;
		SPR_NUM[SP_COUNTER].len = sqrt
		(pow(PX - (SPR_NUM[SP_COUNTER].x_hit * MINI_MAP_SCALE), 2) +
		(pow(PY - (SPR_NUM[SP_COUNTER].y_hit * MINI_MAP_SCALE), 2))) / 10;
		SPR_NUM[SP_COUNTER].av_len = malloc(sizeof(float) * RAYS);
		both->get_info[SP_COUNTER].first_angle = angle;
		both->get_info[SP_COUNTER].angle = angle;
		both->get_info[SP_COUNTER].position = NUM;
		both->get_info[SP_COUNTER].rays = 1;
		SPR_NUM[SP_COUNTER].len_counter = 0;
		// SPR_NUM[SP_COUNTER].start_pos = //find_start_pos(both, &SPR_NUM[SP_COUNTER]);
		// printf("start pos = %d, visible start pos = %d\n",
		// SPR_NUM[SP_COUNTER].start_pos, SPR_NUM[SP_COUNTER].position);
		SP_COUNTER++;
	}
	find_sprite(both, angle, len);
}