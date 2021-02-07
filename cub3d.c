/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:36:08 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/07 16:52:37 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		paint(t_both *both)
{
	if (PRESS_A || PRESS_D || PRESS_S || PRESS_W || PRESS_ROT)
	{
		mlx_clear_window(CONNECT, WIN);
		paint_move(both);
		player_angle(both);
		sprite_works(both);
		mlx_put_image_to_window(CONNECT, WIN, both->img.img, 0, 0);
		mlx_string_put(CONNECT, WIN, RES_X - 80,
		RES_Y - 40, 0xFF3300, "HMICKEY");
	}
	return (1);
}

void	first_draw(t_both *both)
{
	paint_move(both);
	player_angle(both);
	sprite_works(both);
	if (both->schetchik.save_flag == 1)
	{
		write(1, "\n w8 a moment, making screenshot\n", 14);
		make_screenshot(both);
	}
	mlx_put_image_to_window(CONNECT, WIN, both->img.img, 0, 0);
}

void	check_args(t_both *both, char **argv, int argc)
{
	if (!(both->map.fd = open(argv[1], O_RDONLY)))
		if (!(both->map.fd = open(argv[2], O_RDONLY)))
			error_message("Fail to open config file", both);
	if (!check_file_name(argv[1]))
		error_message("Fail extenstion. Or fail arguments order", both);
	parse_map(both);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		both->schetchik.save_flag = 1;
	else if (argc == 3)
		error_message("Wrong screenshot command", both);
}

int		x_cross_close(t_both *both)
{
	error_message("Just kidding\nGood bye", both);
	return (1);
}

int		main(int argc, char **argv)
{
	t_both	both;

	if (argc == 2 || argc == 3)
		check_args(&both, argv, argc);
	else
		error_message("Dude, where is map?", &both);
	if (!(both.mlx.con = mlx_init()))
		error_message("Fail initializing mlx", &both);
	if (!(both.mlx.window = mlx_new_window(both.mlx.con,
	both.mlx.res_x, both.mlx.res_y, "Cub3D")))
		error_message("Fail opening window", &both);
	create_minimap(&both);
	find_texture(&both);
	first_draw(&both);
	mlx_hook(both.mlx.window, 2, 1L << 0, &check_key, &both);
	mlx_key_hook(both.mlx.window, &key_release, &both);
	mlx_hook(both.mlx.window, 17, 1, x_cross_close, &both);
	mlx_loop_hook(both.mlx.con, &paint, &both);
	mlx_loop(both.mlx.con);
	return (0);
}
