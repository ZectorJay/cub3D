/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:57:22 by hmickey           #+#    #+#             */
/*   Updated: 2021/01/30 07:38:08 by hmickey          ###   ########.fr       */
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
	if (RES_Y >= 1440)
		RES_Y = 1439;
	if (RES_X >= 2560)
		RES_X = 2559;
	both->mlx.half_res_y = both->mlx.res_y/2;
	both->mlx.rays = RES_X/QUALITY;
}

void	get_map(t_both *both)
{
	char	*line;
	int		i;
	int		reading;
	char	**temp;
	int		j;

	reading = 1;
	i = 1;
	while (reading)
	{
		j = 0;
		reading = get_next_line(both->map.fd, &line);
		temp = TXT;
		if(!(TXT = malloc((i + 1) * sizeof(char *))))
			error_message("POSHEL NAHUY", both);
		if (temp)
		{
			while (temp[j])
			{
				TXT[j] = temp[j];
				j++;
			}
		}
		free(temp);
		TXT[j++] = line;
		TXT[j] = 0;
		i++;
	}
}

void	parse_map(t_both *both)
{
	press_w = 0;
	press_a = 0;
	press_s = 0;
	press_d = 0;
	SPEED = SPEED_NORM;
	OLD1 = 0;
	OLD2 = 0;
	HIDE_MAP = 0;
	both->save_from_crash = 1;
	get_map(both);
	get_resolution(both);
	recieve_map(both);
	SCALER = RES_X / RAYS;
}