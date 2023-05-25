/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:06:43 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/25 16:29:44 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_values(t_math_pos *data, t_vec2 player)
{
	data->pos_x = player.x1;
	data->pos_y = player.y1;
	data->dir_x = player.dx;
	data->dir_y = player.dy;
	if (data->dir_x > 0)
		data->plane_y = FOV / (double)100;
	else if (data->dir_x < 0)
		data->plane_y = FOV / (double)100 * -1;
	else
		data->plane_y = 0;
	if (data->dir_y < 0)
		data->plane_x = FOV / (double)100;
	else if (data->dir_y > 0)
		data->plane_x = FOV / (double)100 * -1;
	else
		data->plane_x = 0;
}

void	init_sprites(t_math_pos *data)
{
	int	i;

	i = 0;
	while (i < NUMSPRITE)
	{
		if (i == 0)
			data->sprites[i] = (t_sprite_data){9.5, 9.5, 0};
		else if (i == 1)
			data->sprites[i] = (t_sprite_data){5.5, 9.5, 1};
		else if (i == 2)
			data->sprites[i] = (t_sprite_data){15.5, 9.5, 2};
		i++;
	}
}

// void	naruto_fov(t_mlx *disp)
// {
// 	if (disp->data->plane_y > 0)
// 		disp->data->plane_y = (FOV + 10) / (double)100;
// 	else if (disp->data->plane_y < 0)
// 		disp->data->plane_y = (FOV + 10) / (double)100 * -1;
// 	if (disp->data->plane_x > 0)
// 		disp->data->plane_x = (FOV + 10) / (double)100;
// 	else if (disp->data->plane_x < 0)
// 		disp->data->plane_x = (FOV + 10) / (double)100 * -1;
// }

// void	unnaruto_fov(t_mlx *disp)
// {
// 	if (disp->data->plane_y > 0)
// 		disp->data->plane_y = FOV / (double)100;
// 	else if (disp->data->plane_y < 0)
// 		disp->data->plane_y = FOV / (double)100 * -1;
// 	if (disp->data->plane_x > 0)
// 		disp->data->plane_x = FOV / (double)100;
// 	else if (disp->data->plane_x < 0)
// 		disp->data->plane_x = FOV / (double)100 * -1;
// }
