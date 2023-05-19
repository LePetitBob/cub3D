/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/19 17:29:22 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_map(t_mlx *disp)
{
	int	i;

	i = 0;
	disp->height = 1;
	disp->map = malloc(sizeof(char *) * (disp->height_map + 1));
	if (!disp->map)
	{
		print_error(MSG_MALLOC_FAIL);
		ft_free_parsing(disp);
	}
	while (i < disp->height_map)
	{
		disp->map[i] = NULL;
		++i;
	}
	disp->map[disp->height_map] = NULL;
}

int	get_img_path(t_mlx *disp, int *i, int *j, char **path)
{
	int	k;

	k = 0;
	if (*path)
	{
		disp->parsing_pb = PTHMULTIDEF;
		return (print_error(MSG_PTHMULTIDEF), 1);
	}
	while (disp->line[*i + 2] && disp->line[*i + 2] == ' ')
		++*i;
	while (disp->line[*i + *j + 2] && disp->line[*i + *j + 2] != ' '
		&& disp->line[*i + *j + 2] != '\n')
		++*j;
	while (disp->line[*i + *j + 2 + k] && disp->line[*i + *j + 2 + k] != '\n')
		++k;
	if (disp->line[*i + *j + 2 + k] == '\n')
		k = -1;
	if (!disp->line[*i + *j + 2] || disp->line[*i + *j + 2] == '\n' || k == -1)
	{
		*path = ft_strndup(disp->line + *i + 2, *j);
		return (1);
	}
	disp->parsing_pb = INDIC;
	return (0);
}

void	check_path_color(t_mlx *disp, int *imgs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (disp->line[i] && disp->line[i] == ' ')
		++i;
	if (is_charset(disp->line[i], "NSEW"))
		imgs[0] += 1;
	else if (is_charset(disp->line[i], "FC"))
		imgs[1] += 1;
	if (!ft_strncmp(disp->line + i, "NO ", 3))
		get_img_path(disp, &i, &j, &disp->path_no);
	else if (!ft_strncmp(disp->line + i, "SO ", 3))
		get_img_path(disp, &i, &j, &disp->path_so);
	else if (!ft_strncmp(disp->line + i, "WE ", 3))
		get_img_path(disp, &i, &j, &disp->path_we);
	else if (!ft_strncmp(disp->line + i, "EA ", 3))
		get_img_path(disp, &i, &j, &disp->path_ea);
	else if (!ft_strncmp(disp->line + i, "F ", 2))
		parse_color(disp, 'F');
	else if (!ft_strncmp(disp->line + i, "C ", 2))
		parse_color(disp, 'C');
	else if (disp->line[0] != '\n')
		disp->parsing_pb = INDIC;
}
