/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:26:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/25 14:16:08 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	in_borders(t_mlx *disp, int x, int y)
{
	if (y != 0 && y != (disp->height_map) - 1)
	{
		if ((disp->map)[y][x] == ' ' && ((disp->map)[y + 1][x] != '1'
			&& (disp->map)[y + 1][x] != ' '))
			return (print_error(MSG_WALL_1), 0);
		if ((disp->map)[y][x] == ' ' && ((disp->map)[y - 1][x] != '1'
			&& (disp->map)[y - 1][x] != ' '))
			return (print_error(MSG_WALL_1), 0);
	}
	else if (y == 0)
	{
		if ((disp->map)[y][x] == ' ' && ((disp->map)[y + 1][x] != '1'
			&& (disp->map)[y + 1][x] != ' '))
			return (print_error(MSG_WALL_1), 0);
	}
	else if (y == (disp->height_map) - 1)
	{
		if ((disp->map)[y][x] == ' ' && ((disp->map)[y - 1][x] != '1'
			&& (disp->map)[y - 1][x] != ' '))
			return (print_error(MSG_WALL_1), 0);
	}
	return (1);
}

int	borders(t_mlx *disp, int x, int y)
{
	if (y == 0 || y == (disp->height_map) - 1)
	{
		if ((disp->map)[y][x] != '1' && (disp->map)[y][x] != ' ')
			return (print_error(MSG_WALL_1), 0);
	}
	if (!in_borders(disp, x, y))
		return (0);
	return (1);
}

int	check_closed(t_mlx *disp, int i, int j)
{
	if (disp->map[i][j] == '0')
	{
		if (i == 0 || j == 0 || i == disp->height_map - 1
			|| j == disp->length_map - 1)
			return (0);
		if (i > 0 && !is_in("01", disp->map[i - 1][j]))
			return (0);
		if (i < disp->height_map - 1 && !is_in("01", disp->map[i + 1][j]))
			return (0);
		if (j > 0 && !is_in("01", disp->map[i][j - 1]))
			return (0);
		if (j < disp->length_map - 1 && !is_in("01", disp->map[i][j + 1]))
			return (0);
	}
	return (1);
}
