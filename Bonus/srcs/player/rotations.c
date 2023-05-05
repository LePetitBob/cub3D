/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:01:54 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/03 19:10:31 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rt_right(t_math_pos *data)
{
	data->oldDirX = data->dirX;
	data->dirX = (data->dirX) * cos(ROTSPEED) - (data->dirY) * sin(ROTSPEED);
	data->dirY = (data->oldDirX) * sin(ROTSPEED) + (data->dirY) * cos(ROTSPEED);
	data->oldPlaneX = data->planeX;
	data->planeX = (data->planeX) * cos(ROTSPEED) - \
		(data->planeY) * sin(ROTSPEED);
	data->planeY = (data->oldPlaneX) * sin(ROTSPEED) + \
		(data->planeY) * cos(ROTSPEED);
}

void	rt_left(t_math_pos *data)
{
	data->oldDirX = data->dirX;
	data->dirX = (data->dirX) * cos(-ROTSPEED) - (data->dirY) * sin(-ROTSPEED);
	data->dirY = (data->oldDirX) * sin(-ROTSPEED) + \
		(data->dirY) * cos(-ROTSPEED);
	data->oldPlaneX = data->planeX;
	data->planeX = (data->planeX) * cos(-ROTSPEED) - \
		(data->planeY) * sin(-ROTSPEED);
	data->planeY = (data->oldPlaneX) * sin(-ROTSPEED) + \
		(data->planeY) * cos(-ROTSPEED);
}
