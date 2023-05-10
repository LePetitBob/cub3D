/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:56:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/10 12:37:36 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dda_loop(t_math_pos *data, t_mlx *map_data)
{
	while (!(data)->hit)
	{
		if (data->side_distx < data->side_disty)
		{
			data->side_distx += data->delta_distx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->side_disty += data->delta_disty;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (map_data->map[data->mapy][data->mapx] == '1')
			data->hit = 1;
	}
}

void	calc_step_dist(t_math_pos *data)
{
	if (data->ray_dir < 0)
	{
		data->stepx = -1;
		data->side_distx = (data->posx - data->mapx) * data->delta_distx;
	}
	else
	{
		data->stepx = 1;
		data->side_distx = (data->mapx + 1.0 - data->posx) * data->delta_distx;
	}
	if (data->ray_diry < 0)
	{
		data->stepy = -1;
		data->side_disty = (data->posy - data->mapy) * data->delta_disty;
	}
	else
	{
		data->stepy = 1;
		data->side_disty = (data->mapy + 1.0 - data->posy) * data->delta_disty;
	}
}

void	avoid_div_0(t_math_pos *data)
{
	data->delta_distx = fabs(1 / data->ray_dir);
	data->delta_disty = fabs(1 / data->ray_diry);
	data->hit = 0;
}

void	cam_dir_val(t_math_pos *data, int x)
{
	data->camerax = 2 * x / (double)(WIDTH) - 1;
	data->ray_dir = data->dirx + data->planex * data->camerax;
	data->ray_diry = data->diry + data->planey * data->camerax;
	data->mapx = (int)(data->posx);
	data->mapy = (int)(data->posy);
}

	/* to put above mlx_put_img_to_win
	put_minimap(map_data);
	*/
int	wall_printer(t_mlx *map_data)
{
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		cam_dir_val(&(map_data->data), x);
		avoid_div_0(&(map_data->data));
		calc_step_dist(&(map_data->data));
		dda_loop(&(map_data->data), map_data);
		calc_draw_lines(&(map_data->data));
		tex_calc(&(map_data->data));
		tex_px_inc(&(map_data->data), &(map_data->walls),
			&(map_data->data.img), x);
		draw_cf(&(map_data->data), &(map_data->data.img), *map_data, x);
		x++;
	}
	mlx_put_image_to_window(map_data->mlx, map_data->win,
		map_data->data.img.img, 0, 0);
	return (0);
}
