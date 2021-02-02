/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:10:23 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 07:32:23 by hmickey          ###   ########.fr       */
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
	if (xx < x_stop && yy == y_stop)
	{
		check_row(both, &both->west, y);
		both->flag_wall = 1;
	}
	else if (xx == x_stop && yy > y_stop)
	{
		check_row(both, &both->north, x);
		both->flag_wall = 2;
	}
	else if (xx > x_stop && yy == y_stop)
	{
		check_row(both, &both->east, y);
		both->flag_wall = 3;
	}
	else if (yy < y_stop && xx == x_stop)
	{
		check_row(both, &both->south, x);
		both->flag_wall = 4;
	}
}

void			check_sprite_row(t_both *both, float x, float y)
{
	int xx;
	int yy;
	int ix;
	int iy;

	ix = (int)x;
	iy = (int)y;
	xx = (int)x / MINI_MAP_SCALE;
	yy = (int)y / MINI_MAP_SCALE;
	// printf("CHECKING DIFF BETWEEN\n yy[%d] and y_stop[%d]\n", yy, y_stop);
	// printf("xx[%d] and x_stop[%d]\n\n", xx, x_stop);
	// printf("so ix = %d and iy = %d\n", ix % MINI_MAP_SCALE, iy % MINI_MAP_SCALE);
	if (yy == y_stop && xx != x_stop)
		ROW_FLAG = ix % MINI_MAP_SCALE;
	else
		ROW_FLAG = iy % MINI_MAP_SCALE;
	// printf("AND WE GOT - %d ROW\n", ROW_FLAG);
}











static void		fix_params(t_both *both, int *number, int *end, float *len)
{

	if (number)
		*(int*)number = (int)(-1 * (RAYS / 2));
	if (end)
		*(int*)end = (int)(RAYS / 2) + 1;
	OLD1 = (px + PLAYER_SCALE);
	OLD2 = (py + PLAYER_SCALE);
	*(float*)len = 0;
}

void			print_sprite_mass(t_both *both)
{
	int counter;

	counter = -1;
	while(SPR_NUM[++counter].x_hit)
	{
		printf("-------------------COUNTER = %d-------------\n",counter);
		printf("SPRITE START AT %d POSITION\n", SPR_NUM[counter].position);
		printf("SPRITE HAVE %d RAYS\n", SPR_NUM[counter].rays);
		printf("FOUND TEXTURE AT: y[%d]x[%d]\n", both->get_info[counter].x_hit, both->get_info[counter].y_hit);
		printf("ANGLE = %f, LEN = %f\n", both->get_info[counter].angle, both->get_info[counter].len);
		printf("FIRST ANGLE = %f\n", SPR_NUM[counter].first_angle);
	}
}







void			player_angle(t_both *both)
{
	float	len;
	int		number;
	int		end;	
	fix_params(both, &number, &end, &len);
	clear_sprites(both);
	C_COS = cos(prot - (FIX_ANGLE * end));
	C_SIN = sin(prot - (FIX_ANGLE * end));
	NUM = 0;
	SP_COUNTER = 0;
	printf("~~~~~~~~~~~~~~~START~~~~~~~~~~~~~~~~~~~\n");
	while (KARTA[y_stop][x_stop] != '1')
	{
		len += 0.1;
		OLD1 -= C_COS;
		OLD2 -= C_SIN;
		if (KARTA[y_stop][x_stop] == '1')
		{
			check_wall(both, OLD1 + C_COS,
			OLD2 + C_SIN);
			if (end > number)
				end--;
			else
				break ;
			try3d(both, len * both->cos_table[NUM]);
			fix_params(both, 0, 0, &len);
	C_COS = cos(prot - (FIX_ANGLE * end));
	C_SIN = sin(prot - (FIX_ANGLE * end));
			NUM++;
		}
		if (KARTA[y_stop][x_stop] == '2')
			check_sprite(both, len, prot - (FIX_ANGLE * end));
	}
	// sort_sprite(both);
	make_avarage_len(both);
	// print_sprite_mass(both);
	sprite_changer(both);
	printf("~~~~~~~~~~~~~~~DONE-~~~~~~~~~~~~~~~~~~~\n\n\n\n\n");
}
