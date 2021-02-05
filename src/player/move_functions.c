/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:04 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 09:43:07 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	w_move(t_both *both)
{
	OLD1 = PX;
	OLD2 = PY;	
	PX -= cos(PROT) * (SPEED/10);
	PY -= sin(PROT) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
		PX = OLD1;
		PY = OLD2;
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
	OLD1 = PX;
	OLD2 = PY;
	PX += cos(PROT) * (SPEED/10);
	PY += sin(PROT) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
	 	PX = OLD1;
		PY = OLD2;
	}
}

void	a_move(t_both *both)
{
	OLD1 = PX;
	OLD2 = PY;
	PY += cos(PROT) * (SPEED/10);
	PX -= sin(PROT) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
	 	PX = OLD1;
		PY = OLD2;
	}	
}

void	d_move(t_both *both)
{
	OLD1 = PX;
	OLD2 = PY;
	PY -= cos(PROT) * (SPEED/10);
	PX += sin(PROT) * (SPEED/10);
	if (KARTA[ystop][xstop] != '0')
	{
	 	PX = OLD1;
		PY = OLD2;
	}
}