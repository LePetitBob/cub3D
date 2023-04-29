/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:56:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/04/29 16:35:52 by ajeanne          ###   ########.fr       */
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

void	tex_px_inc(t_math_pos *data, t_pics_add *walls, t_img_data *img, int x)
{
	int	y;

	data->step = 1.0 * texHeight / (data->lineHeight);
	data->texPos = ((data->drawStart) - HEIGHT / 2 + (data->lineHeight) / 2) * (data->step);
	y = data->drawStart;
	while (y < data->drawEnd)
	{
		data->texY = (int)(data->texPos) & (texHeight - 1);
		data->texPos += data->step;
		if (data->side == 1 && data->rayDirY < 0)
			px_put(img, x, y, px_extract(&(walls->wallN), data->texX, data->texY));
		else if (data->side == 0 && data->rayDirX > 0)
			px_put(img, x, y, px_extract(&(walls->wallE), data->texX, data->texY));
		else if (data->side == 1 && data->rayDirY > 0)
			px_put(img, x, y, px_extract(&(walls->wallS), data->texX, data->texY));
		else if (data->side == 0 && data->rayDirX < 0)
			px_put(img, x, y, px_extract(&(walls->wallW), data->texX, data->texY));
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

void	calc_draw_lines(t_math_pos *data)
{
	// int	y;
	
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
		tex_px_inc(&(map_data->data), &(map_data->walls), &(map_data->data.img), x);
		draw_cf(&(map_data->data), &(map_data->data.img), *map_data, x);
		x++;
	}
	map_data->data.img_printed = map_data->data.img;
	mlx_put_image_to_window(map_data->mlx, map_data->win, map_data->data.img_printed.img, 0, 0);
	return (0);
}