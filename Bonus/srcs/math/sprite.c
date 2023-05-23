/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 06:57:13 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 10:49:43 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	sort_sprites(int *order, double *dist, int amount)
// {
	
// }

void	sprite_casting(t_mlx *disp, t_math_pos *data, t_sprite_data *sprites)
{
	int	i;
	int	stripe;
	int	y;

	i = 0;
	while (i < NUMSPRITE)
	{
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((data->pos_x - sprites[i].x) * (data->pos_x - sprites[i].x) + (data->pos_y - sprites[i].y) * (data->pos_y - sprites[i].y));
		i++;
	}
	printf("dist = %f - cnt = %d\n", data->sprite_distance[0], disp->cnt);
	// sort_sprites(data->sprite_order, data->sprite_distance);
	//fntc cut
	i = 0;
	while (i < NUMSPRITE)
	{
		data->sprite_x = sprites[data->sprite_order[i]].x - data->pos_x;
		data->sprite_y = sprites[data->sprite_order[i]].y - data->pos_y;
		data->inv_det = 1.0 / (data->plane_x * data->dir_y - data->dir_x * data->plane_y);
		data->transform_x = data->inv_det * (data->dir_y * data->sprite_x - data->dir_x * data->sprite_y);
		data->transform_y = data->inv_det * (-(data->plane_y) * data->sprite_x + data->plane_x * data->sprite_y);
		data->sprite_screen_x = (int)((WIDTH / 2) * (1 + data->transform_x / data->transform_y));
		data->sprite_height = abs((int)(HEIGHT / (data->transform_y)));
		// calc sprite height on screen
		data->draw_start_y = -(data->sprite_height) / 2 + HEIGHT / 2;
		// calc draw part of height sprite
		if (data->draw_start_y < 0)
			data->draw_start_y = 0;
		data->draw_end_y = data->sprite_height / 2 + HEIGHT / 2;
		if (data->draw_end_y >= HEIGHT)
			data->draw_end_y = HEIGHT - 1;
		// calc width sprite
		data->sprite_width = abs((int)(HEIGHT / (data->transform_y)));
		data->draw_start_x = -(data->sprite_width) / 2 + data->sprite_screen_x;
		if (data->draw_start_x < 0)
			data->draw_start_x = 0;
		data->draw_end_x = data->sprite_width / 2 + data->sprite_screen_x;
		if (data->draw_end_x >= WIDTH)
			data->draw_end_x = WIDTH - 1;
		// loop
		stripe = data->draw_start_x;
		while (stripe < data->draw_end_x)
		{
			data->s_tex_x = (int)(256 * (stripe - (-(data->sprite_width) / 2 + data->sprite_screen_x)) * texWidth / data->sprite_width) / 256;
			if (data->transform_y > 0 && stripe > 0 && stripe < WIDTH && data->transform_y < data->z_buffer[stripe])
			{
				y = data->draw_start_y;
				while (y < data->draw_end_y)
				{
					data->s_d = (y) * 256 - HEIGHT * 128 + data->sprite_height * 128;
					data->s_tex_y = ((data->s_d * texHeight) / data->sprite_height) / 256;
					if (px_ext(data->p_sprites[0], data->s_tex_x, data->s_tex_y) != 16777215)
						px_put(data->img, stripe, y, px_ext(data->p_sprites[0], data->s_tex_x, data->s_tex_y));
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}