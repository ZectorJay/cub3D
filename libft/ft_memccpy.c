/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:00:44 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/25 03:18:29 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	stop;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	stop = (unsigned char)c;
	i = 0;
	while (i < n && source[i] != stop)
	{
		dest[i] = source[i];
		i++;
	}
	if (source[i] == stop)
		dest[i] = source[i];
	if (i < n)
		return (dest + i + 1);
	return (NULL);
}

int main()
{
	char a[] = "123456789";
	ft_memccpy(&a[1], &a[0], 0, 9);
	printf("%s\n", a);
}
