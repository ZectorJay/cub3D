/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:57:22 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/07 16:47:39 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		get_x_res(char *res, t_both *both)
{
	int i;

	i = 0;
	while (ft_isspace(res[++i]))
		;
	if ((RES_X = ft_atoi(res + i)) == 0)
		error_message("bad resolution", both);
	i -= 1;
	while (ft_isdigit(res[++i]))
		if (!ft_isdigit(res[i]))
			error_message("bad resolution", both);
	i -= 1;
	while (ft_isspace(res[++i]))
		if (!ft_isspace(res[i]) && !ft_isdigit(res[i]))
			error_message("something before Resolution_Y", both);
	while (res[i])
	{
		if (!ft_isspace(res[i]) && !ft_isdigit(res[i]))
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

	j = 0;
	while (TXT[j])
	{
		if (TXT[j][0] == 'R')
			break ;
		j++;
	}
	if (TXT[j][0] != 'R')
		error_message("No Resolution", both);
	parse_resolution(TXT[j], both);
	printf("RES_Y = %d\n", RES_Y);
	if (RES_Y >= 1440)
		mlx_get_screen_size(CONNECT, &SCREENSHOT_X, &RES_Y);
	printf("RES_Y = %d\n", RES_Y);
	printf("RES_X = %d\n", RES_X);
	if (RES_X >= 2560)
		mlx_get_screen_size(CONNECT, &RES_X, &SCREENSHOT_Y);
	printf("RES_X = %d\n", RES_X);
	if (both->schetchik.save_flag && both->mlx.res_x >= 2550)
		both->mlx.res_x = 2450;
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
	PRESS_W = 0;
	PRESS_A = 0;
	PRESS_S = 0;
	PRESS_D = 0;
	SPEED = SPEED_NORM;
	OLD1 = 0;
	OLD2 = 0;
	HIDE_MAP = 0;
	both->schetchik.save_flag = 0;
	both->save_from_crash = 1;
	get_map(both);
	get_resolution(both);
	recieve_map(both);
	SCALER = RES_X / RAYS;
}
