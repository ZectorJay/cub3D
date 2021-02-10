/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:25:10 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/21 01:53:55 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t ok;

	if (needle[0] == '\0')
		return ((char*)haystack);
	ok = 0;
	i = 0;
	while (i < len && haystack[i])
	{
		ok = 0;
		while (needle[ok] && haystack[i + ok] == needle[ok] &&
		haystack[i + ok] && (i + ok) < len)
			ok++;
		if (needle[ok] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
