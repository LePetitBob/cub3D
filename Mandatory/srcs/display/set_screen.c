/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:41:38 by vduriez           #+#    #+#             */
<<<<<<< HEAD:Mandatory/srcs/display/set_screen.c
/*   Updated: 2023/05/23 00:26:55 by vduriez          ###   ########.fr       */
=======
/*   Updated: 2023/05/11 15:24:39 by vduriez          ###   ########.fr       */
>>>>>>> main:srcs/display/set_screen.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_player(t_mlx *disp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
<<<<<<< HEAD:Mandatory/srcs/display/set_screen.c
			px_put(&(disp->data.img), 10 * (int)disp->data.pos_x + i, \
				10 * (int)disp->data.pos_y + j, 0xFF0000);
=======
			px_put(&(disp->data.img), 10 * (int)disp->data.posx + i, \
				10 * (int)disp->data.posy + j, 0xFF0000);
>>>>>>> main:srcs/display/set_screen.c
	}
}

void	put_minimap(t_mlx *disp)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = -1;
	while (disp->map[++y])
	{
		x = -1;
		while (disp->map[y][++x])
		{
			if (disp->map[y][x] == '1')
			{
				i = -1;
				while (++i < 10)
				{
					j = -1;
					while (++j < 10)
						px_put(&(disp->data.img), \
							10 * x + i, 10 * y + j, 0x0000FF);
				}
			}
		}
	}
	put_player(disp);
}
