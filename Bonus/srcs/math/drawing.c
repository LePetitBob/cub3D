/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:47:19 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 02:29:06 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_draw_lines(t_math_pos *data)
{
	if (!(data)->side)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(HEIGHT / data->perp_wall_dist);
	data->draw_start = (-(data->line_height)) / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT -1;
}

void	copy_img_add(t_img_data	*img, t_img_data *img_printed)
{
	img_printed->img = img->img;
}
