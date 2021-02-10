/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:13:38 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/10 11:41:49 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// void	check_around(t_both *both, int i, int j)
// {

// }

void	check_first_last_row(t_both *both, int i)
{
	int	j;

	j = -1;
	while (KARTA[i][++j])
	{
		if (KARTA[i][j] != '1')
			error_message("top/bot of the map is not closed", both);
	}
}

void	map_validator(t_both *both)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	(void)both;
	// check_first_last_row(both, i + 1);
	// while (KARTA[++i])
	// {
	// 	j = -1;
	// 	while (KARTA[i][++j])
	// 	{
	// 		if (KARTA[i][j] == '0' || KARTA[i][j] == '2')
	// 			check_around(both, i, j);
	// 	}
	// }
}