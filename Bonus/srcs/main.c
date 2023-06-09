/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/25 17:51:29 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init(t_mlx *disp, t_math_pos *data, t_pics_add *walls, t_img_data *img)
{
	disp->shift = 1;
	disp->data = data;
	data->disp = disp;
	disp->walls = walls;
	disp->data->img = img;
	disp->path_wall = "images/wall.xpm";
	disp->path_ceiling = "images/ceiling.xpm";
	disp->path_floor = "images/floor.xpm";
	disp->path_door = "images/door.xpm";
	disp->path_shrekw = "images/shrekw.xpm";
	disp->path_sshrekf = "images/sshrekf.xpm";
	disp->path_sdk = "images/sdk.xpm";
	disp->path_berniew = "images/berniew.xpm";
	init_sprites(data);
	data->p_sprites[0] = &disp->walls->s_scat[0];
	data->p_sprites[1] = &disp->walls->s_sdk;
	data->p_sprites[2] = &disp->walls->s_sshrekf;
	disp->x_mloc = WIDTH / 2;
}

void	start_loop(t_mlx *disp)
{
	mlx_mouse_hide(disp->mlx, disp->win);
	mlx_loop_hook(disp->mlx, wall_printer, disp);
	mlx_hook(disp->win, MotionNotify, PointerMotionMask, mouse_motion, disp);
	mlx_hook(disp->win, KeyPress, KeyPressMask, \
		key_hook_press, disp);
	mlx_hook(disp->win, KeyRelease, KeyReleaseMask, \
		key_hook_release, disp);
	mlx_hook(disp->win, 17, 1L << 17, ft_exit_mlx, disp);
	mlx_loop(disp->mlx);
}

int	cub3d(char **av)
{
	t_mlx		disp;
	t_math_pos	data;
	t_pics_add	walls;
	t_img_data	img;

	disp = (t_mlx){0};
	data = (t_math_pos){0};
	walls = (t_pics_add){0};
	img = (t_img_data){0};
	disp.mapname = ft_strdup(av[1]);
	init(&disp, &data, &walls, &img);
	if (!disp.mapname)
		return (print_error(MSG_MALLOC_FAIL), 0);
	disp.mlx = mlx_init();
	if (!map_check(&disp) || !disp.mlx)
		ft_exit_mlx(&disp);
	disp.win = mlx_new_window(disp.mlx, WIDTH,
			HEIGHT, "Triangle2D");
	if (!disp.win)
		ft_destroy_exit(MSG_MLX_WIN_FAIL, &disp);
	if (!create_wall_images(&disp) ||!create_image(&disp))
		ft_destroy_exit(MSG_IMG_FAIL, &disp);
	init_values(&data, vec2_generating(disp));
	start_loop(&disp);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (print_error(MSG_ARGS), 1);
	if (!extension_check(".cub", av[1]))
		return (print_error(MSG_EXTENSION), 1);
	if (!cub3d(av))
		return (1);
	return (0);
}
