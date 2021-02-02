/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:04 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 04:21:05 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	w_move(t_both *both)
{
	OLD1 = px;
	OLD2 = py;	
	px -= cos(prot) * (SPEED/10);
	py -= sin(prot) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
		px = OLD1;
		py = OLD2;
	}
}

/*
**			АКТУАЛЬНО ДЛЯ: СЕВЕРА И ЗАПАДА
** xstop				(int)(px + PLAYER_SCALE/5)/MINI_MAP_SCALE
** ystop				(int)(py + PLAYER_SCALE/5)/MINI_MAP_SCALE
**			АКТУАЛЬНО ДЛЯ: ЮГА И ВОСТОКА:
** xstop				(int)(px - PLAYER_SCALE/5)/MINI_MAP_SCALE
** ystop				(int)(py - PLAYER_SCALE/5)/MINI_MAP_SCALE
**
**
**
**
*/

void	s_move(t_both *both)
{
	OLD1 = px;
	OLD2 = py;
	px += cos(prot) * (SPEED/10);
	py += sin(prot) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
	 	px = OLD1;
		py = OLD2;
	}
}

void	a_move(t_both *both)
{
	OLD1 = px;
	OLD2 = py;
	py += cos(prot) * (SPEED/10);
	px -= sin(prot) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
	 	px = OLD1;
		py = OLD2;
	}	
}

void	d_move(t_both *both)
{
	OLD1 = px;
	OLD2 = py;
	py -= cos(prot) * (SPEED/10);
	px += sin(prot) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
	 	px = OLD1;
		py = OLD2;
	}
}