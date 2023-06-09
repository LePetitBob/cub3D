/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:47:19 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/10 12:39:33 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_cf(t_math_pos *data, t_img_data *img, t_mlx map_data, int x)
{
	int	y;

	y = 0;
	while (y < data->draw_start)
	{
		px_put(img, x, y, map_data.color_c);
		y++;
	}
	y = data->draw_end;
	while (y < HEIGHT - 1)
	{
		px_put(img, x, y, map_data.color_f);
		y++;
	}
}

void	calc_draw_lines(t_math_pos *data)
{
	if (!(data)->side)
		data->perp_wall_dist = (data->side_distx - data->delta_distx);
	else
		data->perp_wall_dist = (data->side_disty - data->delta_disty);
	data->line_height = (int)(HEIGHT / data->perp_wall_dist);
	data->draw_start = (-(data->line_height)) / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT -1;
}

// void	copy_img_add(t_img_data	*img, t_img_data *img_printed)
// {
// 	img_printed->img = img->img;
// }