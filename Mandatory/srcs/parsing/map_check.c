/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:29:46 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/25 18:27:12 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_closed(t_mlx *disp)
{
	int	i;
	int	j;

	i = 0;
	while (disp->map[i])
	{
		j = 0;
		while (disp->map[i][j])
		{
			if (!check_closed(disp, i, j))
				return (print_error(MSG_OPENMAP), 0);
			++j;
		}
		++i;
	}
	resize_map(disp);
	return (1);
}

int	map_requisites(t_mlx *disp)
{
	int	i;
	int	j;

	i = -1;
	while (disp->map[++i] && ft_strcmp(disp->map[i], "\n"))
	{
		j = -1;
		while (disp->map[i] && disp->map[i][++j])
		{
			if (!is_charset(disp->map[i][j], "01 \nNSEW"))
				return (print_error(MSG_BADMAP), 0);
			if (is_charset(disp->map[i][j], "NSEW"))
			{
				disp->pos[2] = disp->map[i][j];
				disp->pos[1] = i * 10;
				disp->pos[0] = j * 10;
				disp->map[i][j] = '0';
				disp->player++;
			}
		}
	}
	if (disp->player != 1)
		return (print_error(MSG_SPAWN_PB), 0);
	return (1);
}

int	get_data(t_mlx *disp)
{
	int	imgs[2];

	reading_init(disp);
	disp->fd = open(disp->mapname, O_RDONLY);
	if (disp->fd < 0)
		return (print_error(MSG_OPEN_FAIL_MAP), 0);
	set_map(disp);
	disp->line = get_next_line(disp->fd);
	disp->height += skip_newlines(disp);
	imgs[0] = 0;
	imgs[1] = 0;
	while (disp->line && imgs[0] + imgs[1] < 6)
	{
		check_path_color(disp, &imgs[0]);
		get_new_line(disp);
		disp->height++;
	}
	disp->imgs[0] = imgs[0];
	disp->imgs[1] = imgs[1];
	disp->height += skip_newlines(disp);
	if (disp->parsing_pb == INDIC)
		return (ft_set_exit(disp));
	return (1);
}

void	get_map(t_mlx *disp)
{
	int	next;

	while (disp->line && disp->line[0] != '\n')
	{
		if (disp->map_begin == 0)
			disp->map_begin = disp->height + 1;
		next = 0;
		if (disp->line[ft_strlen(disp->line) - 1] == '\n')
			next = 1;
		if (disp->length_map == 0
			|| ft_strlen(disp->line) - next > disp->length_map)
				disp->length_map = ft_strlen(disp->line) - next;
		disp->map[disp->tmp++] = ft_strndup(disp->line,
				ft_strlen(disp->line) - next);
		disp->height++;
		get_new_line(disp);
	}
}

int	map_check(t_mlx *disp)
{
	if (!get_data(disp))
		return (0);
	get_map(disp);
	while (disp->line)
	{
		if (ft_strcmp(disp->line, "\n"))
			ft_exit_map_read(disp);
		get_new_line(disp);
	}
	error_parsing(disp);
	free(disp->line);
	close(disp->fd);
	if (!map_requisites(disp))
		return (0);
	if (!map_closed(disp))
		return (0);
	return (1);
}
