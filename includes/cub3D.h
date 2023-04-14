/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:13:02 by vduriez           #+#    #+#             */
/*   Updated: 2023/04/14 17:58:08 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define PATH -1
# define PTHMULTIDEF -2
# define CLOSED -3
# define WRCHAR -4
# define SPAWN_PB -5
# define AFTERMAP -6
# define RGB_INVALID -7

# define MSG_PATH -1
# define MSG_PTHMULTIDEF -2
# define MSG_CLOSED -3
# define MSG_WRCHAR -4
# define MSG_SPAWN_PB -5
# define MSG_AFTERMAP -6
# define MSG_RGB_INVALID "Error\nColors must be formated as follows :\n[0 to 255],[0 to 255],[0 to 255]\n"

# define FOV 90
# define MOVESPEED 1
# define ROTSPEED 1

typedef struct s_mat_pos
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	
}				t_math_pos;

typedef struct s_read
{
	int		index;
	int		check;
	int		read_ret;
	char	*reading;
	char	*line;
}				t_read;

typedef struct s_vec2
{
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		dx;
	double		dy;
	double	len;
	double	norm[2];
}				t_vec2;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*mapname;
	char	*line;
	char	*path_NO;
	char	*path_SO;
	char	*path_WE;
	char	*path_EA;
	char	*pth_m; //wall blocks for minimap
	char	*pth_p; //player block for minimap
	char	*pth_v; //minimap void
	void	*img_m;
	void	*img_v;
	void	*img_p;
	void	*img_e;
	void	*img_w;
	void	*img_n;
	void	*img_s;
	int		pos[3];	//player pos, [0] = x, [1] = y, [2] = dir
	int		is_floor;
	int		is_ceiling;
	int		color_f;
	int		color_c;
	int		fd;
	int		length;
	int		length_map;
	int		height;
	int		height_map;
	int		player;
	int		tmp;
	int		parsing_pb;
	int		map_pb;
	int		map_begin;
}				t_mlx;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char *s);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strndup(const char *s1, int size);
int		ft_atoi(const char *str);
char	**ft_split(char const *str, char c);

int		printable(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
int		extension_check(char *ext, char *file);
int		ft_exit_mlx(t_mlx *disp);
int		ft_exit_close(t_mlx *disp);

int		skip_newlines(t_mlx *disp);
void	disp_init_values(t_mlx *disp);
void	map_check(t_mlx *disp);
void	set_map(t_mlx *disp);
void	map_requisites(t_mlx *disp);
void	map_closed(t_mlx *disp);
int		check_images(t_mlx *disp);
int		get_img_path(t_mlx *disp, int *i, int *j, char **path);
void	ft_problems(t_mlx *disp);
void	ft_exit(char *strerr);
void	reading_init(t_mlx *disp);
void	err_img(char *msg, t_mlx *disp);
void	sprite_check(t_mlx *disp, char *path);
void	create_imgs(t_mlx *disp);
void	put_minimap(t_mlx *disp);
void	ft_destroy_exit(char *strerr, t_mlx *disp);
void	destroy_image(t_mlx *disp);
void	free_tab(char **map);
void	resize_map(t_mlx *disp);
int		is_charset(char c, char *s);
void	check_closed(t_mlx *disp, int i, int j);
t_vec2	create_vec2(int x1, int y1, int x2, int y2);
double	get_normx(int x1, int y1, int x2, int y2);
double	get_normy(int x1, int y1, int x2, int y2);

//TODO --> remove
void	print_tab(char **map);

#endif