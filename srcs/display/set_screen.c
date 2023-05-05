/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:41:38 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/05 14:59:34 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_minimap(t_mlx *disp)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = -1;
	// create_imgs(disp); //! TODO REMOVE
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
						px_put(&(disp->data.img), 10 * x + i, 10 * y + j, 255);
				}
			}
		}
	}
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			px_put(&(disp->data.img), 10 * (int)disp->data.posX + i, 10 * (int)disp->data.posY + j, 0xFF0000);
	}
}
