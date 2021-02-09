/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:27:22 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 19:11:49 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_leftovers(t_both *both, char *color_string)
{
	while (ft_isdigit(*color_string))
		color_string++;
	if (*color_string)
		if (*color_string != ' ' || *color_string != '\0')
			error_message("something come after colors", both);
	if (*color_string)
		while (*color_string == ' ' || *color_string == '\0')
		{
			color_string++;
			if (*color_string != ' ')
				error_message("something is going after all 3 colors", both);
			else if (*color_string == '\0')
				break ;
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

char	*get_num(t_both *both, char *color_string, int *color)
{
	if (ft_isdigit(*color_string))
		*color = ft_atoi(color_string);
	else
		error_message("there is wrong symbol in color", both);
	while (ft_isdigit(*color_string))
		color_string++;
	return (color_string);
}

void	parse_color(t_both *both, char *color_string, int *color)
{
	int	red;
	int	green;
	int	blue;

	color_string = get_num(both, color_string, &red);
	if (*color_string == ',')
		color_string++;
	else
		error_message("wrong separate symbol", both);
	color_string = get_num(both, color_string, &green);
	if (*color_string == ',')
		color_string++;
	else
		error_message("wrong separate symbol", both);
	color_string = get_num(both, color_string, &blue);
	check_leftovers(both, color_string);
	if (red > 255 || green > 255 || blue > 255
	|| red < 0 || green < 0 || blue < 0)
		error_message("wrong number in color", both);
	*color = mix_colors(red, green, blue);
}

void	find_color(t_both *both, int i, int *color)
{
	int j;
	char *color_string;

	j = 0;
	while((TXT[i][j]) == ' ')
		j++;
	j += 2;
	if (!(color_string = ft_strtrim(TXT[i] + j, white_space)))
		error_message("fail allocate memory for color", both);
	parse_color(both, color_string, color);
	free(color_string);
}

void	get_floor_sky_colors(t_both *both)
{
	int	i;

	i = -1;
	i = search_texture(both, 'F', ' ', i);
	find_color(both, i, &both->schetchik.floor_color);
	i = search_texture(both, 'C', ' ', i);
	find_color(both, i, &both->schetchik.sky_color);
}