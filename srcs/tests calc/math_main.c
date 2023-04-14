/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:56:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/04/14 17:50:46 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define gs = 60;
#define width = 320;
#define height = 320;

int	wall_position(s_vec2 player, s_mlx map_data)
{
	s_mat_pos	data;
	int			x;
	
	// Init values
	data.posX = player.x1;
	data.posY = player.y2;
	data.dirX = player.dx;
	data.dirY = player.dy;
	
	// Init planes depends of direction
	if (!data.dirX)
		data.planeX = gs / 100;
	else
		data.planeX = 0;
	if (!data.dirY)
		data.planeY = gs / 100;
	else
		data.planeY = 0;
	
	// Calc rayDir
	x = 0;
	while (x < width)
	{
		data.cameraX = 2 * x / double(width) - 1;
		data.rayDirX = data.dirX + data.planeX * data.cameraX;
		data.rayDirY = data.dirY + data.planeY * data.cameraX;
		x++;
		
		// Init for DDA
		data.mapX = int(data.posX);
		data.mapY = int(data.posY);
		// Care for avoid divide by 0
		if (!data.rayDirX)
			data.deltaDistX = -1;
		else
			data.deltaDistX = abs(1 / data.rayDirX);
		if (!data.rayDirY)
			data.deltaDistY = -1;
		else
			data.deltaDistY = abs(1 / data.rayDirY);
		data.hit = 0;

		// Calculate step and initial dist
		if (data.rayDirX < 0)
		{
			data.stepX = -1;
			data.sideDistX = (data.posX - data.mapX) * data.deltaDistX; 
		}
		else
		{
			data.stepX = 1;
			data.sideDistX = (data.mapX + 1.0 - data.posX) * data.deltaDistX;
		}
		if (data.rayDirY < 0)
		{
			data.stepY = -1;
			data.sideDistY = (data.posY - data.mapY) * data.deltaDistY;
		}
		else
		{
			data.stepY = 1;
			data.sideDistY = (data.mapY + 1.0 - data.posY) * data.deltaDistY;
		}

		// DDA loop
		while (!data.hit)
		{
			if (data.sideDistX < data.sideDistY)
			{
				data.sideDistX += data.deltaDistX;
				data.mapX += data.stepX;
				data.side = 0;
			}
			else
			{
				data.sideDistY += data.deltaDistY;
				data.mapY += data.stepY;
				data.side = 1;
			}
			if (map_data.map[data.mapX][data.mapY] == 1)
				data.hit = 1;
		}
		
		// Perp to avoid Euclidian distance, also avoid fisheye effect
		if (!side)
			data.perpWallDist = (data.sideDistX - data.deltaDistX);
		else
			data.perpWallDist = (data.sideDistY - data.deltaDistY);
	}
}