/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:14:10 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 11:11:59 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	anim_s(t_mlx *disp)
{
	if (disp->cnt == 15)
		disp->data->p_sprites[0] = &disp->walls->s_scat[1];
	if (disp->cnt == 30)
		disp->data->p_sprites[0] = &disp->walls->s_scat[2];
	if (disp->cnt == 45)
		disp->data->p_sprites[0] = &disp->walls->s_scat[3];
	if (disp->cnt == 60)
		disp->data->p_sprites[0] = &disp->walls->s_scat[4];
	if (disp->cnt == 75)
		disp->data->p_sprites[0] = &disp->walls->s_scat[5];
	if (disp->cnt == 90)
		disp->data->p_sprites[0] = &disp->walls->s_scat[6];
	if (disp->cnt == 105)
		disp->data->p_sprites[0] = &disp->walls->s_scat[7];
	if (disp->cnt == 120)
		disp->data->p_sprites[0] = &disp->walls->s_scat[8];
	if (disp->cnt == 135)
		disp->data->p_sprites[0] = &disp->walls->s_scat[9];
	if (disp->cnt == 150)
		disp->data->p_sprites[0] = &disp->walls->s_scat[0];
	if (disp->cnt == 150)
		disp->cnt = 0;
	disp->cnt++;
}