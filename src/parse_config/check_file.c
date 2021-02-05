/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:12:14 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 09:12:25 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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