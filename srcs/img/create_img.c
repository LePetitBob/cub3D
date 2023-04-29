/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:07:02 by ajeanne           #+#    #+#             */
/*   Updated: 2023/04/29 19:32:42 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	px_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int px_extract(t_img_data *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	create_wall_images(t_mlx *disp, t_pics_add *walls)
{
	walls->wallE.img = mlx_xpm_file_to_image(disp->mlx, disp->path_EA,
			&(walls->wallE.width), &(walls->wallE.height));
	walls->wallW.img = mlx_xpm_file_to_image(disp->mlx, disp->path_WE,
			&(walls->wallW.width), &(walls->wallW.height));
	walls->wallN.img = mlx_xpm_file_to_image(disp->mlx, disp->path_NO,
			&(walls->wallN.width), &(walls->wallN.height));
	walls->wallS.img = mlx_xpm_file_to_image(disp->mlx, disp->path_SO,
			&(walls->wallS.width), &(walls->wallS.height));
	if (!(walls->wallE.img) || !(walls->wallN.img) || !(walls->wallS.img) || !(walls->wallW.img))
		return (1);
	walls->wallE.addr = mlx_get_data_addr((walls->wallE.img), &(walls->wallE.bits_per_pixel), &(walls->wallE.line_length),
								&(walls->wallE.endian));
	walls->wallW.addr = mlx_get_data_addr((walls->wallW.img), &(walls->wallW.bits_per_pixel), &(walls->wallW.line_length),
								&(walls->wallW.endian));
	walls->wallN.addr = mlx_get_data_addr((walls->wallN.img), &(walls->wallN.bits_per_pixel), &(walls->wallN.line_length),
								&(walls->wallN.endian));
	walls->wallS.addr = mlx_get_data_addr((walls->wallS.img), &(walls->wallS.bits_per_pixel), &(walls->wallS.line_length),
								&(walls->wallS.endian));
	if (!(walls->wallE.addr) || !(walls->wallN.addr) || !(walls->wallS.addr) || !(walls->wallW.addr))
		return (1);
}

int	create_image(t_mlx *map_data, t_img_data *img)
{
	img->img = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	if (!(img->img))
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	if (!(img->addr))
		return (1);
}
