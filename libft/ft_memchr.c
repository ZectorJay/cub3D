/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:33:44 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/11 19:40:08 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *str, int a, size_t len)
{
	size_t i;

	i = -1;
	while (++i < len)
		if (((char*)str)[i] == a)
			return ((char*)str + i);
	return (NULL);
}
