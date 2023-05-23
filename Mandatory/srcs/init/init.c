/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:06:43 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 00:28:10 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	disp_init_values(t_mlx *disp)
{
	disp->pth_m = "./images/bs10.xpm";
	disp->pth_p = "./images/rs10.xpm";
	disp->pth_v = "./images/nothingness10.xpm";
	disp->height = 1;
	disp->color_f = -1;
	disp->color_c = -1;
}

void	init_values(t_math_pos *data, t_vec2 player)
{
	data->pos_x = player.x1;
	data->pos_y = player.y1;
	data->dir_x = player.dx;
	data->dir_y = player.dy;
	if (data->dir_x < 0)
		data->plane_y = FOV / (double)100;
	else if (data->dir_x > 0)
		data->plane_y = FOV / (double)100 * -1;
	else
		data->plane_y = 0;
	if (data->dir_y < 0)
		data->plane_x = FOV / (double)100;
	else if (data->dir_y > 0)
		data->plane_x = FOV / (double)100 * -1;
	else
		data->plane_x = 0;
}
