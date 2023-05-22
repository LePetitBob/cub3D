/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:45:19 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/05 16:53:28 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	tex_px_inc(t_math_pos *data, t_pics_add *walls, t_img_data *img, int x)
{
	int	y;

	data->step = 1.0 * texHeight / (data->lineHeight);
	data->texPos = ((data->drawStart) - HEIGHT / 2 + \
		(data->lineHeight) / 2) * (data->step);
	y = data->drawStart;
	while (y < data->drawEnd)
	{
		data->texY = (int)(data->texPos) & (texHeight - 1);
		data->texPos += data->step;
		if (data->side == 1 && data->rayDirY < 0)
			px_put(img, x, y, px_ext(&(walls->wall), data->texX, data->texY));
		y++;
	}
}

void	tex_calc(t_math_pos *data)
{
	if (data->side == 0)
		data->wallX = data->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = data->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= floor((data->wallX));
	data->texX = (int)((data->wallX) * (double)texWidth);
	if (data->side == 0 && data->rayDirX > 0)
		data->texX = texWidth - (data->texX) - 1;
	if (data->side == 1 && data->rayDirY < 0)
		data->texX = texWidth - (data->texX) - 1;
}
