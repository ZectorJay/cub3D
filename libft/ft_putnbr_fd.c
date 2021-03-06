/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:54:41 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/10 22:34:19 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long a;

	a = n;
	if (a < 0)
	{
		write(fd, "-", 1);
		a *= -1;
	}
	if (a >= 10)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putchar_fd(a % 10 + 48, fd);
	}
	else
		ft_putchar_fd(a % 10 + 48, fd);
}
