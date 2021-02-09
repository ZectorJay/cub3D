/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:15:03 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 18:20:36 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	fix_sprite(t_both *both)
{
	float len;

	OLD1 = PX + PLAYER_SCALE;
	OLD2 = PY + PLAYER_SCALE;
	len = 0;
	C_COS = cos(SPR_NUM[SP_COUNTER].first_angle - (1 * FIX_ANGLE));
	C_SIN = sin(SPR_NUM[SP_COUNTER].first_angle - (1 * FIX_ANGLE));
	if (SPR_NUM[SP_COUNTER].position < 1)
		return (MINI_MAP_SCALE);
	while (KARTA[Y_STOP][X_STOP] != '1' && KARTA[Y_STOP][X_STOP])
	{
		len += 0.1;
		OLD1 -= C_COS;
		OLD2 -= C_SIN;
		if (KARTA[Y_STOP][X_STOP] == '1')
			if (len < SPR_NUM[SP_COUNTER].len - 10 && PRESS_ROT != -1)
				return (MINI_MAP_SCALE);
	}
	return (0);
}

float	draw_left(t_both *both, float another_one, float add)
{
	sprite3d(both, another_one);
	SPR_NUM[SP_COUNTER].position++;
	another_one += add;
	return (another_one);
}

float	draw_right(t_both *both, float another_one, float add)
{
	sprite3d(both, another_one);
	SPR_NUM[SP_COUNTER].position--;
	another_one -= add;
	return (another_one);
}

void	skip_steps(t_both *both, float *plus, float scale_texture)
{
	float diff;
	
	if (DRAW_Y <= 0)
	{
		diff = abs(DRAW_Y * QUALITY);
		*plus = fabs((float)diff) * (scale_texture);
		DRAW_Y = 0;
		ROW_FLAG = RES_Y;
	}
}