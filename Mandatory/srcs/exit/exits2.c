/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
<<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
/*   Created: 2023/05/10 11:53:35 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/16 18:05:42 by vduriez          ###   ########.fr       */
========
/*   Created: 2022/12/05 17:59:03 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/16 18:06:44 by vduriez          ###   ########.fr       */
>>>>>>>> main:srcs/exit/exits.c
=======
/*   Created: 2023/05/10 11:53:35 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/16 18:05:42 by vduriez          ###   ########.fr       */
>>>>>>> main:srcs/exit/exits2.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_image2(t_mlx *disp, t_math_pos *data, t_pics_add	*walls)
{
<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
<<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
=======
>>>>>>> main:srcs/exit/exits2.c
	if (data->img.img)
		mlx_destroy_image(disp->mlx, data->img.img);
	if (walls->wall_e.img)
		mlx_destroy_image(disp->mlx, walls->wall_e.img);
	if (walls->wall_n.img)
		mlx_destroy_image(disp->mlx, walls->wall_n.img);
	if (walls->wall_s.img)
		mlx_destroy_image(disp->mlx, walls->wall_s.img);
	if (walls->wall_w.img)
		mlx_destroy_image(disp->mlx, walls->wall_w.img);
<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
========
	write(2, strerr, ft_strlen(strerr));
	exit(2);
}

void	ft_destroy_exit(char *strerr, t_mlx *disp)
{
	destroy_image(disp, &(disp->data), &(disp->walls));
	if (disp->map)
		free_tab(disp->map);
	if (disp->mlx)
	{
		mlx_destroy_display(disp->mlx);
		free(disp->mlx);
	}
	free(disp->mapname);
	write(2, strerr, ft_strlen(strerr));
	exit(2);
>>>>>>>> main:srcs/exit/exits.c
}

void	ft_free_parsing(t_mlx *disp)
{
<<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
=======
}

void	destroy_image(t_mlx *disp, t_math_pos *data, t_pics_add	*walls)
{
>>>>>>> main:srcs/exit/exits2.c
	if (disp->path_no)
		free(disp->path_no);
	if (disp->path_so)
		free(disp->path_so);
	if (disp->path_ea)
		free(disp->path_ea);
	if (disp->path_we)
		free(disp->path_we);
	if (disp->img_e)
		mlx_destroy_image(disp->mlx, disp->img_e);
	if (disp->img_w)
		mlx_destroy_image(disp->mlx, disp->img_w);
	if (disp->img_n)
		mlx_destroy_image(disp->mlx, disp->img_n);
	if (disp->img_s)
		mlx_destroy_image(disp->mlx, disp->img_s);
	if (disp->img_m)
		mlx_destroy_image(disp->mlx, disp->img_m);
	if (disp->img_p)
		mlx_destroy_image(disp->mlx, disp->img_p);
	if (disp->img_v)
		mlx_destroy_image(disp->mlx, disp->img_v);
	destroy_image2(disp, data, walls);
}

void	free_tab(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
========
	destroy_image(disp, &(disp->data), &(disp->walls));
	free(disp->mlx);
	if (disp->map)
		free_tab(disp->map);
	free(disp->mapname);
	exit(1);
>>>>>>>> main:srcs/exit/exits.c
=======
>>>>>>> main:srcs/exit/exits2.c
}

void	ft_exit_before_map(char *strerr, t_mlx *disp)
{
<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
<<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
=======
>>>>>>> main:srcs/exit/exits2.c
	if (disp->map)
		free_tab(disp->map);
	free(disp->mapname);
	write(2, strerr, ft_strlen(strerr));
	exit(2);
<<<<<<< HEAD:Mandatory/srcs/exit/exits2.c
========
	destroy_image(disp, &(disp->data), &(disp->walls));
	if (disp->win)
		mlx_destroy_window(disp->mlx, disp->win);
	if (disp->mlx)
		mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	free_tab(disp->map);
	free(disp->mapname);
	exit(1);
}

void	ft_exit_map_read(t_mlx *disp)
{
	print_error(MSG_AFTERMAP);
	while (disp->line)
		get_new_line(disp);
	ft_exit_mlx(disp);
>>>>>>>> main:srcs/exit/exits.c
=======
>>>>>>> main:srcs/exit/exits2.c
}
