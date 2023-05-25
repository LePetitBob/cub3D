/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:51:28 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/25 16:57:08 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fc_casting_x(t_mlx *disp, t_math_pos *data, t_img_data *img, int *loc)
{
	data->cell_x = (int)(data->floor_x);
	data->cell_y = (int)(data->floor_y);
	data->tx = (int)(TEX_WIDTH * (data->floor_x - data->cell_x)) & \
		(TEX_WIDTH - 1);
	data->ty = (int)(TEX_HEIGHT * (data->floor_y - data->cell_y)) &\
		(TEX_HEIGHT - 1);
	data->floor_x += data->floor_step_x;
	data->floor_y += data->floor_stepyy;
	px_put(img, loc[1], loc[0], px_ext(&(disp->walls->floor), \
		data->tx, data->ty));
	px_put(img, loc[1], (HEIGHT - loc[0] - 1), px_ext(&(disp->walls->ceiling), \
		data->tx, data->ty));
}

int	fc_casting(t_mlx *disp, t_math_pos *data, t_img_data *img)
{
	int	loc[2];

	loc[0] = -1;
	while (++loc[0] < HEIGHT)
	{
		data->ray_dir_x0 = data->dir_x - data->plane_x;
		data->ray_dir_y0 = data->dir_y - data->plane_y;
		data->ray_dir_x1 = data->dir_x + data->plane_x;
		data->ray_dir_y1 = data->dir_y + data->plane_y;
		data->pos = loc[0] - HEIGHT / 2;
		data->pos_z = 0.5 * HEIGHT;
		data->row_distance = data->pos_z / data->pos;
		data->floor_step_x = data->row_distance * (data->ray_dir_x1 - \
		data->ray_dir_x0) / WIDTH;
		data->floor_stepyy = data->row_distance * (data->ray_dir_y1 - \
		data->ray_dir_y0) / WIDTH;
		data->floor_x = data->pos_x + data->row_distance * data->ray_dir_x0;
		data->floor_y = data->pos_y + data->row_distance * data->ray_dir_y0;
		loc[1] = -1;
		while (++loc[1] < WIDTH)
			fc_casting_x(disp, data, img, loc);
	}
	return (1);
}
