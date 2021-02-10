/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:12:30 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/14 21:27:00 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	k;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	k = 0;
	if (!(a = malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	while (s1[i])
		a[k++] = s1[i++];
	i = 0;
	while (s2[i])
		a[k++] = s2[i++];
	a[k] = '\0';
	return (a);
}
