/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:42:10 by vduriez           #+#    #+#             */
/*   Updated: 2023/04/25 17:47:14 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_wall(int pos[2], t_mlx *disp)
{
	if (!disp->map[pos[0]][pos[1]])
		return (-1);
	if (disp->map[pos[0]][pos[1]] == '1')// TODO check if sprite ordoor too
		return (1);
	return (0);
}