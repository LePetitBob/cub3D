/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:28:44 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 01:35:06 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mv_forward(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->pos_y) + \
		(data->dir_y) * MOVESPEED)][(int)(data->pos_x)] == '0')
		data->pos_y += (data->dir_y) * MOVESPEED;
	if ((disp->map)[(int)(data->pos_y)][(int)((data->pos_x) + \
		(data->dir_x) * MOVESPEED)] == '0')
		data->pos_x += (data->dir_x) * MOVESPEED;
}

void	mv_back(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->pos_y) - \
		(data->dir_y) * MOVESPEED)][(int)(data->pos_x)] == '0')
		data->pos_y -= (data->dir_y) * MOVESPEED;
	if ((disp->map)[(int)(data->pos_y)][(int)((data->pos_x) - \
		(data->dir_x) * MOVESPEED)] == '0')
		data->pos_x -= (data->dir_x) * MOVESPEED;
}

void	mv_left(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->pos_y) - \
		(data->dir_x) * MOVESPEED)][(int)(data->pos_x)] == '0')
		data->pos_y -= (data->dir_x) * MOVESPEED;
	if ((disp->map)[(int)(data->pos_y)][(int)((data->pos_x) + \
		(data->dir_y) * MOVESPEED)] == '0')
		data->pos_x += (data->dir_y) * MOVESPEED;
}

void	mv_right(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->pos_y) + \
		(data->dir_x) * MOVESPEED)][(int)(data->pos_x)] == '0')
		data->pos_y += (data->dir_x) * MOVESPEED;
	if ((disp->map)[(int)(data->pos_y)][(int)((data->pos_x) - \
		(data->dir_y) * MOVESPEED)] == '0')
		data->pos_x -= (data->dir_y) * MOVESPEED;
}
