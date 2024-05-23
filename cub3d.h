/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:07:35 by burkaya           #+#    #+#             */
/*   Updated: 2024/05/23 19:30:31 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53
# define E_KEY 14
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define TILE_SIZE 16
# define TOTAL_RAYS 1280
# define PLAYER_SIZE 5
# define TOTAL_TEXTURES 14
# define SCREENHEIGHT 512
# define SCREENWIDTH 1280
# define MINIMAPWIDTH 7
# define MINIMAPHEIGHT 7

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef int	t_bool;

typedef struct s_map
{
	int		map_x;
	int		map_y;
	int		map_s;
	char	**floor;
	char	**ceiling;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	char	**flood_fill;
	char	**wall_textures;
	char 	*floor_str;
	char 	*ceiling_str;
	char	*map_str;
}				t_map;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			key_w;
	int			key_s;
	int			key_left;
	int			key_right;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	int			map_x;
	int			map_y;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	int			wall;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			tex_x;
	int			texnum;
	double		texstep;
	double		texpos;
	int			key_a;
	int			key_d;
	int			user_x;
	int			user_y;
}	t_ray;

typedef struct s_images
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_images;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			*mlx_o_data;
	char		*map_path;
	int			map_fd;
	t_bool		w_pressed;
	t_bool		a_pressed;
	t_bool		s_pressed;
	t_bool		d_pressed;
	t_bool		e_pressed;
	t_bool		is_door_open;
	t_bool		left_pressed;
	t_bool		right_pressed;
	t_map		*map;
	t_ray		*ray;
	t_images	**images;
}				t_data;

/* CHECK */
int			check_extension(char *file);
int			ft_check_input(t_data *data, char **argv);
void		ft_check_map(t_data *data);

/* DRAW */
void		ft_ray_casting(t_data *data);
void		ft_direction(t_data *data);
void		ft_check_wallhit(t_data *data);
void		ft_wallhit(t_data *data);
void		ft_raydist(t_data *data);
void		ft_send_ray(t_data *data, int x);
void		ft_wall_check(t_data *data);
void		ft_wall_check1(t_data *data);
void		ft_send_ray_for_sp(t_data *data, int x, int i);

/* INIT */
void		ft_create_map(t_data *data);
void		ft_free_images(t_data *data, int max);
void		ft_init_ray(t_ray *ray);
void		ft_load_image(t_data *data, char *texture, int index);
int			ft_init_image_array(t_data *data);
int			ft_create_main_image(t_data *data);
int			ft_init_images(t_data *data);
int			ft_init(t_data *data);
void		ft_load_other_images(t_data *data, int i);
void		ft_load_image(t_data *data, char *texture, int index);
int			ft_load_walls(t_data *data, char *texture, int index);

/* MLX */
int			ft_exit(void *param);
int			key_hook(void *param);
int			key_pressed(int keycode, void *param);
int			key_released(int keycode, void *param);
void		ft_draw_square_on_coords(t_data *data, int x, int y, int color);

/* MOVE */
int			is_character(char c, t_data *data);
void		key_w(t_data *data);
void		key_s(t_data *data);
void		key_d(t_data *data);
void		key_a(t_data *data);
void		key_left(t_data *data);
void		key_right(t_data *data);
void		ft_move(t_data *data);
int			ft_player_move(t_data *data);

/* RENDER */
void		ft_fill_pixel(t_data *data, int x, int y, char type);
void		ft_render_map(t_data *data, int render_fc);

/* TEXTURE */

void		ft_texture_helper(t_data *data);
void		ft_draw_wall_texture(t_data *data, int x, int tex_index);
void		ft_draw_wall_side(t_data *data, int x, int f_flag);
void		ft_texture(t_data *data, int x, int f_flag);

/* UTILS */
void		ft_fill_floor_and_ceiling(t_data *data);
int			ft_tab_len(char **tab);
char		**ft_split_new_lines(char const *s);

/* MAIN */
void		ft_set_direction(t_data *data, char c);
void		ft_set_plane(t_data *data, char c);
void		ft_get_direction(t_data *data, char c);
void		ft_get_player_location(t_data *data);

#endif