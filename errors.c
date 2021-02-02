/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:08 by hmickey           #+#    #+#             */
/*   Updated: 2021/01/19 19:16:18 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(char *message, t_both *both)
{
	write (1, message, ft_strlen(message));
	write(1, "\n", 1);
	close(both->map.fd);
	exit(0);
}