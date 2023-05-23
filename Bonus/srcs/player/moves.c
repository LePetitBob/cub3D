/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:28:44 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 16:51:46 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mv_forward(t_mlx *disp, t_math_pos *data)
{
	if (is_in("0O", (disp->map)[(int)((data->pos_y) + \
		(data->dir_y) * (MOVESPEED * disp->shift))][(int)(data->pos_x)]))
		data->pos_y += (data->dir_y) * (MOVESPEED * disp->shift);
	if (is_in("0O", (disp->map)[(int)(data->pos_y)][(int)((data->pos_x) + \
		(data->dir_x) * (MOVESPEED * disp->shift))]))
		data->pos_x += (data->dir_x) * (MOVESPEED * disp->shift);
}

void	mv_back(t_mlx *disp, t_math_pos *data)
{
	if (is_in("0O", (disp->map)[(int)((data->pos_y) - \
		(data->dir_y) * (MOVESPEED * disp->shift))][(int)(data->pos_x)]))
		data->pos_y -= (data->dir_y) * (MOVESPEED * disp->shift);
	if (is_in("0O", (disp->map)[(int)(data->pos_y)][(int)((data->pos_x) - \
		(data->dir_x) * (MOVESPEED * disp->shift))]))
		data->pos_x -= (data->dir_x) * (MOVESPEED * disp->shift);
}

void	mv_left(t_mlx *disp, t_math_pos *data)
{
	if (is_in("0O", (disp->map)[(int)((data->pos_y) - \
		(data->dir_x) * (MOVESPEED * disp->shift))][(int)(data->pos_x)]))
		data->pos_y -= (data->dir_x) * (MOVESPEED * disp->shift);
	if (is_in("0O", (disp->map)[(int)(data->pos_y)][(int)((data->pos_x) + \
		(data->dir_y) * (MOVESPEED * disp->shift))]))
		data->pos_x += (data->dir_y) * (MOVESPEED * disp->shift);
}

void	mv_right(t_mlx *disp, t_math_pos *data)
{
	if (is_in("0O", (disp->map)[(int)((data->pos_y) + \
		(data->dir_x) * (MOVESPEED * disp->shift))][(int)(data->pos_x)]))
		data->pos_y += (data->dir_x) * (MOVESPEED * disp->shift);
	if (is_in("0O", (disp->map)[(int)(data->pos_y)][(int)((data->pos_x) - \
		(data->dir_y) * (MOVESPEED * disp->shift))]))
		data->pos_x -= (data->dir_y) * (MOVESPEED * disp->shift);
}
