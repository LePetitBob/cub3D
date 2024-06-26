/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:13:02 by vduriez           #+#    #+#             */
/*   Updated: 2023/05/25 18:55:22 by vduriez          ###   ########.fr       */
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
# define MSG_AFTERMAP "Error\nThere must not be anything after the map\n"
# define MSG_RGB_INVALID "Error\nColors must be \
formated as follows :\n[0 to 255],[0 to 255],[0 to 255]\n"
# define MSG_OPEN_FAIL_MAP "Error\nFailed to open map\n"
# define MSG_OPEN_FAIL_XPM "Error\nMlx_xpm_file_to_image failed\n"
# define MSG_EXTENSION "Error\nThe map must be a\
 file with a \".cub\" extension\n"
# define MSG_ARGS "Error\n2 arguments xpected :\n$> ./cub3D map.cub\n"
# define MSG_MLX_WIN_FAIL "Error\nMlx_create_window failed\n"
# define MSG_MALLOC_FAIL "Error\nMalloc failed\n."
# define MSG_IMG_FAIL "Error\nImage Failure\n"
# define MSG_WALL_1 "Error\nBorder walls must be 1\n"
# define MSG_CHAR "Error\nCharacters must be 1 / 0 / N / S / W / E\n"

# define FOV 75

/*Speed Mac*/
// # define MOVESPEED 0.17
// # define ROTSPEED 0.2
// # define WIDTH 1200
// # define HEIGHT 800
// # define TEX_HEIGHT 64
// # define TEX_WIDTH 64

/*Speed Dell*/
# define MOVESPEED 0.05
# define ROTSPEED 0.03
# define WIDTH 1200
# define HEIGHT 800
# define TEX_HEIGHT 64
# define TEX_WIDTH 64

# define MROTSPEED 0.02
# define NUMSPRITE 3

typedef struct s_read
{
	int		index;
	int		check;
	int		read_ret;
	char	*reading;
	char	*line;
}				t_read;

typedef struct s_img_data
{
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
	t_img_data	wall;
	t_img_data	ceiling;
	t_img_data	floor;
	t_img_data	door;
	t_img_data	shrekw;
	t_img_data	berniew;
	t_img_data	s_sdk;
	t_img_data	s_sshrekf;
	t_img_data	s_scat[10];
}				t_pics_add;

typedef struct s_vec2
{
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		dx;
	double		dy;
	double		len;
	double		norm[2];
}				t_vec2;

typedef struct s_sprite_data
{
	double	x;
	double	y;
	int		texture;
}				t_sprite_data;

typedef struct s_mat_pos
{
	float			ray_dir_x0;
	float			ray_dir_x1;
	float			ray_dir_y0;
	float			ray_dir_y1;
	float			pos_z;
	float			row_distance;
	float			floor_step_x;
	float			floor_stepyy;
	float			floor_y;
	float			floor_x;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			old_dir_x;
	double			dir_y;
	double			plane_x;
	double			old_plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_x;
	double			step;
	double			tex_pos;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	double			z_buffer[WIDTH];
	double			sprite_distance[NUMSPRITE];
	int				sprite_order[NUMSPRITE];
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				cell_x;
	int				cell_y;
	int				tx;
	int				ty;
	int				tex_num;
	int				pos;
	int				tex_y;
	int				tex_x;
	int				s_tex_y;
	int				s_tex_x;
	int				s_d;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	t_img_data		*p_sprites[NUMSPRITE];
	t_img_data		*img;
	t_img_data		img_printed;
	t_sprite_data	sprites[NUMSPRITE];
	struct s_mlx	*disp;
}				t_math_pos;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*mapname;
	char		*line;
	char		*path_wall;
	char		*path_ceiling;
	char		*path_floor;
	char		*path_door;
	char		*path_shrekw;
	char		*path_berniew;
	char		*path_sdk;
	char		*path_sshrekf;
	char		*path_scat[10];
	int			pos[3];
	int			fd;
	int			length_map;
	int			height_map;
	int			player;
	int			tmp;
	int			parsing_pb;
	int			map_pb;
	int			map_begin;
	int			x_mloc;
	int			escape;
	int			right;
	int			left;
	int			forward;
	int			back;
	int			r_right;
	int			r_left;
	int			tab;
	int			cnt;
	float		shift;
	t_math_pos	*data;
	t_pics_add	*walls;
}				t_mlx;

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_free(char *s);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int n);
char			*ft_strndup(const char *s1, int size);
int				ft_atoi(const char *str);
char			**ft_split(char const *str, char c);
void			print_tab(char **map);

int				printable(char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(char *s);
int				extension_check(char *ext, char *file);
int				ft_exit_mlx(t_mlx *disp);
void			print_error(char *str);

int				is_charset(char c, char *s);
int				skip_newlines(t_mlx *disp);
int				map_closed(t_mlx *disp);
int				map_check(t_mlx *disp);
int				map_requisites(t_mlx *disp);
int				get_img_path(t_mlx *disp, int *i, int *j, char **path);
int				check_closed(t_mlx *disp, int i, int j);
void			disp_init_values(t_mlx *disp);
void			set_map(t_mlx *disp);
void			ft_exit(char *strerr);
void			reading_init(t_mlx *disp);
void			put_minimap(t_mlx *disp);
void			ft_destroy_exit(char *strerr, t_mlx *disp);
void			destroy_image(t_mlx *disp, t_math_pos *data, t_pics_add	*walls);
void			free_tab(char **map);
void			resize_map(t_mlx *disp);
t_vec2			create_vec2(int x1, int y1, int x2, int y2);
double			get_normx(int x1, int y1, int x2, int y2);
double			get_normy(int x1, int y1, int x2, int y2);

// img/create_img
void			px_put(t_img_data *img, int x, int y, int color);
int				create_image(t_mlx *map_data);
int				create_wall_images(t_mlx *disp);
unsigned int	px_ext(t_img_data *img, int x, int y);

// math/math_main
int				wall_printer(t_mlx *map_data);

// init/init
void			init_values(t_math_pos *data, t_vec2 player);
void			init_sprites(t_math_pos *data);
// void	naruto_fov(t_mlx *disp);
// void	unnaruto_fov(t_mlx *disp);

// utils/fnc_utils
char			*ft_strchr(const char *s, int c);

// math/2Dverctors
t_vec2			vec2_generating(t_mlx disp);

// math/textures
void			tex_px_inc(t_math_pos *data, \
t_pics_add *walls, t_img_data *img, int x);
void			tex_calc(t_math_pos *data);

// math/drawing
void			draw_cf(t_math_pos *data, \
t_img_data *img, t_mlx map_data, int x);
void			calc_draw_lines(t_math_pos *data);

// player/moves
int				key_hook_press(int keycode, t_mlx *disp);
int				key_hook_release(int keycode, t_mlx *disp);
int				key_apply(t_mlx *disp);

// player/rotations
void			rt_right(t_math_pos *data);
void			rt_left(t_math_pos *data);
void			mv_forward(t_mlx *disp, t_math_pos *data);
void			mv_back(t_mlx *disp, t_math_pos *data);
void			mv_left(t_mlx *disp, t_math_pos *data);
void			mv_right(t_mlx *disp, t_math_pos *data);

// utils/utils1
void			check_destroy(void *mlx, void *img);

// utils/utils
char			*ft_calloc_so(size_t nmemb, size_t size);
char			*gnl_corrector(char *str);
int				is_in(char *str, char c);
void			*xpm_to_img(t_mlx *disp, char *path, t_img_data *img);
char			*img_add(t_img_data *img);

// *********************
// *       BONUS       *
// *********************

// parsing/checkings/checks
int				can_open(t_mlx *disp);

// parsing/checkings/checks
int				initialize_map(t_mlx *disp);

// parsing/checkings/map_borders
int				borders(t_mlx *disp, int x, int y);

// parsing/checkings/player_pos
void			player_pos(t_mlx *disp);

// math/floor
int				fc_casting(t_mlx *disp, t_math_pos *data, t_img_data *img);

// math/door
void			open_door(t_mlx *disp);

// player/mouse
int				mouse_motion(int x, int y, t_mlx *disp);
void			rtm_left(t_math_pos *data);
void			rtm_right(t_math_pos *data);

// math/sprite
void			sprite_casting(t_math_pos *data, t_sprite_data *sprites);

// img/anim_sprite
void			anim_s(t_mlx *disp);

#endif
