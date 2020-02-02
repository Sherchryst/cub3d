/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 03:52:33 by sgah              #+#    #+#             */
/*   Updated: 2020/02/02 00:37:28 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <fmod.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define PLAYER_SPEED 0.1
# define ROTATE_SPEED 3.0
# define RAYS 200.0
# define FOV 45.0
# define JUMP_HEIGHT 10.0
# ifndef INF
#  define INF 100000000.0
# endif

typedef struct		s_raycasting_data {
	int				i;
	int				res;
	int				d;
	int				x;
	int				y;
	int				a;
}					t_raycasting_data;

typedef struct		s_rect
{
	int				x;
	int				y;
	int				width;
	int				height;
}					t_rect;

typedef struct		s_texture
{
	int				width;
	int				height;
	char			*filename;
	void			*ptr;
	char			*data;
}					t_texture;

typedef struct		s_sprite
{
	int				two;
	int				x;
	int				y;
	float			sprite_x;
	float			sprite_y;
	float			dir_x;
	float			dir_y;
	float			inv_det;
	float			transform_x;
	float			transform_y;
	int				sprite_screen_x;
	int				sprite_width;
	int				sprite_height;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
	unsigned char	color[4];
	int				texture_x;
	int				texture_y;
	t_texture		*sprite;
}					t_sprite;

typedef struct		s_ray
{
	float			angle;
	t_texture		*texture;
	float			distance;
	float			side_dist_x;
	float			side_dist_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			ray_dir_x;
	float			ray_dir_y;
	float			step_x;
	float			step_y;
	float			wall_x;
	int				map_x;
	int				map_y;
}					t_ray;

typedef struct		s_keys
{
	int				k_up;
	int				k_down;
	int				k_left;
	int				k_right;
	int				k_a;
	int				k_s;
	int				k_d;
	int				k_w;
}					t_keys;

typedef struct		s_window
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*surface;
	char			*data;
	unsigned int	width;
	unsigned int	height;
	const char		*title;
}					t_window;

typedef struct		s_world
{
	float			angle;
	int				**map;
	t_ray			**rays;
	int				mx;
	int				my;
	float			px;
	float			py;
	float			pz;
	float			jump_time;
	t_texture		*o;
	t_texture		*e;
	t_texture		*s;
	t_texture		*n;
	t_texture		*sprite;
	t_texture		*sprite2;
	t_texture		*sprite3;
	unsigned char	color_ceil[4];
	unsigned char	color_ground[4];
	t_list			*sprites;
	float			plane_x;
	float			plane_y;
}					t_world;

typedef struct		s_god
{
	t_window		*window;
	t_world			*world;
	t_keys			*keys;
	FMOD_SYSTEM		*system;
	FMOD_SOUND		*j;
	int				screenshot;
	void			(*draw)(struct s_god *);
}					t_god;

typedef struct		s_cub
{
	void			*mlx_tmp;
	t_texture		*e;
	t_texture		*w;
	t_texture		*n;
	t_texture		*s;
	t_texture		*sprite;
	t_texture		*sprite2;
	t_texture		*sprite3;
	t_list			*map_tmp;
	int				**map;
	int				width;
	int				height;
	int				map_width;
	int				map_height;
	int				px;
	int				py;
	char			orientation;
	unsigned char	ceil[3];
	unsigned char	floor[3];
	int				map_started;
	int				p;
	int				sp;
	int				started;
}					t_cub;

t_texture			*sprites(int x, int y, t_cub *info);
void				set_color(unsigned char color[4], unsigned char r,
					unsigned char j, unsigned char b);
t_texture			*load_texture(void *mlx_ptr, char *filename);
void				parse_info(char *line, t_cub *info);
void				parsing_map(char *line, t_cub *info);
int					check_parsing(t_cub *info);
void				parsing(char *line, t_cub *info);
t_cub				*parser(char *file);
void				clean_info(t_cub *info);
void				parserror(t_cub *info);
void				print_info(t_cub *info);
int					check_map(t_cub *info);
void				create_map(t_cub *info);
void				parse_resolution(char *line, t_cub *info);
void				parse_texture(char *line, t_cub *info);
void				parse_color(char *line, t_cub *info);
t_ray				**create_ray_array(float angle);
t_god				*creation(t_cub *info);
t_world				*create_world(t_cub *info);
void				destroy_sprite(void *content);
t_keys				*create_keys(void);
t_window			*create_window(t_cub *info, t_god *game);
void				stop_game(t_god *game);
int					key_released(int key, void *game);
int					key_pressed(int key, void *game);
int					program_exited(void *game);
int					loop_hook(void *param);
float				mod(float a, float b);
void				destroy_texture(void *mlx_ptr, t_texture *texture);
void				get_pixel_color(t_texture *texture, int x, int y,
					unsigned char *result);
void				free_ray_array(t_ray **rays);
void				free_2d_array(int **array, int x);
void				draw_game(t_god *game);
void				update(t_god *game);
int					min(int a, int b);
int					max(int a, int b);
float				dist(float a, float b, float x, float y);
float				deg_to_rad(float a);
void				draw_rect(t_window *window, t_rect rect,
					unsigned char color[4]);
void				rotate_ray_array(t_ray **rays, float angle);
void				rotate(t_god *game, int direction);
void				go(t_god *game, int direction);
void				draw_hud(t_god *game);
void				draw_sprites(t_god *game);
void				draw_rays(t_god *game);
void				raycast(t_world *world);
t_list				*create_sprites_array(t_cub *info);
void				draw_pixel(t_window *window, unsigned int x, unsigned int y,
					unsigned char color[4]);
int					get_nth_pixel_distance(t_god *game, int screen_x);
void				jump(t_god *game);
void				update_jump(t_god *game);
int					screenshot(t_god *game);
void				int_to_char(int n, unsigned char *src);
int					get_pixel(t_window *window, unsigned int x, unsigned int y);
void				draw_minimap(t_god *game);

#endif
