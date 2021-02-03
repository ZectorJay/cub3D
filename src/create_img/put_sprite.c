/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:58:23 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 09:25:40 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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