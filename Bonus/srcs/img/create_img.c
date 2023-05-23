/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:07:02 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 11:21:29 by ajeanne          ###   ########.fr       */
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

int	scatman(t_mlx *disp, t_pics_add *walls)
{
	int	i;
	char	*s;
	

	s = "images/scat0.xpm";
	i = -1;
	while (++i < 10)
	{
		disp->path_scat[i] = ft_strdup(s);
		disp->path_scat[i][11] += i;
	}
	i = -1;
	while (++i < 10)
	{
		walls->s_scat[i].img = mlx_xpm_file_to_image(disp->mlx, disp->path_scat[i],
				&(walls->s_scat[i].width), &(walls->s_scat[i].height));
		disp->walls->s_scat[i].addr = mlx_get_data_addr((disp->walls->s_scat[i].img),
			&(disp->walls->s_scat[i].bits_per_pixel), &(disp->walls->s_scat[i].line_length),
			&(disp->walls->s_scat[i].endian));
	}
	i = -1;
	while (++i < 10)
		free(disp->path_scat[i]);
	return (0);
}

int	init_imgs(t_mlx *disp, t_pics_add *walls)
{
	walls->wall.img = mlx_xpm_file_to_image(disp->mlx, disp->path_wall,
			&(walls->wall.width), &(walls->wall.height));
	walls->ceiling.img = mlx_xpm_file_to_image(disp->mlx, disp->path_floor,
			&(walls->ceiling.width), &(walls->ceiling.height));
	walls->floor.img = mlx_xpm_file_to_image(disp->mlx, disp->path_ceiling,
			&(walls->floor.width), &(walls->floor.height));
	walls->door.img = mlx_xpm_file_to_image(disp->mlx, disp->path_door,
			&(walls->door.width), &(walls->door.height));
	walls->s_sdk.img = mlx_xpm_file_to_image(disp->mlx, disp->path_sdk,
			&(walls->s_sdk.width), &(walls->s_sdk.height));
	scatman(disp, walls);
	if (!(walls->wall.img) || !(walls->ceiling.img)
		|| !(walls->floor.img) || !(walls->door.img) || !(walls->s_sdk.img))
		return (0);
	return (1);
}

int	create_wall_images(t_mlx *disp)
{
	if (!init_imgs(disp, disp->walls))
		return (0);
	disp->walls->wall.addr = mlx_get_data_addr((disp->walls->wall.img),
			&(disp->walls->wall.bits_per_pixel), &(disp->walls->wall.line_length),
			&(disp->walls->wall.endian));
	disp->walls->ceiling.addr = mlx_get_data_addr((disp->walls->ceiling.img),
			&(disp->walls->ceiling.bits_per_pixel), &(disp->walls->ceiling.line_length),
			&(disp->walls->ceiling.endian));
	disp->walls->floor.addr = mlx_get_data_addr((disp->walls->floor.img),
			&(disp->walls->floor.bits_per_pixel), &(disp->walls->floor.line_length),
			&(disp->walls->floor.endian));
	disp->walls->door.addr = mlx_get_data_addr((disp->walls->door.img),
			&(disp->walls->door.bits_per_pixel), &(disp->walls->door.line_length),
			&(disp->walls->door.endian));
	disp->walls->s_sdk.addr = mlx_get_data_addr((disp->walls->s_sdk.img),
			&(disp->walls->s_sdk.bits_per_pixel), &(disp->walls->s_sdk.line_length),
			&(disp->walls->s_sdk.endian));
	if (!(disp->walls->wall.addr) || !(disp->walls->ceiling.addr)
		|| !(disp->walls->floor.addr) || !(disp->walls->door.addr) || !(disp->walls->s_sdk.addr))
		return (0);
	return (1);
}

int	create_image(t_mlx *map_data)
{
	map_data->data->img->img = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	if (!(map_data->data->img->img))
		return (0);
	map_data->data->img->addr = \
	mlx_get_data_addr(map_data->data->img->img, &(map_data->data->img->bits_per_pixel), \
	&(map_data->data->img->line_length), &(map_data->data->img->endian));
	if (!(map_data->data->img->addr))
		return (0);
	return (1);
}
