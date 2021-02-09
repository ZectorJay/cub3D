/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:14:24 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 23:15:05 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_dir(t_both *both, int j, int i)
{
	char dir;

	dir = *ft_strchr("SWEN", KARTA[j][i]);
	if (ft_strchr("SWEN", dir) && PROT != 0)
			error_message("Second player? WTF?", both);
	if (dir == 'S')
		PROT = 3 * M_PI_2;
	else if (dir == 'W')
		PROT = M_PI;
	else if (dir == 'E')
		PROT = 2 * M_PI;
	else if (dir == 'N')
		PROT = M_PI_2;
	PX = i * MINI_MAP_SCALE;
	PY = j * MINI_MAP_SCALE;
	KARTA[j][i] = '0';
}

void	fail_minimap(t_both *both, int j, int i)
{
	ft_putstr("Why is there - ");
	write(1, &KARTA[j][i], 1);
	ft_putstr("(ASCII code - ");
	ft_putnbr_fd(KARTA[j][i], 1);
	write(1, ")?\n", 3);
	error_message("I found some wrong things at map", both);
}

void	get_minimap(t_both *both)
{
	int i;
	int j;

	j = 0;
	i =  -1;
	while (KARTA[j][++i])
	{
		if (ft_strchr("SWEN", KARTA[j][i]))
			check_dir(both, j, i);
		else if (KARTA[j][i] == ' ')
			KARTA[j][i] = '1';
		else if (!(ft_strchr("102", KARTA[j][i])))
			fail_minimap(both, j, i);
		if (!KARTA[j][i + 1])
		{
			j++;
			i = -1;
		}
		if (!KARTA[j])
			break ;
	}
	map_validator(both);
}

int		find_map(t_both *both)
{
	int j;

	MAP_START = -1;
	while (TXT[++MAP_START])
	{
		j = -1;
		if (ft_strchr("1 ", TXT[MAP_START][0]))
			while (TXT[MAP_START][++j])
			{
				printf("found 1 or space at - %d row\n", MAP_START);
				if (TXT[MAP_START][j] == '1')
					return (MAP_START);
			}
	}
	error_message("there is no map!!", both);
	return (0);
}
