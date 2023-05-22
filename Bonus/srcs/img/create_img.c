/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:07:02 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/05 17:45:56 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	px_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	px_ext(t_img_data *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	init_imgs(t_mlx *disp, t_pics_add *walls)
{
	walls->wall.img = mlx_xpm_file_to_image(disp->mlx, disp->path_wall,
			&(walls->wall.width), &(walls->wall.height));
	walls->ceiling.img = mlx_xpm_file_to_image(disp->mlx, disp->path_ceiling,
			&(walls->ceiling.width), &(walls->ceiling.height));
	walls->floor.img = mlx_xpm_file_to_image(disp->mlx, disp->path_floor,
			&(walls->floor.width), &(walls->floor.height));
	if (!(walls->wall.img) || !(walls->ceiling.img) || !(walls->floor.img))
		return (0);
	return (1);
}

int	create_wall_images(t_mlx *disp)
{
	t_pics_add walls;
	
	disp->walls = &walls;
	if (!init_imgs(disp, &walls))
		return (0);
	walls.wall.addr = mlx_get_data_addr((walls.wall.img),
			&(walls.wall.bits_per_pixel), &(walls.wall.line_length),
			&(walls.wall.endian));
	walls.ceiling.addr = mlx_get_data_addr((walls.ceiling.img),
			&(walls.ceiling.bits_per_pixel), &(walls.ceiling.line_length),
			&(walls.ceiling.endian));
	walls.floor.addr = mlx_get_data_addr((walls.floor.img),
			&(walls.floor.bits_per_pixel), &(walls.floor.line_length),
			&(walls.floor.endian));
	if (!(walls.wall.addr) || !(walls.ceiling.addr) || !(walls.floor.addr))
		return (0);
	return (1);
}

int	create_image(t_mlx *map_data)
{
	t_img_data img;
	
	map_data->data->img = &img;
	img.img = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	if (!(img.img))
		return (0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	if (!(img.addr))
		return (0);
	return (1);
}
