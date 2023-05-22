/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:06:43 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/22 21:28:39 by vduriez          ###   ########.fr       */
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
	data->posx = player.x1;
	data->posy = player.y1;
	data->dirx = player.dx;
	data->diry = player.dy;
	if (data->dirx < 0)
		data->planey = FOV / (double)100;
	else if (data->dirx > 0)
		data->planey = FOV / (double)100 * -1;
	else
		data->planey = 0;
	if (data->diry < 0)
		data->planex = FOV / (double)100;
	else if (data->diry > 0)
		data->planex = FOV / (double)100 * -1;
	else
		data->planex = 0;
}
