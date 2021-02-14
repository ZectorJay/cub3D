/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:29:34 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/14 14:51:46 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "dylib/mlx.h"

/*
** CHANGABLE DEFINES
*/

# define COLUMN_HEIGHT			9
# define MINI_MAP_SCALE			140
# define ROTATION_SPEED			3
# define PLAYER_SCALE			(int)(MINI_MAP_SCALE/3)
# define SPEED_NORM				MINI_MAP_SCALE * 1
# define DOUBLE_SPEED			SPEED_NORM * 1.5

/*
** ANGLE - Player view angle. M_PI/3 = 60 degree
*/

# define ANGLE					(float)M_PI/3

/*
** HIGHER QUALITY NUMBER - WORSE QUALITY OF PICTURE (AND FASTER GAME)
*/

# define QUALITY				3

/*
** DONT TOUCH THOSE
*/

# define RES_X					both->mlx.res_x
# define RES_Y	 				both->mlx.res_y
# define HRES_Y 				both->mlx.half_res_y
# define PX						both->player.x
# define PY						both->player.y
# define CONNECT				both->mlx.con
# define WIN					both->mlx.window
# define PROT					both->player.rot
# define SPEED					both->player.speedy
# define TXT					both->map.map
# define KARTA					both->map.karta
# define XSTOP					(int)(PX + PLAYER_SCALE)/MINI_MAP_SCALE
# define YSTOP					(int)(PY + PLAYER_SCALE)/MINI_MAP_SCALE
# define NUM					both->counter
# define RAYS					both->mlx.rays
# define FIX_ANGLE				(float)(ANGLE/RAYS)
# define X_STOP					(int)(OLD1/MINI_MAP_SCALE)
# define Y_STOP					(int)(OLD2/MINI_MAP_SCALE)
# define PRESS_W				both->player.move_w
# define PRESS_A				both->player.move_a
# define PRESS_S				both->player.move_s
# define PRESS_D				both->player.move_d
# define PRESS_ROT				both->player.move_rot
# define HIDE_MAP				both->map.map_hide
# define FLOOR_COLOR			both->schetchik.floor_color
# define SKY_COLOR				both->schetchik.sky_color
# define WHITE_SPACE			" \n\t\v\f\r"
# define VALID_SYMBOLS			"102"
# define OLD1					both->player.old_x
# define OLD2					both->player.old_y
# define LEVEL					both->drawing.height
# define DRAW_Y					both->drawing.y_for_me
# define DRAW_X					both->drawing.x_for_me
# define SCALER					both->drawing.scale_for_me
# define SP_COUNTER				both->schetchik.sprite_counter
# define SPR_NUM				both->get_info
# define C_COS					both->player.calc_cos
# define C_SIN					both->player.calc_sin
# define LEN_COUNTER			SPR_NUM[counter].len_counter
# define ROW_FLAG				both->schetchik.flag_color_row
# define SCREENSHOT_X			both->mlx.screenshot_x
# define SCREENSHOT_Y			both->mlx.screenshot_y
# define END					both->schetchik.end
# define WEST					both->west
# define EAST					both->east
# define NORTH					both->north
# define SOUTH					both->south
# define SPRITE					both->sprite
# define SPRITE_OLD_X			both->drawing.sprite_old_x
# define SPRITE_OLD_Y			both->drawing.sprite_old_y
# define ENDING					both->schetchik.sprite_ending
# define COUNTER_END			both->schetchik.counter_end
# define MAP_START				both->schetchik.map_start
# define COLOR_STRING			both->schetchik.color_string

typedef struct		s_mlx
{
	void			*con;
	void			*window;
	int				res_x;
	int				res_y;
	int				screenshot_x;
	int				screenshot_y;
	int				half_res_y;
	int				rays;
}					t_mlx;

typedef struct		s_minimap
{
	float			mpx;
	float			mpy;
}					t_minimap;

typedef struct		s_map
{
	int				fd;
	char			**map;
	char			**karta;
	int				map_hide;
}					t_map;

typedef	struct		s_sprite_info
{
	float			len;
	int				row_flag;
	float			f_x_hit;
	float			f_y_hit;
	int				x_hit;
	int				y_hit;
	float			first_angle;
	float			angle;
	int				rays;
	int				position;
	int				start_pos;
	int				len_counter;
}					t_sprite_info;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_drawing
{
	int				height;
	int				y_for_me;
	int				x_for_me;
	int				sprite_old_x;
	int				sprite_old_y;
	int				scale_for_me;
	float			sprite_counter;
}					t_drawing;

typedef struct		s_sprite
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	char			*path;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				color_mass[600][600];
	int				*color_row;
	float			res;
	float			fix_res_y;
	int				counter;
	float			fix_width;
}					t_sprite;

typedef struct		s_player
{
	float			x;
	float			y;
	float			old_x;
	float			old_y;
	float			calc_cos;
	float			calc_sin;
	float			rot;
	int				flag;
	int				move_w;
	int				move_a;
	int				move_s;
	int				move_d;
	int				move_rot;
	float			speedy;
	int				hight;
}					t_player;

typedef	struct		s_counters
{
	int				sprite_counter;
	int				flag_color_row;
	int				save_flag;
	int				end;
	int				floor_color;
	int				sky_color;
	float			sprite_ending;
	float			counter_end;
	char			checker;
	int				map_start;
	char			*color_string;
	int				flag;
}					t_counters;

typedef struct		s_both
{
	t_mlx			mlx;
	t_player		player;
	t_data			img;
	t_data			minimap;
	t_data			miniplayer;
	t_sprite		north;
	t_sprite		south;
	t_sprite		east;
	t_sprite		west;
	t_sprite		sprite;
	t_drawing		drawing;
	t_sprite_info	get_info[350];
	int				flag_minimap;
	int				flag_wall;
	int				flag_sprite;
	int				counter;
	t_counters		schetchik;
	t_map			map;
	float			*cos_table;
	int				save_from_crash;
	int				color;
}					t_both;

void	my_pixel_put(t_data *data, int x, int y, int color);
void	paint_move(t_both *both);
void	create_img(t_both *both, t_data *img, int size_x, int size_y);
int		check_key(int keycode, t_both *both);
int		key_release(int keycode, t_both *both);
void	error_message(char *message, t_both *both);
void	fill_map(t_both *both);
void	parse_map(t_both *both);
void	paint_square(int x, int y, t_data *img, int color);
void	player_view(t_both *both);
void	w_move(t_both *both);
void	s_move(t_both *both);
void	a_move(t_both *both);
void	d_move(t_both *both);
void	rotate_player(t_both *both);
void	player_angle(t_both *both);
void	try3d(t_both *both, float len);
void	create_minimap(t_both *both);
void	get_minimap(t_both *both);
void	get_north(t_both *both);
void	get_west(t_both *both);
void	get_east(t_both *both);
void	get_south(t_both *both);
void	get_sprite(t_both *both);
int		search_texture(t_both *both, char letter, char letter2, int i);
void	skip_spaces(t_both *both, int i, t_sprite *name);
void	check_sprite(t_both *both, float len, float angle);
void	clear_sprites(t_both *both);
void	sprite3d(t_both *both, float another_one);
void	sprite_changer(t_both *both);
void	sort_sprite(t_both *both);
void	check_sprite_row(t_both *both, float x, float y);
void	swap_sprites(t_both *both, int end, int i);
void	sprite_works(t_both *both);
void	make_screenshot(t_both *both);
void	find_texture(t_both *both);
int		check_file_name(char *file);
float	fix_sprite(t_both *both);
float	draw_left(t_both *both, float another_one, float add);
float	draw_right(t_both *both, float another_one, float add);
void	skip_steps(t_both *both, float *plus, float scale_texture);
void	get_floor_sky_colors(t_both *both);
int		find_start_pos(t_both *both, t_sprite_info *sprite);
void	find_doubles(t_both *both);
int		find_map(t_both *both);
void	map_validator(t_both *both);
void	check_around(t_both *both, int i, int j);
void	fixx_params(t_both *both);
void	check_leftovers(t_both *both, int i);
void	get_color(t_sprite *data);

#endif
