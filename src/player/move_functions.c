/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:04 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/13 12:23:16 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
