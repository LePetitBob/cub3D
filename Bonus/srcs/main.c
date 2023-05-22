/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/05 18:00:27 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cub3d(char **av)
{
	t_mlx	disp;
	t_math_pos	data;

	disp = (t_mlx){0};
	disp.data = &data;
	disp.mapname = ft_strdup(av[1]);
	if (!disp.mapname)
		return (print_error(MSG_MALLOC_FAIL), 0);
	disp.mlx = mlx_init();
	if (!map_check(&disp) || !disp.mlx)
		ft_exit_mlx(&disp);
	disp.win = mlx_new_window(disp.mlx, WIDTH,
			HEIGHT, "Triangle2D");
	if (!disp.win)
		ft_destroy_exit(MSG_MLX_WIN_FAIL, &disp);
	disp.path_wall = "images/wall.xpm";
	disp.path_ceiling = "images/ceiling.xpm";
	disp.path_floor = "images/floor.xpm";
	disp.x_mloc = 600;
	if (!create_wall_images(&disp))
		ft_destroy_exit(MSG_IMG_FAIL, &disp);
	if (!create_image(&disp))
		ft_destroy_exit(MSG_IMG_FAIL, &disp);
	init_values(&data, vec2_generating(disp));
	mlx_loop_hook(disp.mlx, wall_printer, &disp);
	mlx_mouse_hide(disp.mlx, disp.win);
	mlx_hook(disp.win, MotionNotify, PointerMotionMask, mouse_motion, &disp);
	mlx_hook(disp.win, 2, 1L << 0, key_hook, &disp);
	mlx_hook(disp.win, 17, 1L << 17, ft_exit_mlx, &disp);
	mlx_loop(disp.mlx);
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