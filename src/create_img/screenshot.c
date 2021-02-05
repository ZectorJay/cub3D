/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:05:07 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 14:45:30 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	convert_bmp(unsigned char *a, int i)
{
	a[0] = (unsigned char)i;
	a[1] = (unsigned char)(i >> 8);
	a[2] = (unsigned char)(i >> 16);
	a[3] = (unsigned char)(i >> 24);
}

int		header(t_both *both, int fd)
{
	int				filesize;
	unsigned char	*img;
	int				add_bytes;
	unsigned char	header[54];

	add_bytes = (4 - ((int)SCREENSHOT_X * 3) % 4) % 4;
	img = (unsigned char *)malloc(3 * SCREENSHOT_X * SCREENSHOT_Y);
	filesize = 54 + 3 * SCREENSHOT_X * SCREENSHOT_Y;
	ft_bzero(img, filesize - 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
}

void	make_screenshot(t_both *both)
{
	int				fd;

	if ((fd = open("screenshot.bmp", O_WRONLY |
	O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		error_message("fail to create .bmp", both);
	header(both, fd);
	exit(0);
}