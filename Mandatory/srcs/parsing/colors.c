/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:59:03 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/11 14:02:13 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_format(char *s, int *i)
{
	int	j;

	j = *i;
	while (s[*i] && is_charset(s[*i], "0123456789"))
		++*i;
	if (*i - j <= 0 || *i - j > 3)
		return (0);
	if (s[*i] == ',')
		++*i;
	return (1);
}

int	valid_color_format(char *s)
{
	int	i;

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

int	get_color(t_mlx *disp, int c)
{
	char	**color;
	int		res[3];
	int		i;

	if (!valid_color_format(disp->line + c))
		return (-2);
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
	int	i;

	i = 1;
	while (disp->line[i] && is_charset(disp->line[i], " "))
		++i;
	if (color == 'F' )
		disp->color_f = get_color(disp, i);
	if (color == 'C')
		disp->color_c = get_color(disp, i);
}
