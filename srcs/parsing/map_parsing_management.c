/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:33 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/10 12:12:22 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	skip_newlines(t_mlx *disp)
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

int	error_parsing(t_mlx *disp, int imgs[2])
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

int	printable(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i])
	{
		if (s[i] != '\n' && s[i] < 32)
			return (0);
		i++;
	}
	return (1);
}
