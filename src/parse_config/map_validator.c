/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:13:38 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/13 18:21:16 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_around(t_both *both, int i, int j)
{
	if (!KARTA[i - 1][j - 1] && !ft_strchr(VALID_SYMBOLS, KARTA[i - 1][j - 1]))
	{
		printf("I dont like - %c\n", KARTA[i - 1][j - 1]);
		error_message("map is not closed", both);
	}
}

int		check_inside(t_both *both, char *row, int j)
{

}


void	check_row(t_both *both, int i)
{
	int j;

	j = -1;
	while (KARTA[i][++j])
	{
		if (KARTA[i][j] == '1')
			j = check_inside(both, KARTA + i, j);		
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
		check_row(both, i);
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
		{
			if (KARTA[i][j] == '0' || KARTA[i][j] == '2')
				check_around(both, i, j);
		}
	}
}