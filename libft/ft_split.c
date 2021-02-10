/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:41:08 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/14 17:21:10 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		str_count(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
	return (count);
}

static size_t	str_len(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char		*get_str(char const **s, char c)
{
	size_t	i;
	char	*str;
	size_t	strlen;

	i = 0;
	while (**s == c)
		(*s)++;
	strlen = str_len(*s, c);
	if (!(str = malloc(sizeof(char) * (strlen + 1))))
		return (NULL);
	while (i < strlen)
	{
		str[i] = s[0][i];
		i++;
	}
	str[i] = '\0';
	while (**s != c && **s)
		(*s)++;
	return (str);
}

static void		free_str(char **s, size_t i)
{
	size_t j;

	j = 0;
	while (j < i)
	{
		s[j] = NULL;
		free(s[j]);
		j++;
	}
	free(s);
	s = NULL;
}

char			**ft_split(char const *s, char c)
{
	size_t	str_num;
	size_t	i;
	char	**full;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str_num = str_count(s, c);
	if (!(full = (char**)malloc(sizeof(char*) * (str_num + 1))))
		return (NULL);
	while (i < str_num)
	{
		str = get_str(&s, c);
		if (!str)
		{
			free_str(full, i);
			return (NULL);
		}
		full[i] = str;
		i++;
	}
	full[i] = NULL;
	return (full);
}
