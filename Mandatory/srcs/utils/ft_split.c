/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:48:03 by vduriez           #+#    #+#             */
/*   Updated: 2023/02/18 13:56:05 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strchar(char c, char s)
{
	if (c == s)
		return (1);
	return (-1);
}

int	ft_size_w(const char *str, int i, char c)
{
	int	j;

	j = 0;
	while (str[i] && ft_strchar(str[i], c))
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (ft_strchar(str[i], c) != -1)
			i++;
		else
		{
			count++;
			while (ft_strchar(str[i], c) == -1 && str[i] != 0)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i[3];

	if (!str)
		return (NULL);
	i[2] = 0;
	i[0] = 0;
	tab = malloc(sizeof(char *) * (ft_count_word(str, c) + 1));
	if (!tab)
		return (0);
	while (i[0] < ft_count_word(str, c) && str[0] != 0)
	{
		i[1] = 0;
		while (ft_strchar(str[i[2]], c) != -1 && str[i[2]] != 0)
			i[2]++;
		tab[i[0]] = malloc(sizeof(char) * (ft_size_w(str, i[2], c) + 1));
		if (!tab[i[0]])
			return (0);
		while (ft_strchar(str[i[2]], c) == -1 && str[i[2]] != 0)
			tab[i[0]][i[1]++] = str[i[2]++];
		tab[i[0]][i[1]] = '\0';
		i[0]++;
	}
	tab[i[0]] = 0;
	return (tab);
}
