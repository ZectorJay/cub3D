/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:05:07 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/06 10:43:44 by hmickey          ###   ########.fr       */
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

void	header(t_both *both, int fd)
{
	int				filesize;
	unsigned char	*img;
	int				add_bytes;
	unsigned char	bmp_header[54];
	
	if (RES_X % 4 != 0)
		RES_X -= (RES_X % 4);
	add_bytes = (4 - ((int)RES_X * 3) % 4) % 4;
	img = (unsigned char *)malloc(3 * RES_X * RES_Y);
	filesize = 54 + 3 * RES_X * RES_Y;
	ft_bzero(img, filesize);
	img[0] = (unsigned char)('B');
	img[1] = (unsigned char)('M');
	convert_bmp(img + 2, filesize);
	img[10] = (unsigned char)54;
	img[14] = (unsigned char)40;
	convert_bmp(img + 18, RES_X);
	convert_bmp(img + 22, RES_Y);
	img[26] = (unsigned char)1;
	img[28] = (unsigned char)24;
	write(fd, img, 54);
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
	while (DRAW_Y > 0)
	{
		DRAW_X = 0;
		while (DRAW_X < RES_X)
		{
			dst = (both->img.addr + ((int)DRAW_Y * both->img.line_length +
			(int)DRAW_X * (both->img.bits_per_pixel / 8)));
			color = *(unsigned int*)dst;
			if (write(fd, &color, 3) < 0)
				error_message("fail writing screenshot", both);
			if (add_bytes > 0 && write(fd, &color, add_bytes) < 0)
				error_message("fail writing screenshot", both);
				DRAW_X++;
		}
		DRAW_Y--;
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