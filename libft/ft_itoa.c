/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:11:11 by hmickey           #+#    #+#             */
/*   Updated: 2020/11/28 19:58:57 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(int n)
{
	size_t	i;
	long	a;

	a = n;
	if (a < 0)
		a *= -1;
	i = 0;
	while (a)
	{
		i++;
		a /= 10;
	}
	return (i);
}

static char		*int_to_char(int n, char *num)
{
	size_t	i;
	long	a;

	a = n;
	i = 0;
	if (a == 0)
		num[0] = '0';
	if (a < 0)
	{
		a *= -1;
		num[i++] = 45;
	}
	while (a)
	{
		num[i++] = a % 10 + 48;
		a /= 10;
	}
	return (num);
}

char			*ft_itoa(int n)
{
	char	tmp;
	char	*num;
	long	a;
	size_t	i;
	size_t	j;

	j = len(n);
	i = 0;
	a = n;
	if (!(num = malloc(sizeof(char) * (len(n) + 2))))
		return (NULL);
	ft_memset(num, 0, len(n) + 2);
	num = int_to_char(n, num);
	if (a < 0)
		i++;
	j = len(n);
	if (a > 0)
		j -= 1;
	while (i != j && i < j)
	{
		tmp = num[i];
		num[i++] = num[j];
		num[j--] = tmp;
	}
	return (num);
}
