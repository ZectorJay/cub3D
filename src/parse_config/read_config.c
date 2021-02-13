/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:57:22 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/13 17:10:52 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		get_x_res(char *res, t_both *both)
{
	int i;

	i = 0;
	while (res[++i] == ' ')
		;
	if ((RES_X = ft_atoi(res + i)) <= 0)
		error_message("bad resolution", both);
	i -= 1;
	while (ft_isdigit(res[++i]))
		if (!ft_isdigit(res[i]))
			error_message("bad resolution", both);
	i -= 1;
	while (res[++i] == ' ')
		if (res[i] != ' ' && !ft_isdigit(res[i]))
			error_message("something before Resolution_Y", both);
	while (res[i])
	{
		if (res[i] != ' ' && !ft_isdigit(res[i]))
			error_message("letters in resolution", both);
		if (ft_isdigit(res[i]))
			break ;
		i++;
	}
	return (i);
}

void	parse_resolution(char *res, t_both *both)
{
	int i;

	i = get_x_res(res, both);
	if ((RES_Y = ft_atoi(res + i)) == 0)
		error_message("bad Resolution Y", both);
	while (ft_isdigit(res[i]))
	{
		if (!ft_isdigit(res[i]))
			error_message("bad resolution", both);
		i++;
	}
	while (res[i])
	{
		if (!ft_isspace(res[i]) && res[i] != '\0' && res[i] != '\n')
			error_message("some garbage after resolution", both);
		i++;
	}
}

void	get_resolution(t_both *both)
{
	int j;

	if ((j = search_texture(both, 'R', ' ', -1)) < 0)
		error_message("RESOLUTION NOT FOUND", both);
	parse_resolution(TXT[j], both);
	mlx_get_screen_size(CONNECT, &SCREENSHOT_X, &SCREENSHOT_Y);
	if (RES_X > SCREENSHOT_X)
		RES_X = SCREENSHOT_X;
	if (RES_Y > SCREENSHOT_Y)
		RES_Y = SCREENSHOT_Y;
	if (RES_X % 2 != 1)
		RES_X -= 1;
	if (RES_Y % 2 != 1)
		RES_Y -= 1;
	both->mlx.half_res_y = both->mlx.res_y / 2;
	both->mlx.rays = RES_X / QUALITY;
}

void	get_map(t_both *both)
{
	char	*line;
	int		reading;
	char	**temp;
	int		j;

	reading = 1;
	NUM = 1;
	while (reading)
	{
		j = 0;
		reading = get_next_line(both->map.fd, &line);
		temp = TXT;
		if (!(TXT = malloc((++NUM) * sizeof(char *))))
			error_message("fail memory alloc", both);
		if (temp)
			while (temp[j])
			{
				TXT[j] = temp[j];
				j++;
			}
		free(temp);
		TXT[j++] = line;
		TXT[j] = 0;
	}
}

void	parse_map(t_both *both)
{
	int i;

	PRESS_W = 0;
	PRESS_A = 0;
	PRESS_S = 0;
	PRESS_D = 0;
	SPEED = SPEED_NORM;
	OLD1 = 0;
	OLD2 = 0;
	PROT = 0;
	HIDE_MAP = 0;
	both->schetchik.save_flag = 0;
	both->save_from_crash = 1;
	get_map(both);
	get_resolution(both);
	i = find_map(both);
	KARTA = &TXT[i];
	get_floor_sky_colors(both);
	SCALER = RES_X / RAYS;
}
