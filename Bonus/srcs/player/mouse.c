/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:30:18 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/25 14:31:20 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rtm_right(t_math_pos *data)
{
	data->old_dir_x = data->dir_x;
	data->dir_x = (data->dir_x) * cos(MROTSPEED) - \
		(data->dir_y) * sin(MROTSPEED);
	data->dir_y = (data->old_dir_x) * sin(MROTSPEED) + (data->dir_y) * \
		cos(MROTSPEED);
	data->old_plane_x = data->plane_x;
	data->plane_x = (data->plane_x) * cos(MROTSPEED) - \
		(data->plane_y) * sin(MROTSPEED);
	data->plane_y = (data->old_plane_x) * sin(MROTSPEED) + \
		(data->plane_y) * cos(MROTSPEED);
}

void	rtm_left(t_math_pos *data)
{
	data->old_dir_x = data->dir_x;
	data->dir_x = (data->dir_x) * cos(-MROTSPEED) - (data->dir_y) * \
		sin(-MROTSPEED);
	data->dir_y = (data->old_dir_x) * sin(-MROTSPEED) + \
		(data->dir_y) * cos(-MROTSPEED);
	data->old_plane_x = data->plane_x;
	data->plane_x = (data->plane_x) * cos(-MROTSPEED) - \
		(data->plane_y) * sin(-MROTSPEED);
	data->plane_y = (data->old_plane_x) * sin(-MROTSPEED) + \
		(data->plane_y) * cos(-MROTSPEED);
}

int	mouse_motion(int x, int y, t_mlx *disp)
{
	(void)y;
	if (x < (disp->x_mloc))
	{
		rtm_left(disp->data);
	}
	else if (x > (disp->x_mloc))
	{
		rtm_right(disp->data);
	}
	mlx_mouse_move(disp->mlx, disp->win, WIDTH / 2, HEIGHT / 2);
	return (1);
}
