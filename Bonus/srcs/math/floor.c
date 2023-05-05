/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:51:28 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/03 20:18:38 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fc_casting_x(t_mlx *disp, t_math_pos *data, t_img_data *img, int *loc)
{
	data->cellX = (int)(data->floorX);
	data->cellY = (int)(data->floorY);
	data->tx = (int)(texWidth * (data->floorX - data->cellX)) & (texWidth - 1);
	data->ty = (int)(texHeight * (data->floorY - data->cellY)) &\
		(texHeight - 1);
	data->floorX += data->floorStepX;
	data->floorY += data->floorStepY;
	px_put(img, loc[1], loc[0], px_ext(&(disp->walls.floor), \
		data->tx, data->ty));
	px_put(img, loc[1], (HEIGHT - loc[0] - 1), px_ext(&(disp->walls.wallE), \
		data->tx, data->ty));
}

int	fc_casting(t_mlx *disp, t_math_pos *data, t_img_data *img)
{
	int	loc[2];

	loc[0] = -1;
	while (++loc[0] < HEIGHT)
	{
		data->rayDirX0 = data->dirX - data->planeX;
		data->rayDirY0 = data->dirY - data->planeY;
		data->rayDirX1 = data->dirX + data->planeX;
		data->rayDirY1 = data->dirY + data->planeY;
		data->pos = loc[0] - HEIGHT / 2;
		data->posZ = 0.5 * HEIGHT;
		data->rowDistance = data->posZ / data->pos;
		data->floorStepX = data->rowDistance * (data->rayDirX1 - \
		data->rayDirX0) / WIDTH;
		data->floorStepY = data->rowDistance * (data->rayDirY1 - \
		data->rayDirY0) / WIDTH;
		data->floorX = data->posX + data->rowDistance * data->rayDirX0;
		data->floorY = data->posY + data->rowDistance * data->rayDirY0;
		loc[1] = -1;
		while (++loc[1] < WIDTH)
			fc_casting_x(disp, data, img, loc);
	}
	return (1);
}
