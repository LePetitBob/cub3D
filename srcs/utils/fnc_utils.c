/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:00:30 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/05 16:11:33 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c_tmp;

	c_tmp = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_tmp)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	get_new_line(t_mlx *disp)
{
	free(disp->line);
	disp->line = get_next_line(disp->fd);
}