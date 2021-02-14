/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:13:38 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 14:15:30 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		check_inside(t_both *both, char *row, int j)
{
	int flag;

	flag = 0;
	while (row[++j])
	{
		if (row[j] == '0')
			flag = 1;
		else if (row[j] == '2')
			;
		else if (row[j] == '1')
		{
			flag = 0;
			break ;
		}
		else if (row[j] == ' ' && flag == 0)
			;
		else
			error_message("map is not closed", both);
	}
	if (flag == 1)
		error_message("map is not closed", both);
	return (j - 1);
}

void	check_map_row(t_both *both, int i)
{
	int j;

	j = -1;
	while (KARTA[i][++j])
	{
		if (KARTA[i][j] == '1')
			j = check_inside(both, *(KARTA + i), j);
		else if (!ft_strchr("1 \0", KARTA[i][j]))
			error_message("map is not closed. Didnt find start/end of wall",
			both);
	}
}

void	check_close(t_both *both)
{
	int	j;
	int i;

	j = -1;
	i = -1;
	while (KARTA[++i])
	{
		if (i == 0)
		{
			while (KARTA[i][++j])
				if (!ft_strchr("1 \0", KARTA[i][j]))
					error_message("map is not closed at top", both);
		}
		check_map_row(both, i);
	}
}

void	map_validator(t_both *both)
{
	int	i;
	int j;

	i = 0;
	j = -1;
	check_close(both);
	while (KARTA[++i])
	{
		j = -1;
		while (KARTA[i][++j])
			if (KARTA[i][j] == '0' || KARTA[i][j] == '2')
				check_around(both, i, j);
	}
}
