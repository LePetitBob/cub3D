/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dvectors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:37:10 by vduriez           #+#    #+#             */
/*   Updated: 2023/04/28 18:11:57 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vec2	create_vec2(int x1, int y1, int x2, int y2)
{
	t_vec2	res;

	res.x1 = x1;
	res.y1 = y1;
	res.x2 = x2;
	res.y2 = y2;
	res.dx = abs(x1 - x2);
	res.dy = abs(y1 - y2);
	res.len = sqrt((res.dx * res.dx) + (res.dy * res.dy));
	res.norm[0] = sqrt(1 + ((res.dy / res.dx) * (res.dy / res.dx)));
	res.norm[1] = sqrt(1 + ((res.dy / res.dx) * (res.dy / res.dx)));
	return (res);
}

void	dir_player(char d, t_vec2 *player)
{
	if (d == 'N')
	{
		player->dx = 0;
		player->dy = -1;
	}
	else if (d == 'S')
	{
		player->dx = 0;
		player->dy = 1;
	}
	else if (d == 'E')
	{
		player->dx = 1;
		player->dy = 0;
	}
	else if (d == 'S')
	{
		player->dx = -1;
		player->dy = 0;
	}
}

t_vec2	vec2_generating(t_mlx disp)
{
	t_vec2	player;

	player.x1 = (double)(disp.pos)[0] / 10 + 0.5;
	player.y1 = (double)(disp.pos)[0] / 10 + 0.5;
	dir_player((disp.pos)[2], &player);
	return (player);
}

double	get_normx(int x1, int y1, int x2, int y2)
{
	return (sqrt(1 + ((abs(y1 - y2) / abs(x1 - x2))
				* (abs(y1 - y2) / abs(x1 - x2)))));
}

double	get_normy(int x1, int y1, int x2, int y2)
{
	return (sqrt(1 + ((abs(x1 - x2) / abs(y1 - y2))
				* (abs(x1 - x2) / abs(y1 - y2)))));
}
