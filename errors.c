/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:08 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/07 16:50:41 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_memory(t_both *both)
{
	int	i;

	i = -1;
	while (TXT[++i])
	{
		free(TXT[i]);
		TXT[i] = NULL;
	}
	free(TXT);
}

void	error_message(char *message, t_both *both)
{
	if (!message)
		message = "Good bye";
	write(1, "ERROR\n", 6);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	if (TXT[0][0])
		free_memory(both);
	if (both->map.fd)
		close(both->map.fd);
	exit(0);
}
