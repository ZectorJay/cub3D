/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:16:35 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 10:11:04 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotate_player(t_both *both)
{
	if (PRESS_ROT == -1)
		PROT -= (0.1 * ROTATION_SPEED/10);
	if (PRESS_ROT == 1)
		PROT += (0.1 * ROTATION_SPEED/10);
	if (fabs(PROT) >= 2 * M_PI)
		PROT = 0;
}

int		check_key(int keycode, t_both *both)
{
	if (keycode == 53)
		error_message("GAME OVER", both);
	if (keycode == 257)
		SPEED = DOUBLE_SPEED;
	if (keycode == 0)
		PRESS_A = 1;
	if (keycode == 1 || keycode == 125)
		PRESS_S = 1;
	if (keycode == 2)
		PRESS_D = 1;
	if (keycode == 13 || keycode == 126)
		PRESS_W = 1;
	if (keycode == 123)
		PRESS_ROT = -1;
	if (keycode == 124)
		PRESS_ROT = 1;
	return (0);
}

int		key_release(int keycode, t_both *both)
{
	if (keycode == 46)
	{
		if (HIDE_MAP == -1)
			HIDE_MAP = 1;
		else
			HIDE_MAP = -1;
	}
	if (keycode == 257)
		SPEED = SPEED_NORM;
	if (keycode == 123)
		PRESS_ROT = 0;
	if (keycode == 124)
		PRESS_ROT = 0;
	if (keycode == 0)
		PRESS_A = 0;
	if (keycode == 1 || keycode == 125)
		PRESS_S = 0;
	if (keycode == 2)
		PRESS_D = 0;
	if (keycode == 13 || keycode == 126)
		PRESS_W = 0;
	return (0);	
}