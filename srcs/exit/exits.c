/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:59:03 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/10 05:23:33 by vduriez          ###   ########.fr       */
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
	free(disp->mapname);
	write(2, strerr, ft_strlen(strerr));
	exit(2);
}

void	destroy_image(t_mlx *disp, t_math_pos *data, t_pics_add	*walls)
{
	if (disp->img_e)
		mlx_destroy_image(disp->mlx, disp->img_e);
	if (disp->img_w)
		mlx_destroy_image(disp->mlx, disp->img_w);
	if (disp->img_n)
		mlx_destroy_image(disp->mlx, disp->img_n);
	if (disp->img_s)
		mlx_destroy_image(disp->mlx, disp->img_s);
	if (disp->img_m)
		mlx_destroy_image(disp->mlx, disp->img_m);
	if (disp->img_p)
		mlx_destroy_image(disp->mlx, disp->img_p);
	if (disp->img_v)
		mlx_destroy_image(disp->mlx, disp->img_v);
	if (data->img.img)
		mlx_destroy_image(disp->mlx, data->img.img);
	if (walls->wallE.img)
		mlx_destroy_image(disp->mlx, walls->wallE.img);
	if (walls->wallN.img)
		mlx_destroy_image(disp->mlx, walls->wallN.img);
	if (walls->wallS.img)
		mlx_destroy_image(disp->mlx, walls->wallS.img);
	if (walls->wallW.img)
		mlx_destroy_image(disp->mlx, walls->wallW.img);
	if (disp->path_NO)
		free(disp->path_NO);
	if (disp->path_SO)
		free(disp->path_SO);
	if (disp->path_EA)
		free(disp->path_EA);
	if (disp->path_WE)
		free(disp->path_WE);
}

void	free_tab(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_parsing(t_mlx * disp)
{
	free(disp->mlx);
	free(disp->mapname);
	exit(1);
}

int	ft_exit_mlx(t_mlx *disp)
{
	destroy_image(disp, &(disp->data), &(disp->walls));
	if (disp->win)
		mlx_destroy_window(disp->mlx, disp->win);
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