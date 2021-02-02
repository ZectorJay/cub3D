/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:16:59 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/28 17:03:20 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	k;
	size_t	s1len;
	size_t	s2len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	count;

	count = start;
	ret = NULL;
	if (!s)
		return (NULL);
	i = -1;
	while (count < len && s[count])
		count++;
	if (!(ret = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (++i < len && s[start])
		ret[i] = s[start++];
	if (start > ft_strlen(s))
		ret[0] = '\0';
	ret[i] = '\0';
	return (ret);
}
