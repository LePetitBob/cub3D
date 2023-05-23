/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:21:40 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/23 05:58:27 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_dir(t_math_pos *data)
{
	if (data->dir_y < -0.5 )
		return (1);
	if (data->dir_y > 0.5)
		return (2);
	if (data->dir_x > 0.5)
		return (3);
	if (data->dir_x < -0.5)
		return (4);
	return (0);
}

void	close_door(t_mlx *disp, int dir)
{
	if (dir == 1)
	{
		if (disp->map[(int)(disp->data->pos_y - 1)]\
		[(int)(disp->data->pos_x)] == 'O')
		{
			disp->map[(int)(disp->data->pos_y - 1)]\
			[(int)(disp->data->pos_x)] = 'F';
		return ;
		}
	}
	if (dir == 2)
	{
		if (disp->map[(int)(disp->data->pos_y + 1)]\
		[(int)(disp->data->pos_x)] == 'O')
		{
			disp->map[(int)(disp->data->pos_y + 1)]\
			[(int)(disp->data->pos_x)] = 'F';
		return ;
		}
	}
	if (dir == 3)
	{
		if (disp->map[(int)(disp->data->pos_y)]\
		[(int)(disp->data->pos_x + 1)] == 'O')
		{
			disp->map[(int)(disp->data->pos_y)]\
			[(int)(disp->data->pos_x + 1)] = 'F';
		return ;
		}
	}
	if (dir == 4)
	{
		if (disp->map[(int)(disp->data->pos_y)]\
		[(int)(disp->data->pos_x) - 1] == 'O')
		{
			disp->map[(int)(disp->data->pos_y)]\
			[(int)(disp->data->pos_x) - 1] = 'F';
		return ;
		}
	}
}

void	open_door(t_mlx *disp)
{
	int	dir;

	dir = check_dir(disp->data);
	if (dir == 1)
	{
		if (disp->map[(int)(disp->data->pos_y - 1)]\
		[(int)(disp->data->pos_x)] == 'F')
		{
			disp->map[(int)(disp->data->pos_y - 1)]\
			[(int)(disp->data->pos_x)] = 'O';
		return ;
		}
	}
	if (dir == 2)
	{
		if (disp->map[(int)(disp->data->pos_y + 1)]\
		[(int)(disp->data->pos_x)] == 'F')
		{
			disp->map[(int)(disp->data->pos_y + 1)]\
			[(int)(disp->data->pos_x)] = 'O';
		return ;
		}
	}
	if (dir == 3)
	{
		if (disp->map[(int)(disp->data->pos_y)]\
		[(int)(disp->data->pos_x + 1)] == 'F')
		{
			disp->map[(int)(disp->data->pos_y)]\
			[(int)(disp->data->pos_x + 1)] = 'O';
		return ;
		}
	}
	if (dir == 4)
	{
		if (disp->map[(int)(disp->data->pos_y)]\
		[(int)(disp->data->pos_x) - 1] == 'F')
		{
			disp->map[(int)(disp->data->pos_y)]\
			[(int)(disp->data->pos_x) - 1] = 'O';
			return ;
		}
	}
	close_door(disp, dir);
}
