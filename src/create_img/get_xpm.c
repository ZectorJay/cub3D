/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:52:53 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 11:23:20 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	get_sprite_color(t_both *both, t_sprite *data)
{
	float	x;
	int		y;
	char 	*dst;
	int 	counter;
	float	scale;
	
	float width = (float)data->width;
	float mini_scale = (float)(MINI_MAP_SCALE);
	scale = width / mini_scale;
	x = 0;
	counter = 0;
	while ((int)x < data->width)
	{
		y = -1;
		while (++y < data->height)
		{
			dst = (data->addr + ((int)y * data->line_length + (int)x * (data->bits_per_pixel / 8)));
			data->color_mass[counter][y] = *(unsigned int*)dst;
		}
		counter++;
		x += scale;
	}
	data->color_mass[counter][0] = '\0';
}

void	get_color(t_both *both, t_sprite *data)
{
	float	x;
	int		y;
	char 	*dst;
	int 	counter;
	float	scale;
	
	float width = (float)data->width;
	float mini_scale = (float)(MINI_MAP_SCALE);
	scale = width / mini_scale;
	x = 0;
	counter = 0;
	while ((int)x < data->width)
	{
		y = -1;
		while (++y < data->height)
		{
			dst = (data->addr + ((int)y * data->line_length + (int)x * (data->bits_per_pixel / 8)));
			data->color_mass[counter][y] = *(unsigned int*)dst;
		}
		counter++;
		x += scale;
	}
	data->color_mass[counter][0] = '\0';
}

void	get_north(t_both *both)
{
	int i;
	int j;

	i = search_texture(both, 'N', 'O');
	skip_spaces(both, i, &both->north);
	both->north.img = mlx_xpm_file_to_image(connect, both->north.path, &both->north.width, &both->north.height);
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
	both->south.img = mlx_xpm_file_to_image(connect, both->south.path, &both->south.width, &both->south.height);
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
	both->east.img = mlx_xpm_file_to_image(connect, both->east.path, &both->east.width, &both->east.height);
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
	both->west.img = mlx_xpm_file_to_image(connect, both->west.path, &both->west.width, &both->west.height);
	both->west.addr = mlx_get_data_addr(both->west.img,
	&both->west.bits_per_pixel, &both->west.line_length, &both->west.endian);
	get_color(both, &both->west);
}

void	get_sprite(t_both *both)
{
	int i;
	int j;

	i = search_texture(both, 'S', ' '); // НЕ ЗАБЫТЬ ЧТО СЧИТЫВАЕТ КРИВО!! ЪУЪУЪУЪУЪУЪУЪ!!!!!!!!!!!!!!!!
	skip_spaces(both, i, &both->sprite);
	both->sprite.img = mlx_xpm_file_to_image(connect, both->sprite.path, &both->sprite.width, &both->sprite.height);
	both->sprite.addr = mlx_get_data_addr(both->sprite.img,
	&both->sprite.bits_per_pixel, &both->sprite.line_length, &both->sprite.endian);
	get_sprite_color(both, &both->sprite);	
}