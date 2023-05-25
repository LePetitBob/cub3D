/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:41:38 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/25 17:54:47 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_doors(t_mlx *disp, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (disp->map[y][x] == 'F')
				px_put(disp->data->img, \
					10 * x + i, 10 * y + j, 0xFF0000);
			else
				px_put(disp->data->img, \
					10 * x + i, 10 * y + j, 0x00FF00);
		}
	}
}

void	put_walls(t_mlx *disp, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			px_put(disp->data->img, \
				10 * x + i, 10 * y + j, 0xFFFF00);
		}
	}
}

void	put_player(t_mlx *disp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			px_put(disp->data->img, 10 * (int)disp->data->pos_x + i, \
				10 * (int)disp->data->pos_y + j, 0x0000FF);
	}
}

void	put_minimap(t_mlx *disp)
{
	int	y;
	int	x;

	y = -1;
	while (disp->map[++y])
	{
		x = 0;
		while (disp->map[y][x])
		{
			if (is_in("123", disp->map[y][x]))
				put_walls(disp, x, y);
			if (disp->map[y][x] == 'F' || disp->map[y][x] == 'O')
				put_doors(disp, x, y);
			++x;
		}
	}
	put_player(disp);
}
