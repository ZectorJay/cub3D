/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:08 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/07 12:21:30 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(char *message, t_both *both)
{
	if (!message)
		message = "Good bye";
	write(1, "ERROR\n", 6);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	if (both->map.fd)
		close(both->map.fd);
	exit(0);
}
