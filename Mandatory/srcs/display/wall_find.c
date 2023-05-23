/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:42:10 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/03 02:10:50 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_wall_or_door_or_sprite(char c)
{
	if (c && (c == '1' || c == '2' || c == '3'))
		return (1);
	return (0);
}

int	is_wall(int pos[2], t_mlx *disp)
{
	if (!disp->map[pos[0]][pos[1]])
		return (-1);
	if (is_wall_or_door_or_sprite(disp->map[pos[0]][pos[1]]))
		return (1);
	return (0);
}
