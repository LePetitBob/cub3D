/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:51:28 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/02 20:40:13 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	floor_casting(t_mlx *disp,  t_math_pos *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		data->rayDirX0 = data->dirX - data->planeX;
		data->rayDirY0 = data->dirY - data->planeY;
		data->rayDirX1 = data->dirX + data->planeX;
		data->rayDirY1 = data->dirY - data->planeY;
		data->pos = y - HEIGHT / 2;
		data->posZ = 0.5 * HEIGHT;
		data->rowDistance = data->posZ / data->pos;
		data->floorStepX = data->rowDistance * (data->rayDirX1 - data->rayDirX0) / HEIGHT;
		data->floorStepY = data->rowDistance * (data->rayDirY1 - data->rayDirY0) / HEIGHT;
		data->floorX = data->posX + data->rowDistance / data->rayDirX0;
		data->floorY = data->posY + data->rowDistance / data->rayDirY0;
		x = -1;
		while (++x < WIDTH)
		{
			data->cellX = (int)(data->floorX);
			data->cellY = (int)(data->floorY);
			data->tx = (int)(texWidth * (data->floorX - data->cellX)) & (texWidth - 1);
			data->ty = (int)(texHeight * (data->floorY - data->cellY)) & (texHeight - 1);
			data->floorX += data->floorStepX;
			data->floorY += data->floorStepY;
		} 
	}
}