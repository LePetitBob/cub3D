/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:30:18 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/05 16:03:05 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rtm_right(t_math_pos *data)
{
	data->oldDirX = data->dirX;
	data->dirX = (data->dirX) * cos(MROTSPEED) - (data->dirY) * sin(MROTSPEED);
	data->dirY = (data->oldDirX) * sin(MROTSPEED) + (data->dirY) * \
		cos(MROTSPEED);
	data->oldPlaneX = data->planeX;
	data->planeX = (data->planeX) * cos(MROTSPEED) - \
		(data->planeY) * sin(MROTSPEED);
	data->planeY = (data->oldPlaneX) * sin(MROTSPEED) + \
		(data->planeY) * cos(MROTSPEED);
}

void	rtm_left(t_math_pos *data)
{
	data->oldDirX = data->dirX;
	data->dirX = (data->dirX) * cos(-MROTSPEED) - (data->dirY) * \
		sin(-MROTSPEED);
	data->dirY = (data->oldDirX) * sin(-MROTSPEED) + \
		(data->dirY) * cos(-MROTSPEED);
	data->oldPlaneX = data->planeX;
	data->planeX = (data->planeX) * cos(-MROTSPEED) - \
		(data->planeY) * sin(-MROTSPEED);
	data->planeY = (data->oldPlaneX) * sin(-MROTSPEED) + \
		(data->planeY) * cos(-MROTSPEED);
}

int	mouse_motion(int x, int y, t_mlx *disp)
{
	(void)y;
	if (x < (disp->x_mloc))
	{
		rtm_left(&(disp->data));
	}
	else if (x > (disp->x_mloc))
	{
		rtm_right(&(disp->data));
	}
	disp->x_mloc = x;
	return (1);
}
