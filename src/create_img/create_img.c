/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:22:18 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 17:32:51 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	fill_cos(t_both *both)
{
	int number;
	int end;
	int ugol;
	int counter;

	counter = 0;
	number = -1 * (RAYS / 2);
	end = RAYS / 2 + 1;
	ugol = PROT - (FIX_ANGLE * end);
	while (--end > number)
	{
		both->cos_table[counter] =
		cos(PROT - (FIX_ANGLE * end) - PROT);
		counter++;
	}
}

void	create_minimap(t_both *both)
{
	get_minimap(both);
	create_img(both, &both->img, RES_X, RES_Y);
	both->cos_table = malloc(sizeof(float*) * both->mlx.res_x / QUALITY);
	fill_cos(both);
}
