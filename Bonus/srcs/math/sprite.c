/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 06:57:13 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/25 16:57:08 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	sort_sprites(t_math_pos *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < NUMSPRITE)
	{
		if (i + 1 < NUMSPRITE && data->sprite_distance[data->sprite_order[i]] \
			< data->sprite_distance[data->sprite_order[i + 1]])
		{
			j = data->sprite_order[i];
			data->sprite_order[i] = data->sprite_order[i + 1];
			data->sprite_order[i + 1] = j;
			i = -1;
		}
	}
}

void	sprite_casting2(t_math_pos *data, int i, int stripe)
{
	int	y;
	int	sd;

	sd = data->sprites[data->sprite_order[i]].texture;
	y = data->draw_start_y;
	while (y < data->draw_end_y)
	{
		data->s_d = (y) * 256 - HEIGHT * 128 + data->sprite_height * 128;
		data->s_tex_y = ((data->s_d * TEX_HEIGHT) / data->sprite_height) / 256;
		if (px_ext(data->p_sprites[sd], data->s_tex_x, data->s_tex_y) != \
			16777215)
			px_put(data->img, stripe, y, \
				px_ext(data->p_sprites[sd], data->s_tex_x, data->s_tex_y));
		y++;
	}
}

void	sprite_casting1(t_math_pos *data, t_sprite_data *sprites, int i)
{
	data->sprite_x = sprites[data->sprite_order[i]].x - data->pos_x;
	data->sprite_y = sprites[data->sprite_order[i]].y - data->pos_y;
	data->inv_det = 1.0 / (data->plane_x * data->dir_y - data->dir_x * \
		data->plane_y);
	data->transform_x = data->inv_det * (data->dir_y * data->sprite_x - \
		data->dir_x * data->sprite_y);
	data->transform_y = data->inv_det * (-(data->plane_y) * \
			data->sprite_x + data->plane_x * data->sprite_y);
	data->sprite_screen_x = (int)((WIDTH / 2) * (1 + data->transform_x / \
		data->transform_y));
	data->sprite_height = abs((int)(HEIGHT / (data->transform_y)));
	data->draw_start_y = -(data->sprite_height) / 2 + HEIGHT / 2;
	if (data->draw_start_y < 0)
		data->draw_start_y = 0;
	data->draw_end_y = data->sprite_height / 2 + HEIGHT / 2;
	if (data->draw_end_y >= HEIGHT)
		data->draw_end_y = HEIGHT - 1;
	data->sprite_width = abs((int)(HEIGHT / (data->transform_y)));
	data->draw_start_x = -(data->sprite_width) / 2 + data->sprite_screen_x;
	if (data->draw_start_x < 0)
		data->draw_start_x = 0;
	data->draw_end_x = data->sprite_width / 2 + data->sprite_screen_x;
	if (data->draw_end_x >= WIDTH)
		data->draw_end_x = WIDTH - 1;
}

void	sprite_casting3(t_math_pos *data, int i)
{
	int	stripe;

	stripe = data->draw_start_x;
	while (stripe < data->draw_end_x)
	{
		data->s_tex_x = (int)(256 * (stripe - (-(data->sprite_width) / 2 + \
			data->sprite_screen_x)) * TEX_WIDTH / data->sprite_width) / 256;
		if (data->transform_y > 0 && stripe > 0 && stripe < WIDTH && \
			data->transform_y < data->z_buffer[stripe])
		{
			sprite_casting2(data, i, stripe);
		}
		stripe++;
	}
}

void	sprite_casting(t_math_pos *data, t_sprite_data *sprites)
{
	int	i;

	i = -1;
	while (++i < NUMSPRITE)
	{
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((data->pos_x - sprites[i].x) * \
			(data->pos_x - sprites[i].x) + (data->pos_y - sprites[i].y) * \
			(data->pos_y - sprites[i].y));
	}
	sort_sprites(data);
	i = -1;
	while (++i < NUMSPRITE)
	{
		sprite_casting1(data, sprites, i);
		sprite_casting3(data, i);
	}
}
