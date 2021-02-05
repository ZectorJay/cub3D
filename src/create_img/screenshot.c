/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:05:07 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/05 16:43:22 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	convert_bmp(unsigned char *a, int i)
{
	a[0] = (unsigned char)(i);
	a[1] = (unsigned char)(i >> 8);
	a[2] = (unsigned char)(i >> 16);
	a[3] = (unsigned char)(i >> 24);
}

int		header(t_both *both, int fd)
{
	int				filesize;
	// unsigned char	*img;
	int				add_bytes;
	unsigned char	header[54];

	add_bytes = (4 - ((int)RES_X * 3) % 4) % 4;
	// img = (unsigned char *)malloc(3 * RES_X * RES_Y);
	filesize = 54 + 3 * RES_X * RES_Y;
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	convert_bmp(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	convert_bmp(header + 18, RES_X);
	convert_bmp(header + 22, RES_Y);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

void	write_in_bmp(t_both *both, int fd)
{
	int				add_bytes;
	unsigned char	additional[3];
	int				color;
	char			*dst;

	DRAW_Y = RES_Y - 1;
	add_bytes = (4 - ((int)RES_X * 3) % 4) % 4;
	ft_bzero(additional, 3);
	while (--DRAW_Y > 0)
	{
		DRAW_X = -1;
		while (++DRAW_X < RES_X)
		{
			dst = (both->img.addr + ((int)DRAW_Y * both->img.line_length +
			(int)DRAW_X * (both->img.bits_per_pixel / 8)));
			color = *(unsigned int*)dst;
			if (write(fd, &color, 3) < 0)
				error_message("fail writing screenshot", both);
			if (add_bytes > 0 && write(fd, &color, add_bytes) < 0)
				error_message("fail writing screenshot", both);
		}
	}
}

void	make_screenshot(t_both *both)
{
	int				fd;

	if ((fd = open("screenshot.bmp", O_WRONLY |
	O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		error_message("fail to create .bmp", both);
	header(both, fd);
	write_in_bmp(both, fd);
	close(fd);
	error_message("Screenshot was made, enjoy", both);
}