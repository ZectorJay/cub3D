/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:21:43 by hmickey           #+#    #+#             */
/*   Updated: 2020/12/07 10:26:48 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	if (s[0] == c)
		return ((char*)s);
	while (*s++ != c && *s)
		if (*s == c)
			return ((char*)s);
	return (NULL);
}
