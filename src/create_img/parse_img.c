/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:05:04 by hmickey           #+#    #+#             */
/*   Updated: 2021/01/28 02:02:02 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		search_texture(t_both *both, char letter, char letter2)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	j = -1;
	while (TXT[++i])
	{
		j = 0;
		while (ft_isspace(TXT[i][j]) || TXT[i][j] == letter)
		{
			if (TXT[i][j] == letter && TXT[i][j + 1] == letter2)
				if(ft_isspace(TXT[i][j + 2]) || letter2 == ' ')
				{
					flag = 1;
					break;
				}
			j++;
		}
			if(flag == 1)
				break ;
	}
	if (flag == 0)
		error_message("fail texture", both);
	return (i);
}

void	skip_spaces(t_both *both, int i, t_sprite *name)
{
	int j;
	int fd;
	char *file_name;

	j = 0;
	while(ft_isspace(TXT[i][j]))
		j++;
	j += 2;
	file_name = ft_strtrim(TXT[i] + j, white_space);
	if((fd = open(file_name, O_RDONLY)) == -1)
	{
		free(file_name);
		error_message("there is no such file for texture!!!11!1!!!!!", both);
	}
	name->path = file_name;
	free(file_name);
}