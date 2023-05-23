/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:54:20 by user42            #+#    #+#             */
/*   Updated: 2022/12/07 18:33:35 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_read	ft_indexnl(char *reading, t_read newline)
{
	int	i;

	i = -1;
	while (reading[++i])
	{
		if (reading[i] == '\n')
		{
			newline.check = 1;
			newline.index = i;
			return (newline);
		}
	}
	newline.index = i;
	return (newline);
}

t_read	ft_initnl(char *reste)
{
	int		i;
	t_read	newline;

	i = -1;
	if (reste != NULL)
	{
		while (reste[++i])
		{
			if (reste[i] == '\n')
			{
				newline.index = i;
				newline.check = 1;
				return (newline);
			}
		}
	}
	newline.index = 0;
	newline.check = 0;
	newline.read_ret = 1;
	return (newline);
}

char	*ft_getline(char *reste, t_read newline)
{
	int		i;
	char	*line;

	i = -1;
	if (newline.check == 1)
	{
		line = malloc(sizeof(char) * (newline.index + 2));
		if (!line)
			return (NULL);
		while (++i <= newline.index)
			line[i] = reste[i];
		line[i] = 0;
		return (line);
	}
	line = ft_strdup(reste);
	return (line);
}

char	*ft_getreste(char *reste, t_read newline)
{
	int		i;
	int		j;
	char	*recup;

	if (newline.check == 1 && reste[newline.index] == '\n')
	{
		i = ft_strlen(reste);
		recup = malloc(i - (newline.check + newline.index) + 1);
		if (!recup)
			return (NULL);
		j = 0;
		i = newline.index + newline.check;
		while (reste[i])
		{
			recup[j] = reste[i];
			i++;
			j++;
		}
		recup[j] = 0;
		free(reste);
		return (recup);
	}
	free(reste);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*reste = NULL;
	t_read		newline;

	newline = ft_initnl(reste);
	while (newline.check == 0 && newline.read_ret > 0)
	{
		newline.reading = malloc(sizeof(char) * (1023 + 1));
		if (!newline.reading)
			return (NULL);
		newline.read_ret = read(fd, newline.reading, 1023);
		newline.reading[1023] = 0;
		if (newline.read_ret >= 0)
			newline.reading[newline.read_ret] = 0;
		if (newline.read_ret == -1)
			return (ft_free(newline.reading));
		reste = ft_strjoin(reste, newline.reading);
		free(newline.reading);
		newline = ft_indexnl(reste, newline);
	}
	newline.line = ft_getline(reste, newline);
	reste = ft_getreste(reste, newline);
	if (newline.line[0] == 0)
		return (ft_free(newline.line));
	return (newline.line);
}
