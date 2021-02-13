/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:27:22 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/13 15:30:18 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

int		mix_colors(int red, int green, int blue)
{
	int color;

	color = 0;
	if (blue)
		color = blue;
	if (green)
		color += green << 8;
	if (red)
		color += red << 16;
	return (color);
}

int		get_num(t_both *both, int i, int *color)
{
	if (!ft_isdigit(COLOR_STRING[i]))
		error_message("where is number for color?", both);
	if (COLOR_STRING[i] && ft_isdigit(COLOR_STRING[i]))
		*color = ft_atoi(COLOR_STRING + i);
	else
		error_message("there is wrong symbol in color", both);
	while (ft_isdigit(COLOR_STRING[i]))
		i++;
	return (i);
}

void	parse_color(t_both *both, int *color)
{
	int	red;
	int	green;
	int	blue;
	int i;
	
	i = 0;
	i = get_num(both, i, &red);
	if (COLOR_STRING[i] == ',')
		i++;
	else
		error_message("wrong separate symbol", both);
	i = get_num(both, i, &green);
	if (COLOR_STRING[i] == ',')
		i++;
	else
		error_message("wrong separate symbol", both);
	i = get_num(both, i, &blue);
	if (COLOR_STRING[i])
		check_leftovers(both, i);
	if (red > 255 || green > 255 || blue > 255
	|| red < 0 || green < 0 || blue < 0)
		error_message("wrong number in color", both);
	*color = mix_colors(red, green, blue);
}

void	find_color(t_both *both, int i, int *color)
{
	int j;

	j = 1;
	while((TXT[i][j]) == ' ')
		j++;
	if (!(COLOR_STRING = ft_strtrim(TXT[i] + j, " ")))
		error_message("fail allocate memory for color", both);
	parse_color(both,color);
	free(COLOR_STRING);
}

void	get_floor_sky_colors(t_both *both)
{
	int	i;

	if ((i = search_texture(both, 'F', ' ', -1)) < 0)
		error_message("Color for FLOOR not found", both);
	find_color(both, i, &both->schetchik.floor_color);
	if ((i = search_texture(both, 'C', ' ', -1)) < 0)
		error_message("Color for SKY not found", both);
	find_color(both, i, &both->schetchik.sky_color);
}