/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:06:43 by ajeanne           #+#    #+#             */
/*   Updated: 2023/04/29 19:53:39 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
