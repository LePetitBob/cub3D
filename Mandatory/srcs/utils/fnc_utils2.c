/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:41:27 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/31 14:06:59 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*xpm_to_img(t_mlx *disp, char *path, t_img_data *wall)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(disp->mlx, path,
			&wall->width, &wall->height);
	if (wall->width != 64 || wall->height != 64)
		disp->tmp = -1;
	return (ptr);
}
