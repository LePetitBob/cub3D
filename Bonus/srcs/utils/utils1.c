/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:31:51 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/25 16:56:14 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	check_destroy(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}
