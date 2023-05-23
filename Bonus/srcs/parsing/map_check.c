/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:29:46 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/02 18:57:46 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_check(t_mlx *disp)
{
	if (!can_open(disp))
		return (print_error("FAILED\n"), 0);
	player_pos(disp);
	return (print_error("OK\n"), 1);
}
