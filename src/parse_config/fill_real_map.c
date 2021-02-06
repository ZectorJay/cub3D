/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_real_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:44:00 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/06 16:23:39 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// DO I EVEN NEED THIS SH!T?

void	get_mini_map(t_both *both)
{
	// int x = 0;
	// int y = 0;
	// int i;
	// int j;
	// char dir;

	// j = 0;
	// i =  -1;
	// while (KARTA[j][++i])
	// {
	// 	if (KARTA[j][i] == '1')
	// 	{
	// 		// paint_square(x, y, &both->minimap, 0x00FF0000);
	// 		x += MINI_MAP_SCALE;
	// 	}
	// 	else if (ft_strchr("SWEN", KARTA[j][i]))
	// 	{
	// 		if (ft_strchr("SWEN", dir))
	// 			error_message("Second player? WTF?", both);
	// 		dir = *ft_strchr("SWEN", KARTA[j][i]);
	// 		// paint_square(x,y, &both->minimap, 0x888888);
	// 		x += MINI_MAP_SCALE;
	// 		KARTA[j][i] = '0';
	// 		PX = x;
	// 		PY = y;
	// 	}
	// 	else if (KARTA[j][i] == '2')
	// 	{
	// 		// paint_square(x,y, &both->minimap, 0x228800);
	// 		x += MINI_MAP_SCALE;
	// 	}
	// 	else if (ft_isspace(KARTA[j][i]))
	// 	{
	// 		KARTA[j][i] = '1';
	// 		// paint_square(x, y, &both->minimap, 0xFF000000);
	// 		x += MINI_MAP_SCALE;
	// 	}
	// 	else if (KARTA[j][i] == '0')
	// 	{
	// 		// paint_square(x,y, &both->minimap, 0x888888);
	// 		x += MINI_MAP_SCALE;
	// 	}
	// 	else if (!KARTA[j][i])
	// 		KARTA[j][i] = '1';
	// 	else
	// 		error_message("Wrong symbols at map", both);
	// 	if (!KARTA[j][i + 1])
	// 	{
	// 		j++;
	// 		i = -1;
	// 		y += MINI_MAP_SCALE;
	// 		x = 0;
	// 	}
	// 	if (!KARTA[j])
	// 	break;
	// }
}