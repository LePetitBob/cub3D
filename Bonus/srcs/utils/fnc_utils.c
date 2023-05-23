/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:00:30 by ajeanne           #+#    #+#             */
/*   Updated: 2023/05/02 18:43:19 by ajeanne          ###   ########.fr       */
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
