/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:28:44 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/10 12:31:40 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mv_forward(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posy) + \
		(data->diry) * MOVESPEED)][(int)(data->posx)] == '0')
		data->posy += (data->diry) * MOVESPEED;
	if ((disp->map)[(int)(data->posy)][(int)((data->posx) + \
		(data->dirx) * MOVESPEED)] == '0')
		data->posx += (data->dirx) * MOVESPEED;
}

void	mv_back(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posy) - \
		(data->diry) * MOVESPEED)][(int)(data->posx)] == '0')
		data->posy -= (data->diry) * MOVESPEED;
	if ((disp->map)[(int)(data->posy)][(int)((data->posx) - \
		(data->dirx) * MOVESPEED)] == '0')
		data->posx -= (data->dirx) * MOVESPEED;
}

void	mv_left(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posy) - \
		(data->dirx) * MOVESPEED)][(int)(data->posx)] == '0')
		data->posy -= (data->dirx) * MOVESPEED;
	if ((disp->map)[(int)(data->posy)][(int)((data->posx) + \
		(data->diry) * MOVESPEED)] == '0')
		data->posx += (data->diry) * MOVESPEED;
}

void	mv_right(t_mlx *disp, t_math_pos *data)
{
	if ((disp->map)[(int)((data->posy) + \
		(data->dirx) * MOVESPEED)][(int)(data->posx)] == '0')
		data->posy += (data->dirx) * MOVESPEED;
	if ((disp->map)[(int)(data->posy)][(int)((data->posx) - \
		(data->diry) * MOVESPEED)] == '0')
		data->posx -= (data->diry) * MOVESPEED;
}

//TODO state machine and apply
int	key_hook_press(int keycode, t_mlx *disp)
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
