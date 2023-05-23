/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:01:54 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 00:31:01 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rt_right(t_math_pos *data)
{
	data->old_dir_x = data->dir_x;
	data->dir_x = (data->dir_x) * cos(ROTSPEED) - (data->dir_y) * sin(ROTSPEED);
	data->dir_y = (data->old_dir_x) * sin(ROTSPEED) + (data->dir_y) * \
		cos(ROTSPEED);
	data->old_plane_x = data->plane_x;
	data->plane_x = (data->plane_x) * cos(ROTSPEED) - \
		(data->plane_y) * sin(ROTSPEED);
	data->plane_y = (data->old_plane_x) * sin(ROTSPEED) + \
		(data->plane_y) * cos(ROTSPEED);
}

void	rt_left(t_math_pos *data)
{
	data->old_dir_x = data->dir_x;
	data->dir_x = (data->dir_x) * \
	cos(-ROTSPEED) - (data->dir_y) * sin(-ROTSPEED);
	data->dir_y = (data->old_dir_x) * sin(-ROTSPEED) + \
		(data->dir_y) * cos(-ROTSPEED);
	data->old_plane_x = data->plane_x;
	data->plane_x = (data->plane_x) * cos(-ROTSPEED) - \
		(data->plane_y) * sin(-ROTSPEED);
	data->plane_y = (data->old_plane_x) * sin(-ROTSPEED) + \
		(data->plane_y) * cos(-ROTSPEED);
}
