/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:52:53 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 09:40:10 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_color(t_both *both, t_sprite *data)
{
	float	x;
	int	y;
	int	color;
	char *dst;
	float res;
	int counter;

	res = data->width/100;
	x = 0;
	counter = 0;
	y = -1;
	while ((int)x < data->width)
	{
		y = -1;
		while (++y < data->height)
		{
			dst = (data->addr + ((int)y * data->line_length + (int)x * (data->bits_per_pixel / 8)));
			color = *(unsigned int*)dst;
			data->color_mass[counter][y] = color;
		}
		counter++;
		x += res;
	}
}

void	get_north(t_both *both)
{
	int i;
	int j;

	i = search_texture(both, 'N', 'O');
	skip_spaces(both, i, &both->north);
	both->north.img = mlx_xpm_file_to_image(CONNECT, both->north.path, &both->north.width, &both->north.height);
	both->north.addr = mlx_get_data_addr(both->north.img,
	&both->north.bits_per_pixel, &both->north.line_length, &both->north.endian);
	get_color(both, &both->north);
}

void	get_south(t_both *both)
{
	int i;
	int j;

	i = search_texture(both, 'S', 'O');
	skip_spaces(both, i, &both->south);
	both->south.img = mlx_xpm_file_to_image(CONNECT, both->south.path, &both->south.width, &both->south.height);
	both->south.addr = mlx_get_data_addr(both->south.img,
	&both->south.bits_per_pixel, &both->south.line_length, &both->south.endian);
	get_color(both, &both->south);
}

void	get_east(t_both *both)
{
	int i;
	int j;

	i = search_texture(both, 'E', 'A');
	skip_spaces(both, i, &both->east);
	both->east.img = mlx_xpm_file_to_image(CONNECT, both->east.path, &both->east.width, &both->east.height);
	both->east.addr = mlx_get_data_addr(both->east.img,
	&both->east.bits_per_pixel, &both->east.line_length, &both->east.endian);
	get_color(both, &both->east);
}

void	get_west(t_both *both)
{
	int i;
	int j;

	i = search_texture(both, 'W', 'E');
	skip_spaces(both, i, &both->west);
	both->west.img = mlx_xpm_file_to_image(CONNECT, both->west.path, &both->west.width, &both->west.height);
	both->west.addr = mlx_get_data_addr(both->west.img,
	&both->west.bits_per_pixel, &both->west.line_length, &both->west.endian);
	get_color(both, &both->west);
}