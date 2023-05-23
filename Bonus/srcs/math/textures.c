/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:45:19 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 18:10:14 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	tex_px_inc(t_math_pos *data, t_pics_add *walls, t_img_data *img, int x)
{
	int	y;

	data->step = 1.0 * texHeight / (data->line_height);
	data->tex_pos = ((data->draw_start) - HEIGHT / 2 + \
		(data->line_height) / 2) * (data->step);
	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)(data->tex_pos) & (texHeight - 1);
		data->tex_pos += data->step;
		if (data->disp->map[data->map_y][data->map_x] == '1')
		{
			if (data->side == 1 && data->ray_dir_y < 0)
				px_put(img, x, y, px_ext(&(walls->wall), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x > 0)
				px_put(img, x, y, px_ext(&(walls->wall), data->tex_x, data->tex_y));
			else if (data->side == 1 && data->ray_dir_y > 0)
				px_put(img, x, y, px_ext(&(walls->wall), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x < 0)
				px_put(img, x, y, px_ext(&(walls->wall), data->tex_x, data->tex_y));
		}
		else if (data->disp->map[data->map_y][data->map_x] == 'F')
		{
			if (data->side == 1 && data->ray_dir_y < 0)
				px_put(img, x, y, px_ext(&(walls->door), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x > 0)
				px_put(img, x, y, px_ext(&(walls->door), data->tex_x, data->tex_y));
			else if (data->side == 1 && data->ray_dir_y > 0)
				px_put(img, x, y, px_ext(&(walls->door), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x < 0)
				px_put(img, x, y, px_ext(&(walls->door), data->tex_x, data->tex_y));
		}
		else if (data->disp->map[data->map_y][data->map_x] == '2')
		{
			if (data->side == 1 && data->ray_dir_y < 0)
				px_put(img, x, y, px_ext(&(walls->shrekw), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x > 0)
				px_put(img, x, y, px_ext(&(walls->shrekw), data->tex_x, data->tex_y));
			else if (data->side == 1 && data->ray_dir_y > 0)
				px_put(img, x, y, px_ext(&(walls->shrekw), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x < 0)
				px_put(img, x, y, px_ext(&(walls->shrekw), data->tex_x, data->tex_y));
		}
		else if (data->disp->map[data->map_y][data->map_x] == '3')
		{
			if (data->side == 1 && data->ray_dir_y < 0)
				px_put(img, x, y, px_ext(&(walls->berniew), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x > 0)
				px_put(img, x, y, px_ext(&(walls->berniew), data->tex_x, data->tex_y));
			else if (data->side == 1 && data->ray_dir_y > 0)
				px_put(img, x, y, px_ext(&(walls->berniew), data->tex_x, data->tex_y));
			else if (data->side == 0 && data->ray_dir_x < 0)
				px_put(img, x, y, px_ext(&(walls->berniew), data->tex_x, data->tex_y));
		}
		y++;
	}
}

void	tex_calc(t_math_pos *data)
{
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor((data->wall_x));
	data->tex_x = (int)((data->wall_x) * (double)texWidth);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = texWidth - (data->tex_x) - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = texWidth - (data->tex_x) - 1;
}
