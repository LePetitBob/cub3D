/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:56:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/04/27 04:07:27 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	wall_position(s_vec2 player, t_mlx map_data)
// {
// 	s_mat_pos	data;
// 	int			x;
	
// 	// Init values
// 	data.posX = player.x1;
// 	data.posY = player.y2;
// 	data.dirX = player.dx;
// 	data.dirY = player.dy;
	
// 	// Init planes depends of direction
// 	if (!data.dirX)
// 		data.planeX = gs / 100;
// 	else
// 		data.planeX = 0;
// 	if (!data.dirY)
// 		data.planeY = gs / 100;
// 	else
// 		data.planeY = 0;
	
// 	// Calc rayDir
// 	x = 0;
// 	while (x < width)
// 	{
// 		data.cameraX = 2 * x / double(width) - 1;
// 		data.rayDirX = data.dirX + data.planeX * data.cameraX;
// 		data.rayDirY = data.dirY + data.planeY * data.cameraX;
// 		x++;
		
// 		// Init for DDA
// 		data.mapX = int(data.posX);
// 		data.mapY = int(data.posY);
// 		// Care for avoid divide by 0
// 		if (!data.rayDirX)
// 			data.deltaDistX = -1;
// 		else
// 			data.deltaDistX = abs(1 / data.rayDirX);
// 		if (!data.rayDirY)
// 			data.deltaDistY = -1;
// 		else
// 			data.deltaDistY = abs(1 / data.rayDirY);
// 		data.hit = 0;

// 		// Calculate step and initial dist
// 		if (data.rayDirX < 0)
// 		{
// 			data.stepX = -1;
// 			data.sideDistX = (data.posX - data.mapX) * data.deltaDistX; 
// 		}
// 		else
// 		{
// 			data.stepX = 1;
// 			data.sideDistX = (data.mapX + 1.0 - data.posX) * data.deltaDistX;
// 		}
// 		if (data.rayDirY < 0)
// 		{
// 			data.stepY = -1;
// 			data.sideDistY = (data.posY - data.mapY) * data.deltaDistY;
// 		}
// 		else
// 		{
// 			data.stepY = 1;
// 			data.sideDistY = (data.mapY + 1.0 - data.posY) * data.deltaDistY;
// 		}

// 		// DDA loop
// 		while (!data.hit)
// 		{
// 			if (data.sideDistX < data.sideDistY)
// 			{
// 				data.sideDistX += data.deltaDistX;
// 				data.mapX += data.stepX;
// 				data.side = 0;
// 			}
// 			else
// 			{
// 				data.sideDistY += data.deltaDistY;
// 				data.mapY += data.stepY;
// 				data.side = 1;
// 			}
// 			if (map_data.map[data.mapX][data.mapY] == 1)
// 				data.hit = 1;
// 		}
		
// 		// Perp to avoid Euclidian distance, also avoid fisheye effect
// 		if (!side)
// 			data.perpWallDist = (data.sideDistX - data.deltaDistX);
// 		else
// 			data.perpWallDist = (data.sideDistY - data.deltaDistY);
		
// 		// Calculate Height of line to draw
// 		data.lineHeight = int(height / data.perpWallDist);
		
// 		// Calculate the highest and lowest pixel to draw
// 		data.drawStart = (-lineHeight) / 2 + height / 2;
// 		if (data.drawStart < 0)
// 			data.drawStart = 0;
// 		data.drawEnd = data.lineHeight / 2 + height / 2;
// 		if (data.drawEnd >= height)
// 			data.drawEnd = height -1;
// 	}
// }

void	calc_draw_lines(s_mat_pos *data)
{
	if (!(data)->side)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = int(HEIGHT / data->perpWallDist);
	data->drawStart = (-(data->lineHeight)) / 2 + HEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + HEIGHT / 2;
	if (data->drawEnd >= HEIGHT)
		data->drawEnd = HEIGHT -1;
}

void	dda_loop(s_mat_pos *data)
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
		if (map_data->map[data->mapX][data->mapY] == 1)
			data->hit = 1;
	}
}

void	calc_step_dist(s_mat_pos *data)
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

void	avoid_div_0(s_mat_pos *data)
{
	if (!(data)->rayDirX)
		data->deltaDistX = -1;
	else
		data->deltaDistX = abs(1 / data->rayDirX);
	if (!(data)->rayDirY)
		data->deltaDistY = -1;
	else
		data->deltaDistY = abs(1 / data->rayDirY);
	data->hit = 0;
}

void	cam_dir_val(s_mat_pos *data)
{
	data->cameraX = 2 * x / double(WIDTH) - 1;
	data->rayDirX = data->dirX + data->planeX * data->cameraX;
	data->rayDirY = data->dirY + data->planeY * data->cameraX;
	data.mapX = int(data.posX);
	data.mapY = int(data.posY);
}

void	init_values(s_mat_pos *data, s_vec2 player)
{
	data->posX = player.x1;
	data->posY = player.y2;
	data->dirX = player.dx;
	data->dirY = player.dy;
	if (!(data)->dirX)
		data->planeX = FOV / 100;
	else
		data->planeX = 0;
	if (!(data)->dirY)
		data->planeY = FOV / 100;
	else
		data->planeY = 0;
}

int	wall_printer(s_vec2 player, t_mlx map_data)
{
	t_mat_pos	data;
	t_img		img;
	int			x;
	
	init_values(&data, player);
	x = 0;
	while (x < WIDTH)
	{
		cam_dir_val(&data);
		x++;
		avoid_div_0(&data);
		calc_step_dist(&data);
		dda_loop(&data);
		calc_draw_lines(&data);
	}
	return (0);
}

// int	check_map(char *ent_map, t_mlx *disp)
// {
// 	if (!extension_check(".cub", ent_map))
// 		return (print_err(ERR_CUB), 1);
// 	disp.mapname = ft_strdup(av[1]);
// 	if (!disp.mapname)
// 		return (print_err(ERR_MALLOC), 1);
// 	map_check(&disp);
// }

// int	main(int ac, char **av)
// {
// 	t_mlx	disp;

// 	disp = (t_mlx){0};
// 	if (ac != 2)
// 		return (ft_exit(ERR_ARGS));
// 	if (check_map(av[1], &disp))
// 		return (0);
// }