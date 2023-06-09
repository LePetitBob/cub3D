/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_map_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:01:10 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/19 17:30:58 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	resize_map(t_mlx *disp)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	while (++i < disp->height_map)
	{
		j = 0;
		s = malloc(sizeof(char) * (disp->length_map + 1));
		if (!s)
			return (print_error(MSG_MALLOC_FAIL), ft_free_parsing(disp));
		while (disp->map[i][j])
		{
			s[j] = disp->map[i][j];
			++j;
		}
		while (j < disp->length_map)
		{
			s[j] = 32;
			++j;
		}
		s[j] = 0;
		free(disp->map[i]);
		disp->map[i] = s;
	}
}

int	is_charset(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	check_closed(t_mlx *disp, int i, int j)
{
	if (disp->map[i][j] == '0')
	{
		if (i == 0 || j == 0 || i == disp->height_map - 1
			|| j == disp->length_map - 1)
			return (0);
		if (i > 0 && !is_charset(disp->map[i - 1][j], "01"))
			return (0);
		if (i < disp->height_map - 1 && !is_charset(disp->map[i + 1][j], "01"))
			return (0);
		if (j > 0 && !is_charset(disp->map[i][j - 1], "01"))
			return (0);
		if (j < disp->length_map - 1 && !is_charset(disp->map[i][j + 1], "01"))
			return (0);
	}
	return (1);
}
