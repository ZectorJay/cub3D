/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:56:15 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/11 19:40:52 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*a;
	unsigned const char	*b;
	size_t				i;
	int					diff;

	diff = 0;
	i = 0;
	a = s1;
	b = s2;
	while (i < n)
	{
		if (a[i] != b[i])
		{
			diff += (a[i] - b[i]);
			break ;
		}
		i++;
	}
	return (diff);
}
