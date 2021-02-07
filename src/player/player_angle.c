/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:10:23 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/07 10:04:09 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void			check_row(t_both *both, t_sprite *data, int x)
{
	if (x > MINI_MAP_SCALE)
		x %= MINI_MAP_SCALE;
	data->color_row = data->color_mass[x];
}

void			check_wall(t_both *both, float x, float y)
{
	int xx;
	int yy;

	xx = (int)x / MINI_MAP_SCALE;
	yy = (int)y / MINI_MAP_SCALE;
	if (xx < X_STOP && yy == Y_STOP)
	{
		check_row(both, &both->west, y);
		both->flag_wall = 1;
	}
	else if (xx == X_STOP && yy > Y_STOP)
	{
		check_row(both, &both->north, x);
		both->flag_wall = 2;
	}
	else if (xx > X_STOP && yy == Y_STOP)
	{
		check_row(both, &both->east, y);
		both->flag_wall = 3;
	}
	else if (yy < Y_STOP && xx == X_STOP)
	{
		check_row(both, &both->south, x);
		both->flag_wall = 4;
	}
}

static void		fix_params(t_both *both, int *number, int flag,
				float *len)
{
	if (number)
		*(int*)number = (int)(-1 * (RAYS / 2));
	if (flag)
	{
		END = (int)(RAYS / 2) + 1;
		NUM = 0;
		SP_COUNTER = 0;
	}
	OLD1 = (PX + PLAYER_SCALE);
	OLD2 = (PY + PLAYER_SCALE);
	*(float*)len = 0;
	C_COS = cos(PROT - (FIX_ANGLE * END));
	C_SIN = sin(PROT - (FIX_ANGLE * END));
}

void			sprite_works(t_both *both)
{
	make_avarage_len(both);
	sort_sprite(both);
	sprite_changer(both);
}

void			player_angle(t_both *both)
{
	float	len;
	int		number;

	fix_params(both, &number, 1, &len);
	clear_sprites(both);
	while (KARTA[Y_STOP][X_STOP] != '1' && (len += 0.1) > 0)
	{
		OLD1 -= C_COS;
		OLD2 -= C_SIN;
		if (KARTA[Y_STOP][X_STOP] == '1')
		{
			check_wall(both, OLD1 + C_COS, OLD2 + C_SIN);
			if (END > number + 1)
				END--;
			else
				break ;
			try3d(both, len * both->cos_table[NUM]);
			fix_params(both, 0, 0, &len);
			NUM++;
		}
		if (KARTA[Y_STOP][X_STOP] == '2')
			check_sprite(both, len, PROT - (FIX_ANGLE * END));
	}
}
