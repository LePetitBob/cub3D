/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:29:46 by vduriez           #+#    #+#             */
/*   Updated: 2023/04/21 18:01:51 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	map_closed(t_mlx *disp)
{
	int	i;
	int	j;

	// printf("into map_closed\n");
	i = 0;
	while (disp->map[i])
	{
		j = 0;
		while (disp->map[i][j])
		{
			check_closed(disp, i, j);
			++j;
		}
		++i;
	}
	if (disp->parsing_pb != 0)
		ft_destroy_exit("Error\nPath must be defined once per textures\n", disp);
	if (disp->player != 1)
		ft_destroy_exit("Error\nThere must be exactly one spawn point\n", disp);//TODO more err msg parsing_pb
	if (disp->map_pb != 0)
		ft_destroy_exit("Error\nMap is not closed or contains wrong characters\n", disp);//TODO more err msg parsing_pb
	resize_map(disp);
}

void	map_requisites(t_mlx *disp)
{
	int	i;
	int	j;

	// printf("into map_requisites\n");
	i = -1; //TODO = disp->map_begin;
	while (disp->map[++i] && ft_strcmp(disp->map[i], "\n"))
	{
		j = -1;
		while (disp->map[i] && disp->map[i][++j])
		{
			if (!is_charset(disp->map[i][j], "01 \nNSEW"))
				disp->parsing_pb = WRCHAR;
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
	if (disp->parsing_pb != 0)
		printf("mp_chk.c -> mp_req -> prs_pb = %d\n", disp->parsing_pb);
	if (disp->parsing_pb != 0)
		ft_destroy_exit("File corrupted\nDestroy_exit map_requisites\n", disp);//TODO exit with correct message from parsing pb
}

int		skip_newlines(t_mlx *disp)
{
	int	i;

	i = 0;
	while (disp->line && disp->line[0] == '\n')
	{
		++i;
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	return (i);
}

int	valid_color_format(char *s)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(s) > 12 || ft_strlen(s) < 6)
		return (0);
	//TODO 			<func------------------------
	j = i;
	while (s[i] && is_charset(s[i], "0123456789"))
			++i;
	if (i - j <= 0 || i - j > 3)
		return (0);
	if (s[i] == ',')
		i++;
	else
		return (0);
	//TODO			 -------------------------func>
	j = i;
	while (s[i] && is_charset(s[i], "0123456789"))
			++i;
	if (i - j <= 0 || i - j > 3)
		return (0);
	if (s[i] == ',')
		i++;
	else
		return (0);
	j = i;
	while (s[i] && is_charset(s[i], "0123456789"))
			++i;
	if (i - j <= 0 || i - j > 3)
		return (0);
	return (1);
}

int get_color(t_mlx *disp, int c)
{
	char	**color;
	int		res[3];
	int		i;

	//TODO check that colors are exactly "R,G,B"
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
		{
			disp->parsing_pb = RGB_INVALID;
			return (-1);
		}
	}
	disp->height++;
	return (res[0] << 16 | res[1] << 8 | res[2]);
}

void	map_check(t_mlx *disp)
{
	//? 22 v
	int	imgs;
	int	i;
	int	next;

	reading_init(disp);
	disp->fd = open(disp->mapname, O_RDONLY);
	if (disp->fd < 0)
		ft_destroy_exit("Error\nFailed to open map_name\n", disp);
	set_map(disp);
	disp->line = get_next_line(disp->fd);
	disp->height += skip_newlines(disp);
	imgs = 0;
	while (disp->line && imgs < 4)
	{
		imgs += check_images(disp);
		free(disp->line);
		disp->line = get_next_line(disp->fd);
		disp->height++;
	}
	if (imgs != 4 || disp->parsing_pb != 0)
		ft_destroy_exit("Error\nRequires 4 textures for walls\n", disp);//TODO msg for multi def and formissig texture
	disp->height += skip_newlines(disp);
	//?     22 ^

	//?     21 v
	while (disp->line && !ft_strncmp(disp->line, "F ", 2)) // TODO make func
	{
		i = 1;
		while (disp->line[i] && is_charset(disp->line[i], " "))
			++i;
		disp->color_f = get_color(disp, i);
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	disp->height += skip_newlines(disp);
	while (disp->line && !ft_strncmp(disp->line, "C ", 2)) // TODO make func
	{
		i = 1;
		while (disp->line[i] && is_charset(disp->line[i], " "))
			++i;
		disp->color_c = get_color(disp, i);
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	if (disp->color_c < 0 || disp->color_f < 0)
		ft_destroy_exit(MSG_RGB_INVALID, disp);
	disp->height += skip_newlines(disp);
	//? 21 ^

	//? 14 v  (get "int next;")
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
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	//? 14 ^

	//? 10 v
	while (disp->line)
	{
		if (disp->map_pb == 0 && ft_strcmp(disp->line, "\n"))
		{
			printf("enf of map check, if ater map : (%s)\n", disp->line);
			disp->map_pb = AFTERMAP;
		}
		free(disp->line);
		disp->line = get_next_line(disp->fd);
	}
	//? 10 ^

	free(disp->line);
	close(disp->fd);
	//TODO clean exit with elements aftermap
	if (disp->map_pb != 0)
	{
		printf("map pb = %d\n", disp->map_pb);
		ft_destroy_exit("Error\nElements are present after the map description\n", disp);
	}
	map_requisites(disp);
	map_closed(disp);
}
