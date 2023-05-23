/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:59:03 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/23 03:47:05 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_exit(char *strerr)
{
	write(2, strerr, ft_strlen(strerr));
	exit(2);
}

void	ft_destroy_exit(char *strerr, t_mlx *disp)
{
	destroy_image(disp, disp->data, disp->walls);
	if (disp->map)
		free_tab(disp->map);
	free(disp->mapname);
	write(2, strerr, ft_strlen(strerr));
	exit(2);
}

void	destroy_image(t_mlx *disp, t_math_pos *data, t_pics_add	*walls)
{
	if (data->img->img)
		mlx_destroy_image(disp->mlx, data->img->img);
	if (walls->wall.img)
		mlx_destroy_image(disp->mlx, walls->wall.img);
}

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int	ft_exit_mlx(t_mlx *disp)
{
	destroy_image(disp, disp->data, disp->walls);
	mlx_destroy_window(disp->mlx, disp->win);
	mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	free_tab(disp->map);
	free(disp->mapname);
	exit(1);
}