/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:14:24 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 10:21:49 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_dir(char dir, t_both *both)
{
	if (dir == 'S')
		PROT = 3 * M_PI_2;
	else if (dir == 'W')
		PROT = M_PI;
	else if (dir == 'E')
		PROT = 2 * M_PI;
	else if (dir == 'N')
		PROT = M_PI_2;
}

void	get_minimap(t_both *both)
{
	int x = 0;
	int y = 0;
	int i;
	int j;
	char dir;

	j = 0;
	i =  -1;
	while (KARTA[j][++i])
	{
		if (KARTA[j][i] == '1')
			x += MINI_MAP_SCALE;
		else if (ft_strchr("SWEN", KARTA[j][i]))
		{
			if (ft_strchr("SWEN", dir))
				error_message("Second player? WTF?", both);
			dir = *ft_strchr("SWEN", KARTA[j][i]);
			check_dir(dir, both);
			x += MINI_MAP_SCALE;
			KARTA[j][i] = '0';
			PX = x;
			PY = y;
		}
		else if (KARTA[j][i] == '2')
			x += MINI_MAP_SCALE;
		else if (ft_isspace(KARTA[j][i]))
			x += MINI_MAP_SCALE;
		else if (KARTA[j][i] == '0')
			x += MINI_MAP_SCALE;
		else
			error_message("I found some wrong things at map", both);
		if (!KARTA[j][i + 1])
		{
			j++;
			i = -1;
			y += MINI_MAP_SCALE;
			x = 0;
		}
		if (!KARTA[j])
		break;
	}
}

int		get_line(int i, t_both *both, char **karta_line)
{
	int j;

	if (!TXT[i])
		return (0);
	j = 0;
	*karta_line = TXT[i];
	return(1);
}

void	recieve_map(t_both *both)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (TXT[++i])
		if (TXT[i][0] == 'C')
			break ;
	i++;
	while (!TXT[i][j])
		i++;
	while (TXT[i][j])
	{
		if (ft_strchr("1", TXT[i][j]))
		{
			flag = 1;
			break ;
		}
		j++;
	}
	if (flag != 1)
		error_message("there is no map!!", both);
	KARTA = &TXT[i];
}