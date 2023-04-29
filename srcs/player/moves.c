/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:28:44 by ajeanne           #+#    #+#             */
/*   Updated: 2023/04/29 19:35:16 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mv_forward(t_mlx *disp, t_math_pos *data)
{
	
	if ((disp->map)[(int)((data->posY) + (data->dirY) * MOVESPEED)][(int)(data->posX)] == '0')
		data->posY += (data->dirY) * MOVESPEED;
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) + (data->dirX) * MOVESPEED)] == '0')
		data->posX += (data->dirX) * MOVESPEED;
}

void	mv_back(t_mlx *disp, t_math_pos *data)
{
	
	if ((disp->map)[(int)((data->posY) - (data->dirY) * MOVESPEED)][(int)(data->posX)] == '0')
		data->posY -= (data->dirY) * MOVESPEED;
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) - (data->dirX) * MOVESPEED)] == '0')
		data->posX -= (data->dirX) * MOVESPEED;
}

void	mv_left(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posY) - (data->dirX) * MOVESPEED)][(int)(data->posX)] == '0')
	{
		data->posY -= (data->dirX) * MOVESPEED;
	}
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) + (data->dirY) * MOVESPEED)] == '0')
		data->posX += (data->dirY) * MOVESPEED;
}

void	mv_right(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posY) + (data->dirX) * MOVESPEED)][(int)(data->posX)] == '0')
		data->posY += (data->dirX) * MOVESPEED;
	if ((disp->map)[(int)(data->posY)][(int)((data->posX) - (data->dirY) * MOVESPEED)] == '0')
		data->posX -= (data->dirY) * MOVESPEED;
}

void	rt_right(t_math_pos *data)
{
	data->oldDirX = data->dirX;
	data->dirX = (data->dirX) * cos(ROTSPEED) - (data->dirY) * sin(ROTSPEED);
	data->dirY = (data->oldDirX) * sin(ROTSPEED) + (data->dirY) * cos(ROTSPEED);
	data->oldPlaneX = data->planeX;
	data->planeX = (data->planeX) * cos(ROTSPEED) - (data->planeY) * sin(ROTSPEED);
	data->planeY = (data->oldPlaneX) * sin(ROTSPEED) + (data->planeY) * cos(ROTSPEED);
}

void	rt_left(t_math_pos *data)
{
	data->oldDirX = data->dirX;
	data->dirX = (data->dirX) * cos(-ROTSPEED) - (data->dirY) * sin(-ROTSPEED);
	data->dirY = (data->oldDirX) * sin(-ROTSPEED) + (data->dirY) * cos(-ROTSPEED);
	data->oldPlaneX = data->planeX;
	data->planeX = (data->planeX) * cos(-ROTSPEED) - (data->planeY) * sin(-ROTSPEED);
	data->planeY = (data->oldPlaneX) * sin(-ROTSPEED) + (data->planeY) * cos(-ROTSPEED);
}

int	key_hook(int keycode, t_mlx *disp)
{
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

// int	key_hook(int keycode, t_mlx *disp)
// {
// 	if (keycode == XK_Escape)
// 		ft_exit_mlx(disp);
// 	if (keycode == XK_a)
// 		disp->pos[0] -= MOVESPEED;//TODO set moves and rot
// 	if (keycode == XK_w)
// 		mv_forward(disp, &(disp->data));
// 	if (keycode == XK_d)
// 		disp->pos[0] += MOVESPEED;
// 	if (keycode == XK_s)
// 		disp->pos[1] += MOVESPEED;
	// if (keycode == XK_Left)
	// 	disp->pos[2] -= ROTSPEED;
	// if (keycode == XK_Right)
	// 	disp->pos[2] += ROTSPEED;
// 	mlx_clear_window(disp->mlx, disp->win);
// 	put_minimap(disp);
// 	return (0);
// }