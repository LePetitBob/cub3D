/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:07:02 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/31 14:09:07 by vduriez          ###   ########.fr       */
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
	disp->tmp = 0;
	walls->wall_n.img = xpm_to_img(disp, disp->path_ea, &walls->wall_n);
	walls->wall_s.img = xpm_to_img(disp, disp->path_ea, &walls->wall_s);
	walls->wall_e.img = xpm_to_img(disp, disp->path_ea, &walls->wall_e);
	walls->wall_w.img = xpm_to_img(disp, disp->path_ea, &walls->wall_w);
	if (!(walls->wall_e.img) || !(walls->wall_n.img) || !(walls->wall_s.img)
		|| !(walls->wall_w.img) || disp->tmp == -1)
		return (0);
	return (1);
}

int	create_wall_images(t_mlx *disp, t_pics_add *walls)
{
	if (!init_imgs(disp, walls))
		return (0);
	walls->wall_e.addr = mlx_get_data_addr((walls->wall_e.img),
			&(walls->wall_e.bits_per_pixel), &(walls->wall_e.line_length),
			&(walls->wall_e.endian));
	walls->wall_w.addr = mlx_get_data_addr((walls->wall_w.img),
			&(walls->wall_w.bits_per_pixel), &(walls->wall_w.line_length),
			&(walls->wall_w.endian));
	walls->wall_n.addr = mlx_get_data_addr((walls->wall_n.img),
			&(walls->wall_n.bits_per_pixel), &(walls->wall_n.line_length),
			&(walls->wall_n.endian));
	walls->wall_s.addr = mlx_get_data_addr((walls->wall_s.img),
			&(walls->wall_s.bits_per_pixel), &(walls->wall_s.line_length),
			&(walls->wall_s.endian));
	if (!(walls->wall_e.addr) || !(walls->wall_n.addr) || !(walls->wall_s.addr)
		|| !(walls->wall_w.addr))
		return (0);
	return (1);
}

int	create_image(t_mlx *map_data, t_img_data *img)
{
	img->img = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	if (!(img->img))
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!(img->addr))
		return (0);
	return (1);
}
