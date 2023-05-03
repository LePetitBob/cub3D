/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:28:44 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/03 04:34:00 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mv_forward(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posY) + \
		(data->dirY) * MOVESPEED)][(int)(data->posX)] == '0')
		data->posY += (data->dirY) * MOVESPEED;
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) + \
		(data->dirX) * MOVESPEED)] == '0')
		data->posX += (data->dirX) * MOVESPEED;
}

void	mv_back(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posY) - \
		(data->dirY) * MOVESPEED)][(int)(data->posX)] == '0')
		data->posY -= (data->dirY) * MOVESPEED;
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) - \
		(data->dirX) * MOVESPEED)] == '0')
		data->posX -= (data->dirX) * MOVESPEED;
}

void	mv_left(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posY) - \
		(data->dirX) * MOVESPEED)][(int)(data->posX)] == '0')
		data->posY -= (data->dirX) * MOVESPEED;
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) + \
		(data->dirY) * MOVESPEED)] == '0')
		data->posX += (data->dirY) * MOVESPEED;
}

void	mv_right(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posY) + \
		(data->dirX) * MOVESPEED)][(int)(data->posX)] == '0')
		data->posY += (data->dirX) * MOVESPEED;
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) - \
		(data->dirY) * MOVESPEED)] == '0')
		data->posX -= (data->dirY) * MOVESPEED;
}

int	key_hook(int keycode, t_mlx *disp)
{
	put_minimap(disp);
	if (keycode == XK_Escape)
		ft_exit_mlx(disp);
	if (keycode == XK_a)
		mv_left(disp, &(disp->data));
	if (keycode == XK_w)
		mv_forward(disp, &(disp->data));
	if (keycode == XK_d)
		mv_right(disp, &(disp->data));
	if (keycode == XK_s)
		mv_back(disp, &(disp->data));
	if (keycode == XK_Left)
		rt_left(&(disp->data));
	if (keycode == XK_Right)
		rt_right(&(disp->data));
	return (0);
}
