/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:59:03 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/25 18:41:42 by vduriez          ###   ########.fr       */
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
	destroy_image(disp, &(disp->data), &(disp->walls));
	if (disp->map)
		free_tab(disp->map);
	if (disp->mlx)
	{
		mlx_destroy_display(disp->mlx);
		free(disp->mlx);
	}
	free(disp->mapname);
	write(2, strerr, ft_strlen(strerr));
	exit(2);
}

void	ft_free_parsing(t_mlx *disp)
{
	destroy_image(disp, &(disp->data), &(disp->walls));
	free(disp->mlx);
	if (disp->map)
		free_tab(disp->map);
	free(disp->mapname);
	exit(1);
}

int	ft_exit_mlx(t_mlx *disp)
{
	destroy_image(disp, &(disp->data), &(disp->walls));
	if (disp->win)
		mlx_destroy_window(disp->mlx, disp->win);
	if (disp->mlx)
		mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	free_tab(disp->map);
	free(disp->mapname);
	exit(1);
}

void	ft_exit_map_read(t_mlx *disp)
{
	print_error(MSG_AFTERMAP);
	while (disp->line)
		get_new_line(disp);
	ft_exit_mlx(disp);
}
