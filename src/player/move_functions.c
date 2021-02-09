/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:04 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 18:04:36 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
**			АКТУАЛЬНО ДЛЯ: СЕВЕРА И ЗАПАДА
** xstop				(int)(px + PLAYER_SCALE/5)/MINI_MAP_SCALE
** ystop				(int)(py + PLAYER_SCALE/5)/MINI_MAP_SCALE
**			АКТУАЛЬНО ДЛЯ: ЮГА И ВОСТОКА:
** xstop				(int)(px - PLAYER_SCALE/5)/MINI_MAP_SCALE
** ystop				(int)(py - PLAYER_SCALE/5)/MINI_MAP_SCALE
*/

void	w_move(t_both *both)
{
	OLD1 = PX;
	OLD2 = PY;
	PX -= cos(PROT) * (SPEED / 10);
	PY -= sin(PROT) * (SPEED / 10);
	if (KARTA[YSTOP][XSTOP] == '1')
	{
		PX = OLD1;
		PY = OLD2;
	}
}

void	s_move(t_both *both)
{
	OLD1 = PX;
	OLD2 = PY;
	PX += cos(PROT) * (SPEED / 10);
	PY += sin(PROT) * (SPEED / 10);
	if (KARTA[YSTOP][XSTOP] == '1')
	{
		PX = OLD1;
		PY = OLD2;
	}
}

void	a_move(t_both *both)
{
	OLD1 = PX;
	OLD2 = PY;
	PY += cos(PROT) * (SPEED / 10);
	PX -= sin(PROT) * (SPEED / 10);
	if (KARTA[YSTOP][XSTOP] == '1')
	{
		PX = OLD1;
		PY = OLD2;
	}
}

void	d_move(t_both *both)
{
	OLD1 = PX;
	OLD2 = PY;
	PY -= cos(PROT) * (SPEED / 10);
	PX += sin(PROT) * (SPEED / 10);
	if (KARTA[YSTOP][XSTOP] == '1')
	{
		PX = OLD1;
		PY = OLD2;
	}
}
