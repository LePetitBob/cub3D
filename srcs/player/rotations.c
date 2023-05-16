/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:01:54 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/11 12:39:20 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rt_right(t_math_pos *data)
{
	data->old_dirx = data->dirx;
	data->dirx = (data->dirx) * cos(ROTSPEED) - (data->diry) * sin(ROTSPEED);
	data->diry = (data->old_dirx) * sin(ROTSPEED) + (data->diry) * \
		cos(ROTSPEED);
	data->old_planex = data->planex;
	data->planex = (data->planex) * cos(ROTSPEED) - \
		(data->planey) * sin(ROTSPEED);
	data->planey = (data->old_planex) * sin(ROTSPEED) + \
		(data->planey) * cos(ROTSPEED);
}

void	rt_left(t_math_pos *data)
{
	data->old_dirx = data->dirx;
	data->dirx = (data->dirx) * cos(-ROTSPEED) - (data->diry) * sin(-ROTSPEED);
	data->diry = (data->old_dirx) * sin(-ROTSPEED) + \
		(data->diry) * cos(-ROTSPEED);
	data->old_planex = data->planex;
	data->planex = (data->planex) * cos(-ROTSPEED) - \
		(data->planey) * sin(-ROTSPEED);
	data->planey = (data->old_planex) * sin(-ROTSPEED) + \
		(data->planey) * cos(-ROTSPEED);
}
