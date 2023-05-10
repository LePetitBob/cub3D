/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:13:02 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/10 12:49:44 by vduriez          ###   ########.fr       */
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
# define WALL -2
# define PTHMULTIDEF -3
# define BADMAP -4
# define SPAWN_PB -5
# define AFTERMAP -6
# define RGB_INVALID  -7
# define OPEN_FAIL_MAP  -8
# define OPEN_FAIL_XPM  -9

# define MSG_PATH "Error\nSprite must be an existing .xpm file\n"
# define MSG_WALL "Error\nRequires 4 textures for walls\n"
# define MSG_PTHMULTIDEF "Error\nPath must be defined once per textures\n"
# define MSG_BADMAP "Error\nMap contains wrong characters\n"
# define MSG_OPENMAP "Error\nMap is not closed\n"
# define MSG_SPAWN_PB "Error\nThere must be exactly one spawn point\n"
# define MSG_AFTERMAP "Error\nThere must not\
	 be anything after the map\n"
# define MSG_RGB_INVALID "Error\nColors must\
	 be formated as follows :\n[0 to 255],[0 to 255],[0 to 255]\n"
# define MSG_OPEN_FAIL_MAP "Error\nFailed ot open map\n"
# define MSG_OPEN_FAIL_XPM "Error\nMlx_xpm_file_to_image failed\n"
# define MSG_EXTENSION "Error\nThe map must be a file with a \".cub\" extension\n"
# define MSG_ARGS "Error\n2 arguments xpected :\n$> ./cub3D map.cub\n"
# define MSG_MLX_WIN_FAIL "Error\nMlx_create_window failed\n"
# define MSG_MALLOC_FAIL "Error\nMalloc failed\n."
# define MSG_IMG_FAIL "Error\nImage Failure\n"

# define FOV 75
# define MOVESPEED 0.2
# define ROTSPEED 0.032724923
# define WIDTH 1200
# define HEIGHT 800
# define TEX_HEIGHT 64
# define TEX_WIDTH 64

typedef struct s_read
{
	int		index;
	int		check;
	int		read_ret;
	char	*reading;
	char	*line;
}				t_read;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img_data;

typedef struct s_pics_add
{
	t_img_data	wall_n;
	t_img_data	wall_s;
	t_img_data	wall_e;
	t_img_data	wall_w;
}				t_pics_add;

typedef struct s_vec2
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	dx;
	double	dy;
	double	len;
	double	norm[2];
}				t_vec2;

typedef struct s_mat_pos
{
	double		posx;
	double		posy;
	double		dirx;
	double		old_dirx;
	double		diry;
	double		planex;
	double		old_planex;
	double		planey;
	double		camerax;
	double		ray_dir;
	double		ray_diry;
	double		side_distx;
	double		side_disty;
	double		delta_distx;
	double		delta_disty;
	double		perp_wall_dist;
	double		wallx;
	double		step;
	double		tex_pos;
	int			texy;
	int			texx;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	t_img_data	img;
	t_img_data	img_printed;
}				t_math_pos;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*mapname;
	char		*line;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*pth_m;
	char		*pth_p;
	char		*pth_v;
	void		*img_m;
	void		*img_v;
	void		*img_p;
	void		*img_e;
	void		*img_w;
	void		*img_n;
	void		*img_s;
	int			pos[3];
	int			is_floor;
	int			is_ceiling;
	int			color_f;
	int			color_c;
	int			fd;
	int			length;
	int			length_map;
	int			height;
	int			height_map;
	int			player;
	int			tmp;
	int			parsing_pb;
	int			map_begin;
	t_math_pos	data;
	t_pics_add	walls;
}				t_mlx;
	/* int		escape; */
	/* int		right; */
	/* int		left; */
	/* int		forward; */
	/* int		back; */
	/* int		r_right; */
	/* int		r_left; */
	/*player pos, [0] = x, [1] = y, [2] = dir */

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_free(char *s);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int n);
char			*ft_strndup(const char *s1, int size);
int				ft_atoi(const char *str);
char			**ft_split(char const *str, char c);

int				printable(char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(char *s);
int				ft_exit_mlx(t_mlx *disp);
void			print_error(char *str);

int				is_charset(char c, char *s);
int				skip_newlines(t_mlx *disp);
int				map_closed(t_mlx *disp);
int				map_check(t_mlx *disp);
int				map_requisites(t_mlx *disp);
int				get_img_path(t_mlx *disp, int *i, int *j, char **path);
int				check_closed(t_mlx *disp, int i, int j);
int				error_parsing(t_mlx *disp, int imgs[2]);
int				get_data(t_mlx *disp);
void			ft_exit_map_read(t_mlx *disp);
void			disp_init_values(t_mlx *disp);
void			set_map(t_mlx *disp);
void			ft_problems(t_mlx *disp);
void			ft_exit(char *strerr);
void			reading_init(t_mlx *disp);
void			ft_destroy_exit(char *strerr, t_mlx *disp);
void			destroy_image(t_mlx *disp, t_math_pos *data, t_pics_add	*walls);
void			destroy_image2(t_mlx *disp, \
	t_math_pos *data, t_pics_add	*walls);
void			free_tab(char **map);
void			resize_map(t_mlx *disp);
void			parse_color(t_mlx *disp, char color);
void			get_map(t_mlx *disp);
void			get_new_line(t_mlx *disp);
void			check_path_color(t_mlx *disp, int *imgs);
t_vec2			create_vec2(int x1, int y1, int x2, int y2);
double			get_normx(int x1, int y1, int x2, int y2);
double			get_normy(int x1, int y1, int x2, int y2);
int				rgb_format(char *s, int *i);
void			ft_free_parsing(t_mlx *disp);

/* display/set_screen */
void			put_minimap(t_mlx *disp);

/* display/set_images */
int				extension_check(char *ext, char *file);
void			err_img(char *msg, t_mlx *disp);

/* display/wall_find */
int				is_wall_or_door_or_sprite(char c);
int				is_wall(int pos[2], t_mlx *disp);

/* img/create_img */
void			px_put(t_img_data *img, int x, int y, int color);
int				create_image(t_mlx *map_data, t_img_data *img);
int				create_wall_images(t_mlx *disp, t_pics_add *walls);
unsigned int	px_ext(t_img_data *img, int x, int y);

/* math/math_main */
int				wall_printer(t_mlx *map_data);

/* init/init */
void			init_values(t_math_pos *data, t_vec2 player);

/* utils/fnc_utils */
char			*ft_strchr(const char *s, int c);

/* math/2Dverctors */
t_vec2			vec2_generating(t_mlx disp);

/* math/textures */
void			tex_px_inc(t_math_pos *data, \
	t_pics_add *walls, t_img_data *img, int x);
void			tex_calc(t_math_pos *data);

/* math/drawing */
void			draw_cf(t_math_pos *data, t_img_data *img, \
	t_mlx map_data, int x);
void			calc_draw_lines(t_math_pos *data);

/* player/moves */
int				key_hook_press(int keycode, t_mlx *disp);

/* player/rotations */
void			rt_right(t_math_pos *data);
void			rt_left(t_math_pos *data);

#endif