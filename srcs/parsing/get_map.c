/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/03 03:15:14 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_map(t_mlx *disp)
{
	disp->height = 1;
	disp->map = malloc(sizeof(char *) * (disp->height_map + 1));
	if (!disp->map)
		ft_destroy_exit(MSG_MALLOC_FAIL, disp);
	disp->map[disp->height_map] = NULL;
}

int		get_img_path(t_mlx *disp, int *i, int *j, char **path)
{
	if (*path)
	{
		disp->parsing_pb = PTHMULTIDEF;
		return (dprintf(2, MSG_PTHMULTIDEF), 1);
	}
	while (disp->line[*i + 2] && disp->line[*i + 2] == ' ')
		++*i;
	while (disp->line[*i + *j + 2] && disp->line[*i + *j + 2] != ' ' && disp->line[*i + *j + 2] != '\n')
		++*j;
	if (!disp->line[*i + *j + 2] || disp->line[*i + *j + 2] == '\n')
	{
		*path = ft_strndup(disp->line + *i + 2, *j);
		return (1);
	}
	return (0);
}

int		check_images(t_mlx *disp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ft_strncmp(disp->line + i, "NO ", 3))
		return (get_img_path(disp, &i, &j, &disp->path_NO));
	else if (!ft_strncmp(disp->line + i, "SO ", 3))
		return (get_img_path(disp, &i, &j, &disp->path_SO));
	else if (!ft_strncmp(disp->line + i, "WE ", 3))
		return (get_img_path(disp, &i, &j, &disp->path_WE));
	else if (!ft_strncmp(disp->line + i, "EA ", 3))
		return (get_img_path(disp, &i, &j, &disp->path_EA));
	return (0);
}
