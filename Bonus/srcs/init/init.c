/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:06:43 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 00:13:24 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
