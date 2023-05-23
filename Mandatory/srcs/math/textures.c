/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:45:19 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 00:26:55 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	tex_px_inc(t_math_pos *data, t_pics_add *walls, t_img_data *img, int x)
{
	int	y;

	data->step = 1.0 * TEX_HEIGHT / (data->line_height);
	data->tex_pos = ((data->draw_start) - HEIGHT / 2 + \
		(data->line_height) / 2) * (data->step);
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->texy = (int)(data->tex_pos) & (TEX_HEIGHT - 1);
		data->tex_pos += data->step;
		if (data->side == 1 && data->ray_dir_y < 0)
			px_put(img, x, y, px_ext(&(walls->wall_n), data->texx, data->texy));
		else if (data->side == 0 && data->ray_dir > 0)
			px_put(img, x, y, px_ext(&(walls->wall_e), data->texx, data->texy));
		else if (data->side == 1 && data->ray_dir_y > 0)
			px_put(img, x, y, px_ext(&(walls->wall_s), data->texx, data->texy));
		else if (data->side == 0 && data->ray_dir < 0)
			px_put(img, x, y, px_ext(&(walls->wall_w), data->texx, data->texy));
		y++;
	}
}

void	tex_calc(t_math_pos *data)
{
	if (data->side == 0)
		data->wallx = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wallx = data->pos_x + data->perp_wall_dist * data->ray_dir;
	data->wallx -= floor((data->wallx));
	data->texx = (int)((data->wallx) * (double)TEX_WIDTH);
	if (data->side == 0 && data->ray_dir > 0)
		data->texx = TEX_WIDTH - (data->texx) - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->texx = TEX_WIDTH - (data->texx) - 1;
}
