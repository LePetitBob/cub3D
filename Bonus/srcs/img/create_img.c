/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:07:02 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/31 13:05:41 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	scatman(t_mlx *disp)
{
	int		i;
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
		disp->walls->s_scat[i].img = xpm_to_img(disp, disp->path_scat[i], \
			&disp->walls->s_scat[i]);
		if (!disp->walls->s_scat[i].img || disp->tmp == -1)
			return (1);
		disp->walls->s_scat[i].addr = img_add(&disp->walls->s_scat[i]);
		if (!disp->walls->s_scat[i].addr)
			return (1);
	}
	i = -1;
	while (++i < 10)
		free(disp->path_scat[i]);
	return (0);
}

int	init_imgs(t_mlx *disp, t_pics_add *walls)
{
	disp ->tmp = 0;
	walls->wall.img = xpm_to_img(disp, disp->path_wall, &walls->wall);
	walls->ceiling.img = xpm_to_img(disp, disp->path_ceiling, \
		&walls->ceiling);
	walls->floor.img = xpm_to_img(disp, disp->path_floor, &walls->floor);
	walls->door.img = xpm_to_img(disp, disp->path_door, &walls->door);
	walls->shrekw.img = xpm_to_img(disp, disp->path_shrekw, &walls->shrekw);
	walls->berniew.img = xpm_to_img(disp, disp->path_berniew, &walls->berniew);
	walls->s_sdk.img = xpm_to_img(disp, disp->path_sdk, &walls->s_sdk);
	walls->s_sshrekf.img = xpm_to_img(disp, disp->path_sshrekf, \
		&walls->s_sshrekf);
	if (scatman(disp))
		return (0);
	if (!(walls->wall.img) || !(walls->ceiling.img) || !(walls->floor.img)
		|| !(walls->door.img) || !(walls->s_sdk.img) || !(walls->shrekw.img)
		|| !(walls->berniew.img) || !(walls->s_sshrekf.img) || disp->tmp == -1)
		return (0);
	return (1);
}

int	create_wall_images(t_mlx *disp)
{
	disp->tmp = 0;
	if (!init_imgs(disp, disp->walls))
		return (0);
	disp->walls->wall.addr = img_add(&disp->walls->wall);
	disp->walls->ceiling.addr = img_add(&disp->walls->ceiling);
	disp->walls->floor.addr = img_add(&disp->walls->floor);
	disp->walls->door.addr = img_add(&disp->walls->door);
	disp->walls->shrekw.addr = img_add(&disp->walls->shrekw);
	disp->walls->s_sdk.addr = img_add(&disp->walls->s_sdk);
	disp->walls->s_sshrekf.addr = img_add(&disp->walls->s_sshrekf);
	disp->walls->berniew.addr = img_add(&disp->walls->berniew);
	if (!(disp->walls->wall.addr) || !(disp->walls->ceiling.addr)
		|| !(disp->walls->floor.addr) || !(disp->walls->door.addr)
		|| !(disp->walls->s_sdk.addr) || !(disp->walls->shrekw.addr)
		|| !(disp->walls->s_sshrekf.addr) || !(disp->walls->berniew.addr)
		|| disp->tmp == -1)
		return (0);
	return (1);
}

int	create_image(t_mlx *map_data)
{
	map_data->data->img->img = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	if (!(map_data->data->img->img))
		return (0);
	map_data->data->img->addr = img_add(map_data->data->img);
	if (!(map_data->data->img->addr))
		return (0);
	return (1);
}
