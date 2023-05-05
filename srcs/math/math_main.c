/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:56:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/05 15:09:52 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dda_loop(t_math_pos *data, t_mlx *map_data)
{
	while (!(data)->hit)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		if (map_data->map[data->mapY][data->mapX] == '1')
			data->hit = 1;
	}
}

void	calc_step_dist(t_math_pos *data)
{
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
	}
}

void	avoid_div_0(t_math_pos *data)
{
	data->deltaDistX = fabs(1 / data->rayDirX);
	data->deltaDistY = fabs(1 / data->rayDirY);
	data->hit = 0;
}

void	cam_dir_val(t_math_pos *data, int x)
{
	data->cameraX = 2 * x / (double)(WIDTH) - 1;
	data->rayDirX = data->dirX + data->planeX * data->cameraX;
	data->rayDirY = data->dirY + data->planeY * data->cameraX;
	data->mapX = (int)(data->posX);
	data->mapY = (int)(data->posY);
}

int	wall_printer(t_mlx *map_data)
{
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		cam_dir_val(&(map_data->data), x);
		avoid_div_0(&(map_data->data));
		calc_step_dist(&(map_data->data));
		dda_loop(&(map_data->data), map_data);
		calc_draw_lines(&(map_data->data));
		tex_calc(&(map_data->data));
		tex_px_inc(&(map_data->data), &(map_data->walls),
			&(map_data->data.img), x);
		draw_cf(&(map_data->data), &(map_data->data.img), *map_data, x);
		x++;
	}
	// map_data->data.img_printed = map_data->data.img;
	put_minimap(map_data);
	mlx_put_image_to_window(map_data->mlx, map_data->win,
		map_data->data.img.img, 0, 0);
	return (0);
}
