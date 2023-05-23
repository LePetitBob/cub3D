/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:56:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 04:19:25 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dda_loop(t_math_pos *data, t_mlx *map_data)
{
	while (!(data)->hit)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (map_data->map[data->map_y][data->map_x] == '1'
			|| map_data->map[data->map_y][data->map_x] == 'F')
			data->hit = 1;
	}
}

void	calc_stepydist(t_math_pos *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
	}
}

void	avoid_div_0(t_math_pos *data)
{
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
}

void	cam_dir_val(t_math_pos *data, int x)
{
	data->camera_x = 2 * x / (double)(WIDTH) - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)(data->pos_x);
	data->map_y = (int)(data->pos_y);
}

int	wall_printer(t_mlx *map_data)
{
	int			x;

	x = 0;
	key_apply(map_data);
	fc_casting(map_data, map_data->data, map_data->data->img);
	while (x < WIDTH)
	{
		cam_dir_val(map_data->data, x);
		avoid_div_0(map_data->data);
		calc_stepydist(map_data->data);
		dda_loop(map_data->data, map_data);
		calc_draw_lines(map_data->data);
		tex_calc(map_data->data);
		tex_px_inc(map_data->data, map_data->walls,
			map_data->data->img, x);
		x++;
	}
	if (map_data->tab == 1)
		put_minimap(map_data);
	mlx_put_image_to_window(map_data->mlx, map_data->win,
		map_data->data->img->img, 0, 0);
	return (0);
}
