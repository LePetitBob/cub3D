/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:38:24 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/31 13:18:59 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_calloc_so(size_t nmemb, size_t size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((nmemb + 1) * size);
	if (!dest)
		return (NULL);
	while (i < (int)nmemb)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_corrector(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!is_in(str, '\n'))
		return (str);
	dest = ft_calloc_so(ft_strlen(str), 1);
	if (!dest)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	return (free(str), dest);
}

int	is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	*xpm_to_img(t_mlx *disp, char *path, t_img_data *img)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(disp->mlx, path, &img->width, &img->height);
	if (img->width != 64 || img->height != 64)
		disp->tmp = -1;
	return (ptr);
}

char	*img_add(t_img_data *img)
{
	return (mlx_get_data_addr(img->img, \
			&img->bits_per_pixel, &img->line_length, &img->endian));
}
