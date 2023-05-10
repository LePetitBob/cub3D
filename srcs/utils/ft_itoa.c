/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:58:05 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/10 12:26:10 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>

int	ft_size(int n)
{
	int		size;
	int		signe;

	signe = 0;
	if (n < 0)
		signe = 1;
	if (n < 0)
		n = -n;
	size = 1;
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (signe + size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		signe;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	signe = 0;
	if (n < 0)
		signe = 1;
	size = ft_size(n);
	if (n < 0)
		n = -n;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (--size >= signe)
	{
		res[size] = (n % 10) + 48;
		n /= 10;
	}
	if (signe)
		res[0] = '-';
	return (res);
}

char	*ft_strndup(const char *s1, int size)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (s1[i] && i < size)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = s1[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}
