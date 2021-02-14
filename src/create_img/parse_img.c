/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:05:04 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 14:55:25 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		search_texture(t_both *both, char letter, char letter2, int i)
{
	while (++i < MAP_START && TXT[i])
	{
		if (TXT[i][0] == letter && TXT[i][1] == letter2)
			if ((TXT[i][2]) == ' ' || letter2 == ' ')
				return (i);
	}
	return (-1);
}

void	skip_spaces(t_both *both, int i, t_sprite *name)
{
	int		j;
	int		fd;
	char	*file_name;

	j = 2;
	file_name = ft_strtrim(TXT[i] + j, WHITE_SPACE);
	if ((fd = open(file_name, O_RDONLY) < 0))
	{
		free(file_name);
		error_message("there is no such file for texture!", both);
	}
	name->path = file_name;
	free(file_name);
}

void	get_color(t_sprite *data)
{
	float	x;
	int		y;
	char	*dst;
	int		counter;
	float	scale;

	scale = (float)data->width / (float)MINI_MAP_SCALE;
	x = 0;
	counter = 0;
	while ((int)x < data->width)
	{
		y = -1;
		while (++y < data->height)
		{
			dst = (data->addr + ((int)y * data->line_length +
			(int)x * (data->bits_per_pixel / 8)));
			data->color_mass[counter][y] = *(unsigned int*)dst;
		}
		counter++;
		x += scale;
	}
	data->color_mass[counter][0] = '\0';
}
