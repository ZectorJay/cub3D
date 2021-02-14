/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:23:56 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 17:35:26 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	swap_sprites(t_both *both, int end, int i)
{
	t_sprite_info tmp;

	tmp.x_hit = SPR_NUM[i].x_hit;
	tmp.y_hit = SPR_NUM[i].y_hit;
	tmp.len = SPR_NUM[i].len;
	tmp.first_angle = SPR_NUM[i].first_angle;
	tmp.angle = SPR_NUM[i].angle;
	tmp.position = SPR_NUM[i].position;
	tmp.rays = SPR_NUM[i].rays;
	SPR_NUM[i].x_hit = both->get_info[end].x_hit;
	SPR_NUM[i].y_hit = SPR_NUM[end].y_hit;
	SPR_NUM[i].len = SPR_NUM[end].len;
	SPR_NUM[i].first_angle = SPR_NUM[end].first_angle;
	SPR_NUM[i].angle = SPR_NUM[end].angle;
	SPR_NUM[i].position = SPR_NUM[end].position;
	SPR_NUM[i].rays = SPR_NUM[end].rays;
	both->get_info[end].x_hit = tmp.x_hit;
	both->get_info[end].y_hit = tmp.y_hit;
	both->get_info[end].len = tmp.len;
	both->get_info[end].first_angle = tmp.first_angle;
	both->get_info[end].angle = tmp.angle;
	both->get_info[end].position = tmp.position;
	both->get_info[end].rays = tmp.rays;
}

void	sort_sprite(t_both *both)
{
	int		i;
	float	max;
	int		end;

	end = -1;
	i = 0;
	max = 0;
	while (SPR_NUM[++end].len)
	{
		SP_COUNTER = end;
		max = SPR_NUM[end].len;
		i = 0;
		while (SPR_NUM[++SP_COUNTER].x_hit)
			if (max < SPR_NUM[SP_COUNTER].len)
			{
				max = SPR_NUM[SP_COUNTER].len;
				i = SP_COUNTER;
			}
		if (i != 0)
			swap_sprites(both, end, i);
	}
}
