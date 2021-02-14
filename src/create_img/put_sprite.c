/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:58:23 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 17:45:25 by hmickey          ###   ########.fr       */
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
		both->get_info[SP_COUNTER].first_angle = 0;
		both->get_info[SP_COUNTER].len_counter = 0;
	}
	SP_COUNTER = 0;
}

int		check_previous_sprites(t_both *both)
{
	int counter;

	counter = 0;
	if (!SPR_NUM[counter].x_hit)
		return (-1);
	while (SPR_NUM[counter].x_hit)
	{
		if (X_STOP == SPR_NUM[counter].x_hit)
			if (Y_STOP == SPR_NUM[counter].y_hit)
				return (counter);
		counter++;
	}
	return (-1);
}

void	find_sprite(t_both *both, float angle)
{
	int counter;

	if ((counter = check_previous_sprites(both)) != -1)
		if (angle != SPR_NUM[counter].angle)
		{
			SPR_NUM[counter].rays++;
			SPR_NUM[counter].angle = angle;
			LEN_COUNTER++;
		}
}

void	check_sprite(t_both *both, float angle)
{
	if (check_previous_sprites(both) == -1)
	{
		both->get_info[SP_COUNTER].x_hit = X_STOP;
		both->get_info[SP_COUNTER].y_hit = Y_STOP;
		both->get_info[SP_COUNTER].len = 0;
		SPR_NUM[SP_COUNTER].len =
		sqrt(pow(PX - (SPR_NUM[SP_COUNTER].x_hit * MINI_MAP_SCALE), 2) +
		(pow(PY - (SPR_NUM[SP_COUNTER].y_hit * MINI_MAP_SCALE), 2))) / 10;
		both->get_info[SP_COUNTER].first_angle = angle;
		both->get_info[SP_COUNTER].angle = angle;
		both->get_info[SP_COUNTER].position = NUM;
		both->get_info[SP_COUNTER].rays = 1;
		SPR_NUM[SP_COUNTER].len_counter = 0;
		SP_COUNTER++;
	}
	find_sprite(both, angle);
}
