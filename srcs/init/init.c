/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:06:43 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/10 05:26:51 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	disp_init_values(t_mlx *disp)
{
	disp->line = NULL;
	disp->path_NO = NULL;
	disp->path_SO = NULL;
	disp->path_WE = NULL;
	disp->path_EA = NULL;
	disp->map = NULL;
	disp->pth_m = "./images/bs10.xpm";
	disp->pth_p = "./images/rs10.xpm";
	disp->pth_v = "./images/nothingness10.xpm";
	disp->player = 0;
	disp->height = 1;
	disp->length = 0;
	disp->length_map = 0;
	disp->height_map = 0;
	disp->tmp = 0;
	disp->color_f = -1;
	disp->color_c = -1;
	disp->is_floor = 0;
	disp->is_ceiling = 0;
	disp->parsing_pb = 0;
	disp->map_begin = 0;
}

void	init_values(t_math_pos *data, t_vec2 player)
{
	data->posX = player.x1;
	data->posY = player.y1;
	data->dirX = player.dx;
	data->dirY = player.dy;
	if (data->dirX < 0)
		data->planeY = FOV / (double)100;
	else if (data->dirX > 0)
		data->planeY = FOV / (double)100 * -1;
	else
		data->planeY = 0;
	if (data->dirY < 0)
		data->planeX = FOV / (double)100;
	else if (data->dirY > 0)
		data->planeX = FOV / (double)100 * -1;
	else
		data->planeX = 0;
}
