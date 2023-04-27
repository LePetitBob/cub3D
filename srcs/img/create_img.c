/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:07:02 by ajeanne           #+#    #+#             */
/*   Updated: 2023/04/27 05:35:36 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	px_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_image(t_mlx *map_data, t_img_data *img)
{
	img->img = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}

// int	main()
// {
// 	t_img_data	img;
// 	t_mlx	disp;

// 	disp = (t_mlx){0};
// 	disp.mlx = mlx_init();
// 	disp.win = mlx_new_window(disp.mlx, WIDTH, HEIGHT, "Triangle2D");
// 	img.img = mlx_new_image(disp.mlx, WIDTH, HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	px_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(disp.mlx, disp.win, img.img, 0, 0);
// 	mlx_loop(disp.mlx);
// }