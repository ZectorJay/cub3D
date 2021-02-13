/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:05:04 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/13 16:19:45 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		search_texture(t_both *both, char letter, char letter2, int i)
{
	while (++i < MAP_START && TXT[i])
	{
		if (TXT[i][0] == letter && TXT[i][1] == letter2)
			if((TXT[i][2]) == ' ' || letter2 == ' ')
				return (i);
	}
	return (-1);
}

void	skip_spaces(t_both *both, int i, t_sprite *name)
{
	int j;
	int fd;
	char *file_name;

	j = 2;
	file_name = ft_strtrim(TXT[i] + j, WHITE_SPACE);
	if((fd = open(file_name, O_RDONLY) < 0))
	{
		free(file_name);
		error_message("there is no such file for texture!!!11!1!!!!!", both);
	}
	name->path = file_name;
	free(file_name);
}