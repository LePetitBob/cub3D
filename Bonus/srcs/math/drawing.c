/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:47:19 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/02 18:28:47 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_cf(t_math_pos *data, t_img_data *img, t_mlx map_data, int x)
{
	int	y;

	y = 0;
	while (y < data->drawStart)
	{
		px_put(img, x, y, map_data.color_c);
		y++;
	}
	y = data->drawEnd;
	while (y < HEIGHT - 1)
	{
		px_put(img, x, y, map_data.color_f);
		y++;
	}
}

void	calc_draw_lines(t_math_pos *data)
{
	if (!(data)->side)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = (int)(HEIGHT / data->perpWallDist);
	data->drawStart = (-(data->lineHeight)) / 2 + HEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + HEIGHT / 2;
	if (data->drawEnd >= HEIGHT)
		data->drawEnd = HEIGHT -1;
}

void	copy_img_add(t_img_data	*img, t_img_data *img_printed)
{
	img_printed->img = img->img;
}
