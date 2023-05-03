/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:41:38 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/03 04:38:12 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_minimap(t_mlx *disp)
{
	int	i;
	int	j;

	i = 0;
	create_imgs(disp);
	while (disp->map[i])
	{
		j = 0;
		while (disp->map[i][j])
		{
			if (disp->map[i][j] == '1')
				mlx_put_image_to_window(disp->mlx, disp->win
					, disp->img_m, j * 10, i * 10);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img_p,
			disp->pos[0], disp->pos[1]);
}
