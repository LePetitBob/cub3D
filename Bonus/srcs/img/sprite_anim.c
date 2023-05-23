/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:14:10 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/23 14:54:25 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	anim_s(t_mlx *disp)
{
	int	i;

	i = 8;
	if (disp->cnt == i)
		disp->data->p_sprites[0] = &disp->walls->s_scat[1];
	if (disp->cnt == i * 2)
		disp->data->p_sprites[0] = &disp->walls->s_scat[2];
	if (disp->cnt == i * 3)
		disp->data->p_sprites[0] = &disp->walls->s_scat[3];
	if (disp->cnt == i * 4)
		disp->data->p_sprites[0] = &disp->walls->s_scat[4];
	if (disp->cnt == i * 5)
		disp->data->p_sprites[0] = &disp->walls->s_scat[5];
	if (disp->cnt == i * 6)
		disp->data->p_sprites[0] = &disp->walls->s_scat[6];
	if (disp->cnt == i * 7)
		disp->data->p_sprites[0] = &disp->walls->s_scat[7];
	if (disp->cnt == i * 8)
		disp->data->p_sprites[0] = &disp->walls->s_scat[8];
	if (disp->cnt == i * 9)
		disp->data->p_sprites[0] = &disp->walls->s_scat[9];
	if (disp->cnt == i * 10)
		disp->data->p_sprites[0] = &disp->walls->s_scat[0];
	if (disp->cnt == i * 10)
		disp->cnt = 0;
	disp->cnt++;
}