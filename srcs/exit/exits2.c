/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:53:35 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/16 14:21:32 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_image2(t_mlx *disp, t_math_pos *data, t_pics_add	*walls)
{
	if (data->img.img)
		mlx_destroy_image(disp->mlx, data->img.img);
	if (walls->wall_e.img)
		mlx_destroy_image(disp->mlx, walls->wall_e.img);
	if (walls->wall_n.img)
		mlx_destroy_image(disp->mlx, walls->wall_n.img);
	if (walls->wall_s.img)
		mlx_destroy_image(disp->mlx, walls->wall_s.img);
	if (walls->wall_w.img)
		mlx_destroy_image(disp->mlx, walls->wall_w.img);
}

void	destroy_image(t_mlx *disp, t_math_pos *data, t_pics_add	*walls)
{
	if (disp->path_no)
		free(disp->path_no);
	if (disp->path_so)
		free(disp->path_so);
	if (disp->path_ea)
		free(disp->path_ea);
	if (disp->path_we)
		free(disp->path_we);
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
	destroy_image2(disp, data, walls);
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

void	ft_exit_before_map(char *strerr, t_mlx *disp)
{
	if (disp->map)
		free_tab(disp->map);
	free(disp->mapname);
	write(2, strerr, ft_strlen(strerr));
	exit(2);
}
