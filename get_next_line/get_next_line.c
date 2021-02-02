/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:05:26 by hmickey           #+#    #+#             */
/*   Updated: 2020/12/27 22:08:16 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_endl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	check_eof(int reading, char **str)
{
	if (reading == 0)
	{
		if (str)
		{
			free(*str);
			*str = NULL;
		}
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			reading;
	char		*buff;
	static char	*str;
	char		*tmp;

	reading = -1;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || !line)
		return (-1);
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (check_endl(str) == -1 && reading != 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		buff[reading] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	*line = ft_substr(str, 0, check_endl(str));
	tmp = str;
	str = ft_substr(str, check_endl(str) + 1, ft_strlen(str));
	free(tmp);
	free(buff);
	return (check_eof(reading, &str));
}
