/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:12:31 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/10 13:05:27 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		trim_left(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i != ft_strlen(set))
	{
		if (s1[j] == set[i])
		{
			i = 0;
			j++;
		}
		else
			i++;
	}
	return (j);
}

static int		trim_right(char const *s1, char const *set)
{
	size_t i;
	size_t k;

	i = 0;
	k = ft_strlen(s1) - 1;
	while (i < ft_strlen(set))
	{
		if (s1[k] == set[i])
		{
			i = 0;
			k--;
		}
		else
			i++;
	}
	return (k);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	k;

	if (!s1)
		return (NULL);
	str = NULL;
	i = 0;
	j = trim_left(s1, set);
	if (j >= ft_strlen(s1))
	{
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	k = trim_right(s1, set);
	if (!(str = ft_substr(s1, j, (k - j + 1))))
		return (NULL);
	str[k - j + 1] = '\0';
	return (str);
}
