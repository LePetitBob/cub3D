/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:52:15 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/25 18:13:35 by vduriez          ###   ########.fr       */
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

int	block_wrong_file(char *str, t_mlx *disp)
{
	while (is_in(" ", *str))
		str++;
	if (*str != '1')
	{
		while (str)
		{
			free(str);
			str = get_next_line(disp->fd);
		}
		return (print_error(MSG_BADMAP), 0);
	}
	return (1);
}

int	set_map_data(t_mlx *disp)
{
	char	*str;

	disp->height_map = 0;
	disp->length_map = 0;
	str = gnl_corrector(get_next_line(disp->fd));
	if (!str)
		return (print_error(MSG_BADMAP), 0);
	if (!block_wrong_file(str, disp))
		return (0);
	while (str)
	{
		(disp->height_map)++;
		if (disp->length_map < ft_strlen(str) + 1)
			disp->length_map = ft_strlen(str) + 1;
		free(str);
		str = gnl_corrector(get_next_line(disp->fd));
	}
	if (close(disp->fd) == -1)
		return (print_error(MSG_OPENMAP), 0);
	if (!initialize_map(disp))
		return (0);
	return (1);
}

int	can_open(t_mlx *disp)
{
	disp->fd = open(disp->mapname, O_RDONLY);
	if (disp->fd == -1)
		return (print_error(MSG_OPEN_FAIL_MAP), 0);
	if (!set_map_data(disp))
		return (0);
	return (1);
}
