/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:36:08 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/02 04:51:14 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_texture(t_both *both)
{
	get_north(both);
	get_east(both);
	get_south(both);
	get_west(both);
	get_sprite(both);
}

int		check_file_name(char *file)
{
	int len;
	int k;

	len = ft_strlen(file);
	if (len <= 4)
		return(0);
	k = len - 4;
	if (ft_strnstr(file + k, ".cub", 4))
		return(1);
	return(0);
}

int		paint(t_both *both)
{
	if(press_a || press_d || press_s || press_w || press_rot)
	{
		mlx_clear_window(connect, win);
		paint_move(both);
		player_angle(both);
		mlx_put_image_to_window(connect, win, both->img.img, 0, 0);
		mlx_string_put(connect, win, RES_X - 80, RES_Y - 40, 0xFF3300, "HMICKEY");
	}
	return (1);
}

void	first_draw(t_both *both)
{
		paint_move(both);
		player_angle(both);
		mlx_put_image_to_window(connect, win, both->img.img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_both	both;
	if (argc == 2 || argc == 3)
	{
		if (!(both.map.fd = open(argv[1], O_RDONLY)))
			error_message("Fail to open config file", &both);
		if (!check_file_name(argv[1]))
			error_message("Fail extenstion. Its not .cub file!", &both);
		parse_map(&both);
	}
	else
		error_message("Dude, where is map?", &both);
	both.mlx.con = mlx_init();
	both.mlx.window = mlx_new_window(both.mlx.con, both.mlx.res_x, both.mlx.res_y, "Cub3D");
	create_minimap(&both);
	find_texture(&both);
	first_draw(&both);
	mlx_hook(both.mlx.window, 2, 1L << 0, &check_key, &both);
	mlx_key_hook(both.mlx.window, &key_release, &both);
	mlx_loop_hook(both.mlx.con, &paint, &both);
	mlx_loop(both.mlx.con);
	return(0);
}


// НЕ ЗАБЫТЬ!!!!!!!!!!!!!!
/*
** Не забыть про все костыли и prinf'ы
** гусь
*/