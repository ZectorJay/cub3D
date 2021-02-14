/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:17:59 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 12:43:52 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	check_up_bot_left(t_both *both, int i, int j)
{
	if (j > ft_strlen(KARTA[i - 1]) + 1)
		error_message("map is not closed.", both);
	if (KARTA[i - 1][j - 1])
		if (!ft_strchr(VALID_SYMBOLS, KARTA[i - 1][j - 1]))
			error_message("map is not closed", both);
	if (j > ft_strlen(KARTA[i + 1]) + 1)
		error_message("map is not closed.", both);
	if (KARTA[i + 1][j - 1])
		if (!ft_strchr(VALID_SYMBOLS, KARTA[i + 1][j - 1]))
			error_message("map is not closed", both);
}

void	check_up_bot_middle(t_both *both, int i, int j)
{
	if (j > ft_strlen(KARTA[i - 1]))
		error_message("map is not closed.", both);
	if (KARTA[i - 1][j])
		if (!ft_strchr(VALID_SYMBOLS, KARTA[i - 1][j]))
			error_message("map is not closed", both);
	if (j >= ft_strlen(KARTA[i + 1]))
		error_message("map is not closed.", both);
	if (KARTA[i + 1][j])
		if (!ft_strchr(VALID_SYMBOLS, KARTA[i + 1][j]))
			error_message("map is not closed", both);
}

void check_up_bot_right(t_both *both, int i, int j)
{
	if (j >= ft_strlen(KARTA[i - 1]) - 1)
		error_message("map is not closed.", both);
	if (KARTA[i - 1][j + 1])
		if (!ft_strchr(VALID_SYMBOLS, KARTA[i - 1][j + 1]))
			error_message("map is not closed", both);
	if (j >= ft_strlen(KARTA[i + 1]) - 1)
		error_message("map is not closed.", both);
	if (KARTA[i + 1][j + 1])
		if (!ft_strchr(VALID_SYMBOLS, KARTA[i + 1][j + 1]))
			error_message("map is not closed", both);
}

void	check_left_right(t_both *both, int i, int j)
{
	if (!ft_strchr(VALID_SYMBOLS, KARTA[i][j - 1]))
		error_message("map is not closed", both);
	if (KARTA[i][j + 1] != '\0')
	{
		if (!ft_strchr(VALID_SYMBOLS, KARTA[i][j + 1]))
			error_message("map is not closed", both);
	}
	else
		error_message("map is not closed", both);

}

void	check_around(t_both *both, int i, int j)
{
	check_up_bot_left(both, i, j);
	check_up_bot_middle(both, i, j);
	check_up_bot_right(both, i, j);
	check_left_right(both, i, j);
}