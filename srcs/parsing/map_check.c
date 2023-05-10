/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:29:46 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/10 05:28:18 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int map_closed(t_mlx *disp)
{
	int i;
	int j;

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
	return (0);
}

int map_requisites(t_mlx *disp)
{
	int i;
	int j;

	i = -1; // TODO = disp->map_begin;
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
	return (1);
}

int skip_newlines(t_mlx *disp)
{
	int i;

	i = 0;
	while (disp->line && disp->line[0] == '\n')
	{
		++i;
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	return (i);
}

int	rgb_format(char *s, int *i)
{
	int j;

	j = *i;
	while (s[*i] && is_charset(s[*i], "0123456789"))
		++*i;
	if (*i - j <= 0 || *i - j > 3)
		return (0);
	if (s[*i] == ',')
		++*i;
	else
		return (0);
	return (1);
}

int valid_color_format(char *s)
{
	int i;

	i = 0;
	if (!rgb_format(s, &i))
		return (0);
	if (!rgb_format(s, &i))
		return (0);
	if (!rgb_format(s, &i))
		return (0);
	while (s[i] && s[i] == ' ')
		++i;
	if (s[i] != '\n')
		return (0);
	return (1);
}

int get_color(t_mlx *disp, int c)
{
	char **color;
	int res[3];
	int i;

	if (!valid_color_format(disp->line + c))
		return (-1);
	color = ft_split(disp->line + c, ',');
	i = -1;
	while (++i < 3)
		res[i] = ft_atoi(color[i]);
	free_tab(color);
	i = -1;
	while (++i < 3)
	{
		if (res[i] < 0 || res[i] > 255)
			disp->parsing_pb = RGB_INVALID;
		if (res[i] < 0 || res[i] > 255)
			return (-2);
	}
	disp->height++;
	return (res[0] << 16 | res[1] << 8 | res[2]);
}

void	parse_color(t_mlx *disp, char color)
{
	int i;

	printf("is color : [%s]\n", disp->line);
	i = 1;
	while (disp->line[i] && is_charset(disp->line[i], " "))
		++i;
	if (color == 'F' )
		disp->color_f = get_color(disp, i);
	if (color == 'C')
		disp->color_c = get_color(disp, i);
}

int		error_parsing(t_mlx *disp, int imgs[2])
{
	if (imgs[0] != 4 || imgs[1] != 2)
	{
		print_error(MSG_WALL);
		ft_free_parsing(disp);
	}
	if (disp->parsing_pb == PTHMULTIDEF)
	{
		print_error(MSG_PTHMULTIDEF);
		ft_free_parsing(disp);
	}
	if (disp->parsing_pb == RGB_INVALID)
	{
		print_error(MSG_RGB_INVALID);
		ft_free_parsing(disp);
	}
	return (1);
}

int	get_data(t_mlx *disp)
{
	int imgs[2];

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
	error_parsing(disp, imgs);
	disp->height += skip_newlines(disp);
	return (1);
}

void	get_map(t_mlx *disp)
{
	int next;
	// printf("paths :\nNO : {%s}\nSO : {%s}\nWE : {%s}\nEA : {%s}\n", disp->path_NO, disp->path_SO, disp->path_WE, disp->path_EA);
	printf("f : %x\nc : %x\n", disp->color_f, disp->color_c);
	write(1, disp->line, ft_strlen(disp->line));
	while (disp->line && disp->line[0] != '\n')
	{
		if (disp->map_begin == 0)
			disp->map_begin = disp->height + 1;
		next = 0;
		if (disp->line[ft_strlen(disp->line) - 1] == '\n')
			next = 1;
		if (disp->length_map == 0 || ft_strlen(disp->line) - next > disp->length_map)
			disp->length_map = ft_strlen(disp->line) - next;
		disp->map[disp->tmp++] = ft_strndup(disp->line,
											ft_strlen(disp->line) - next);
		disp->height++;
		get_new_line(disp);
	}
	// print_tab(disp->map);
}

int		map_check(t_mlx *disp)
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
	free(disp->line);
	close(disp->fd);
	if (!map_requisites(disp))
		return (0);
	if (map_closed(disp))
		return (0);
	return (1);
}
