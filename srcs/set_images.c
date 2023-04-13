/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:46:33 by vduriez           #+#    #+#             */
/*   Updated: 2023/02/22 21:58:14 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extension_check(char *ext, char *file)
{
	int	j;

	j = 0;
	while (file[j])
		j++;
	if (j <= 4)
		return (0);
	j -= 4;
	if (!ft_strncmp(file + j, ext, 5) && file[j - 1] != '/')
		return (1);
	return (0);
}

void	err_img(char *msg, t_mlx *disp)
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
	write(2, msg, ft_strlen(msg));
	mlx_destroy_window(disp->mlx, disp->win);
	mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	free_tab(disp->map);
	exit(1);
}

void	sprite_check(t_mlx *disp, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY, __O_NOFOLLOW);
	if (fd < 0 || !extension_check(".xpm", path))
		err_img("Error\nSprite must be an existing .xpm file\n", disp);
	close(fd);
}

void	create_imgs(t_mlx *disp)
{
	int	img_h;
	int	img_w;

	sprite_check(disp, disp->pth_m);
	disp->img_m = mlx_xpm_file_to_image(disp->mlx, disp->pth_m,
			&img_w, &img_h);
	sprite_check(disp, disp->pth_p);
	disp->img_p = mlx_xpm_file_to_image(disp->mlx, disp->pth_p,
			&img_w, &img_h);
	sprite_check(disp, disp->pth_v);
	disp->img_v = mlx_xpm_file_to_image(disp->mlx, disp->pth_v,
			&img_w, &img_h);
	// sprite_check(disp, disp->path_NO);
	// disp->img_v = mlx_xpm_file_to_image(disp->mlx, disp->path_NO,
			// &img_w, &img_h);
	// sprite_check(disp, disp->path_SO);
	// disp->img_v = mlx_xpm_file_to_image(disp->mlx, disp->path_SO,
			// &img_w, &img_h);
	// sprite_check(disp, disp->path_WE);
	// disp->img_v = mlx_xpm_file_to_image(disp->mlx, disp->path_WE,
			// &img_w, &img_h);
	// sprite_check(disp, disp->path_EA);
	// disp->img_v = mlx_xpm_file_to_image(disp->mlx, disp->path_EA,
			// &img_w, &img_h);
}
