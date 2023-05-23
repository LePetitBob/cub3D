/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:45:29 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/23 05:11:01 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_apply(t_mlx *disp)
{	
	if (disp->left == 1)
		mv_left(disp, disp->data);
	if (disp->forward == 1)
		mv_forward(disp, disp->data);
	if (disp->right == 1)
		mv_right(disp, disp->data);
	if (disp->back == 1)
		mv_back(disp, disp->data);
	if (disp->r_left == 1)
		rt_left(disp->data);
	if (disp->r_right == 1)
		rt_right(disp->data);
	return (0);
}

int	key_hook_press(int keycode, t_mlx *disp)
{
	if (keycode == XK_Escape)
		ft_exit_mlx(disp);
	if (keycode == XK_a)
		disp->left = 1;
	if (keycode == XK_w)
		disp->forward = 1;
	if (keycode == XK_d)
		disp->right = 1;
	if (keycode == XK_s)
		disp->back = 1;
	if (keycode == XK_Left)
		disp->r_left = 1;
	if (keycode == XK_Right)
		disp->r_right = 1;
	if (keycode == XK_Tab)
		disp->tab = 1;
	if (keycode == XK_e)
		open_door(disp);
	return (0);
}

int	key_hook_release(int keycode, t_mlx *disp)
{
	if (keycode == XK_a)
		disp->left = 0;
	if (keycode == XK_w)
		disp->forward = 0;
	if (keycode == XK_d)
		disp->right = 0;
	if (keycode == XK_s)
		disp->back = 0;
	if (keycode == XK_Left)
		disp->r_left = 0;
	if (keycode == XK_Right)
		disp->r_right = 0;
	if (keycode == XK_Tab)
		disp->tab = 0;
	return (0);
}
