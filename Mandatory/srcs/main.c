/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2023/04/30 10:11:34 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	disp_set(t_mlx *disp)
{
	int		read_ret[2];
	char	*sample;

	sample = malloc(sizeof(char) * 13);
	if (!sample)
		return ;
	read_ret[1] = open(disp->mapname, O_RDONLY);
	if (!read_ret[1])
	{
		free(disp->mapname);
		ft_exit("Error\nUnable to open file\n");
	}
	read_ret[0] = read(read_ret[1], sample, 12);
	sample[11] = '\0';
	close(read_ret[1]);
	if (read_ret[0] < 12 || !printable(sample))
	{
		free(sample);
		free(disp->mapname);
		ft_exit("Error\nMap contains unfit characters\n");
	}
	free(sample);
	disp_init_values(disp);
}

void	check_setupfile_path(t_mlx *disp)
{
	int	data;

	data = 0;
	skip_newlines(disp);
	while (disp->line && data != 6)
	{
		//TODO GET ORDER HERE
		if (disp->line && is_charset(disp->line[0], "NSEWFC"))
			++data;
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	if (!disp->line || data != 6)
		ft_destroy_exit("Error\n4 textures and 2 colors are required\n", disp);
	skip_newlines(disp);
}

void	reading_init(t_mlx *disp)
{
	int	i;

	disp_set(disp);
	disp->fd = open(disp->mapname, O_RDONLY);
	if (disp->fd < 0)
		ft_destroy_exit(MSG_OPEN_FAIL_MAP, disp);
	disp->line = get_next_line(disp->fd);
	check_setupfile_path(disp);
	while (disp->line && disp->line[0] != '\n')
	{
		++i;
		if (disp->length == 0 || disp->length < ft_strlen(disp->line))
			disp->length = ft_strlen(disp->line);
		disp->height_map++;
		free(disp->line);//TODO factorize free gnl in a simple fct
		disp->line = get_next_line(disp->fd);
	}
	while (disp->line)
	{
		++i;
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	free(disp->line);
	close(disp->fd);
	disp->height = 1;
}

int		cub3D(char **av)
{
	t_mlx	disp;
	
	disp = (t_mlx){0};
	disp.mapname = ft_strdup(av[1]);
	disp.mlx = mlx_init();
	if (!map_check(&disp) || !disp.mlx)
		ft_exit_mlx(&disp);
	disp.win = mlx_new_window(disp.mlx, WIDTH,
			HEIGHT, "Triangle2D");
	if (!disp.win)
		ft_destroy_exit(MSG_MLX_WIN_FAIL, &disp);
	if (!create_wall_images(&disp, &(disp.walls)))
		ft_destroy_exit(MSG_IMG_FAIL, &disp);
	if (!create_image(&disp, &(disp.data.img)))
		ft_destroy_exit(MSG_IMG_FAIL, &disp);
	init_values(&(disp.data), vec2_generating(disp));
	mlx_loop_hook(disp.mlx, &wall_printer, &disp);
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
	if (!cub3D(av))
		return (1);
	return (0);
}