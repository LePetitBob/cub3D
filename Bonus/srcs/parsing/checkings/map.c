/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:31:29 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 18:09:35 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>

int	char_checker(t_mlx *disp)
{
	int	y;
	int	x;

	disp->player = 0;
	y = -1;
	while (++y < disp->height_map)
	{
		x = -1;
		while (++x < (disp->length_map))
		{
			if (!is_in("FO 1230NSWE", (disp->map)[y][x]))
				return (print_error(MSG_CHAR), 0);
			if (!borders(disp, x, y))
				return (0);
			if (x == 0 && (disp->map)[y][x] != ' ' && (disp->map)[y][x] != '1')
				return (print_error(MSG_WALL_1), 0);
			if (is_in("NSWE", (disp->map)[y][x]))
				if (++(disp->player) > 1)
					return (print_error(MSG_SPAWN_PB), 0);
		}
	}
	if (disp->player != 1)
		return (print_error(MSG_SPAWN_PB), 0);
	return (1);
}

int	is_char_next(char *str)
{
	while (*str == ' ')
		str++;
	if (!(*str))
		return (0);
	return (1);
}

int	fill_map(t_mlx *disp, char *str, int y)
{
	char	prev_char;
	int		i;

	prev_char = '1';
	i = 0;
	while (*str)
	{
		if (*str == ' ')
			if (!is_char_next(str))
				break ;
		if (((prev_char != ' ' && prev_char != '1') && *str == ' ')
			|| (prev_char == ' ' && (*str != ' ' && *str != '1')))
			return (print_error(MSG_WALL_1), 0);
		(disp->map)[y][i] = *str;
		prev_char = *str;
		str++;
		i++;
	}
	(disp->map)[y][i] = ' ';
	while (++i < disp->length_map)
		(disp->map)[y][i] = ' ';
	disp->map[y][i] = 0;
	return (1);
}

int	set_up_map(t_mlx *disp)
{
	int		i;
	char	*str;

	i = 0;
	str = gnl_corrector(get_next_line(disp->fd));
	if (!str)
		return (print_error(MSG_BADMAP), 0);
	while (str)
	{
		if (!fill_map(disp, str, i))
			return (0);
		free(str);
		str = gnl_corrector(get_next_line(disp->fd));
		i++;
	}
	if (close(disp->fd) == -1)
		return (print_error(MSG_OPENMAP), 0);
	if (!char_checker(disp))
		return (0);
	return (1);
}

int	initialize_map(t_mlx *disp)
{
	int	i;

	i = 0;
	disp->map = malloc(sizeof(char *) * (disp->height_map + 1));
	if (!(disp->map))
		return (print_error(MSG_MALLOC_FAIL), 0);
	disp->map[disp->height_map] = NULL;
	while (i < disp->height_map)
	{
		(disp->map)[i] = ft_calloc_so(disp->length_map, sizeof(char));
		if (!((disp->map)[i]))
			return (print_error(MSG_MALLOC_FAIL), 0);
		i++;
	}
	disp->fd = open(disp->mapname, O_RDONLY);
	if (disp->fd == -1)
		return (print_error(MSG_OPEN_FAIL_MAP), 0);
	if (!set_up_map(disp))
		return (0);
	return (1);
}
