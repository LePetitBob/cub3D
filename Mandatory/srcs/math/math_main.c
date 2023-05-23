/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:56:15 by ajeanne           #+#    #+#             */
<<<<<<< HEAD:Mandatory/srcs/math/math_main.c
/*   Updated: 2023/05/23 00:38:11 by vduriez          ###   ########.fr       */
=======
/*   Updated: 2023/05/22 21:58:25 by vduriez          ###   ########.fr       */
>>>>>>> main:srcs/math/math_main.c
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
<<<<<<< HEAD:Mandatory/srcs/math/math_main.c
			data->mapy += data->stepyy;
=======
			data->mapy += data->stepy;
>>>>>>> main:srcs/math/math_main.c
			data->side = 1;
		}
		if (map_data->map[data->mapy][data->mapx] == '1')
			data->hit = 1;
	}
}

void	calc_stepydist(t_math_pos *data)
{
	if (data->ray_dir < 0)
	{
		data->stepx = -1;
<<<<<<< HEAD:Mandatory/srcs/math/math_main.c
		data->side_distx = (data->pos_x - data->mapx) * data->delta_distx;
=======
		data->side_distx = (data->posx - data->mapx) * data->delta_distx;
>>>>>>> main:srcs/math/math_main.c
	}
	else
	{
		data->stepx = 1;
<<<<<<< HEAD:Mandatory/srcs/math/math_main.c
		data->side_distx = (data->mapx + 1.0 - data->pos_x) * data->delta_distx;
	}
	if (data->ray_dir_y < 0)
	{
		data->stepyy = -1;
		data->side_disty = (data->pos_y - data->mapy) * data->delta_disty;
	}
	else
	{
		data->stepyy = 1;
		data->side_disty = (data->mapy + 1.0 - data->pos_y) * data->delta_disty;
=======
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
>>>>>>> main:srcs/math/math_main.c
	}
}

void	avoid_div_0(t_math_pos *data)
{
	data->delta_distx = fabs(1 / data->ray_dir);
<<<<<<< HEAD:Mandatory/srcs/math/math_main.c
	data->delta_disty = fabs(1 / data->ray_dir_y);
=======
	data->delta_disty = fabs(1 / data->ray_diry);
>>>>>>> main:srcs/math/math_main.c
	data->hit = 0;
}

void	cam_dir_val(t_math_pos *data, int x)
{
	data->camerax = 2 * x / (double)(WIDTH) - 1;
<<<<<<< HEAD:Mandatory/srcs/math/math_main.c
	data->ray_dir = data->dir_x + data->plane_x * data->camerax;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camerax;
	data->mapx = (int)(data->pos_x);
	data->mapy = (int)(data->pos_y);
=======
	data->ray_dir = data->dirx + data->planex * data->camerax;
	data->ray_diry = data->diry + data->planey * data->camerax;
	data->mapx = (int)(data->posx);
	data->mapy = (int)(data->posy);
>>>>>>> main:srcs/math/math_main.c
}

int	wall_printer(t_mlx *map_data)
{
	int			x;

	x = 0;
	key_apply(map_data);
	while (x < WIDTH)
	{
		cam_dir_val(&(map_data->data), x);
		avoid_div_0(&(map_data->data));
		calc_stepydist(&(map_data->data));
		dda_loop(&(map_data->data), map_data);
		calc_draw_lines(&(map_data->data));
		tex_calc(&(map_data->data));
		tex_px_inc(&(map_data->data), &(map_data->walls),
			&(map_data->data.img), x);
		draw_cf(&(map_data->data), &(map_data->data.img), *map_data, x);
		x++;
	}
<<<<<<< HEAD:Mandatory/srcs/math/math_main.c
	if (map_data->tab == -1)
=======
	if (map_data->tab == 1)
>>>>>>> main:srcs/math/math_main.c
		put_minimap(map_data);
	mlx_put_image_to_window(map_data->mlx, map_data->win,
		map_data->data.img.img, 0, 0);
	return (0);
}
