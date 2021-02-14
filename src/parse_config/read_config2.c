/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:51:33 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 14:29:25 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	find_texture(t_both *both)
{
	get_north(both);
	get_east(both);
	get_south(both);
	get_west(both);
	get_sprite(both);
	find_doubles(both);
}

int		check_file_name(char *file)
{
	int len;
	int k;

	len = ft_strlen(file);
	if (len <= 4)
		return (0);
	k = len - 4;
	if (ft_strnstr(file + k, ".cub", 4))
		return (1);
	return (0);
}

void	fixx_params(t_both *both)
{
	PRESS_W = 0;
	PRESS_A = 0;
	PRESS_S = 0;
	PRESS_D = 0;
	SPEED = SPEED_NORM;
	OLD1 = 0;
	OLD2 = 0;
	PROT = 0;
	HIDE_MAP = 0;
	SCALER = RES_X / RAYS;
}

void	check_leftovers(t_both *both, int i)
{
	if (COLOR_STRING[i] != ' ' || COLOR_STRING[i] != '\0')
		error_message("something come after colors", both);
	if (COLOR_STRING[i])
		while (COLOR_STRING[i] == ' ' || COLOR_STRING[i] == '\0')
		{
			COLOR_STRING[i]++;
			if (COLOR_STRING[i] == '\0')
				break ;
			else if (COLOR_STRING[i] != ' ')
				error_message("something is going after all 3 colors", both);
		}
}
