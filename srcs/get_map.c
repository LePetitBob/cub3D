/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2023/02/23 06:06:29 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_map(t_mlx *disp)
{
	disp->height = 1;
	disp->map = malloc(sizeof(char *) * (disp->height_map + 1));
	if (!disp->map)
		return ;
	disp->map[disp->height_map] = NULL;
}

void	disp_init_values(t_mlx *disp)
{
	disp->line = NULL;
	disp->path_NO = NULL;
	disp->path_SO = NULL;
	disp->path_WE = NULL;
	disp->path_EA = NULL;
	disp->pth_m = "./images/bs10.xpm";
	disp->pth_p = "./images/rs10.xpm";
	disp->pth_v = "./images/nothingness10.xpm";
	disp->player = 0;
	disp->height = 1;
	disp->length = 0;
	disp->length_map = 0;
	disp->height_map = 0;
	disp->tmp = 0;
	disp->is_floor = 0;
	disp->is_ceiling = 0;
	disp->parsing_pb = 0;
	disp->map_pb = 0;
	disp->map_begin = 0;
}

int		get_img_path(t_mlx *disp, int *i, int *j, char **path)
{
	if (*path)
	{
		disp->parsing_pb = PTHMULTIDEF;
		return (1);
	}
	while (disp->line[*i + 2] && disp->line[*i + 2] == ' ')
		++*i;
	while (disp->line[*i + *j + 2] && disp->line[*i + *j + 2] != ' ' && disp->line[*i + *j + 2] != '\n')
		++*j;
	if (!disp->line[*i + *j + 2] || disp->line[*i + *j + 2] == '\n')
	{
		*path = ft_strndup(disp->line + *i + 2, *j - 1);
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

