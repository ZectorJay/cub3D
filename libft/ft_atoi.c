/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:50:45 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/14 16:48:27 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_space(const char *str, int i)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

static long int		check_num(const char *str, int i)
{
	long int a;

	a = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		a = a + (str[i] - 48);
		i++;
		if (str[i] >= 48 && str[i] <= 57)
			a = a * 10;
	}
	return (a);
}

int					ft_atoi(const char *str)
{
	int			i;
	int			m;
	long int	k;

	k = 0;
	m = 1;
	i = 0;
	while (str[i] != '\0')
	{
		i = check_space(str, i);
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				m = -1;
			i++;
		}
		if (m == 1 && check_num(str, i) < 0)
			return (-1);
		if (m == -1 && check_num(str, i) < 0)
			return (0);
		return (k = (m * check_num(str, i)));
	}
	return (k);
}
