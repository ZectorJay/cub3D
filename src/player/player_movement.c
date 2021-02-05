/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:16:35 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 09:43:07 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotate_player(t_both *both)
{
	if (press_rot == -1)
		PROT -= (0.1 * ROTATION_SPEED/10);
	if (press_rot == 1)
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
		press_a = 1;
	if (keycode == 1 || keycode == 125)
		press_s = 1;
	if (keycode == 2)
		press_d = 1;
	if (keycode == 13 || keycode == 126)
		press_w = 1;
	if (keycode == 123)
		press_rot = -1;
	if (keycode == 124)
		press_rot = 1;
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
		press_rot = 0;
	if (keycode == 124)
		press_rot = 0;
	if (keycode == 0)
		press_a = 0;
	if (keycode == 1 || keycode == 125)
		press_s = 0;
	if (keycode == 2)
		press_d = 0;
	if (keycode == 13 || keycode == 126)
		press_w = 0;
	return (0);	
}