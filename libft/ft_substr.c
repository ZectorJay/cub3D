/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:13:38 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/19 21:15:31 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	{
		ret[i] = s[start];
		start++;
	}
	if (start > ft_strlen(s))
		ret[0] = '\0';
	ret[i] = '\0';
	return (ret);
}
