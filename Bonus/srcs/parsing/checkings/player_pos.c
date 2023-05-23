/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:46:09 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/02 19:03:43 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_pos(t_mlx *disp)
{
	int	y;
	int	x;

	y = -1;
	while (++y < disp->height_map && (disp->map)[y])
	{
		x = -1;
		while (++x < disp->length_map && (disp->map)[y][x])
		{
			if (is_in("NSEW", (disp->map)[y][x]))
				break ;
		}
		if (is_in("NSEW", (disp->map)[y][x]))
			break ;
	}
	(disp->pos)[0] = x * 10;
	(disp->pos)[1] = y * 10;
	(disp->pos)[2] = (disp->map)[y][x];
	(disp->map)[y][x] = '0';
}
