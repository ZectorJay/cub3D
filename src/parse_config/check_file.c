/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:12:14 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/09 22:00:07 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	checker_of_doubles(t_both *both, char letter1, char letter2)
{
	int i;

	i = -1;
	if ((i = search_texture(both, letter1, letter2, i)) == -1)
		error_message("fail config (way to texture or color)", both);
	if ((i = search_texture(both, letter1, letter2, i)) != -1)
		error_message("found second same string", both);	
}

int		check_second_letter(t_both *both, char c, int i)
{
	if (c == '\0')
		return (1);
	if (c == 'R')
		if (TXT[i][1] != ' ')
			error_message("some trash is found in config - RES", both);
	if (c == 'N')
		if (TXT[i][1] != 'O')
			error_message("some trash is found in config - NO", both);
	if (c == 'S')
		if (TXT[i][1] != 'O' && TXT[i][1] != ' ')
			error_message("some trash is found in config - SO", both);
	if (c == 'W')
		if (TXT[i][1] != 'E')
			error_message("some trash is found in config - WE", both);
	if (c == 'E')
		if (TXT[i][1] != 'A')
			error_message("some trash is found in config - EA", both);
	if (c == 'F')
		if (TXT[i][1] != ' ')
			error_message("some trash is found in config - F ", both);
	if (c == 'C')
		if (TXT[i][1] != ' ')
			error_message("some trash is found in config - C ", both);
	return (1);
}

void	look_for_trash(t_both *both)
{
	int	i;

	i = -1;
	while (TXT[++i] && i < MAP_START)
	{
		if ((ft_strchr("RNSWESFC\0", TXT[i][0])))
		{
			check_second_letter(both, *ft_strchr("RNSWESFC\0", TXT[i][0]), i);
		}
		else if (!(ft_strchr("RNSWESFC\0", TXT[i][0])))
		{
			ft_putstr("what is it? - ");
			write(1, &TXT[i][0], 1);
			ft_putstr("(ASCII code - ");
			ft_putnbr_fd(TXT[i][0], 1);
			write(1, ")\n\n", 3);
			ft_putstr("row in file - ");
			ft_putnbr_fd(i, 1);
			error_message("\nI found bad symbol in config", both);
		}
	}
}

void	find_doubles(t_both *both)
{
	write(1, "checking config\n", 16);
	checker_of_doubles(both, 'N', 'O');
	checker_of_doubles(both, 'S', 'O');
	checker_of_doubles(both, 'W', 'E');
	checker_of_doubles(both, 'E', 'A');
	checker_of_doubles(both, 'S', ' ');
	checker_of_doubles(both, 'F', ' ');
	checker_of_doubles(both, 'C', ' ');
	look_for_trash(both);
}

