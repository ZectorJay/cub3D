/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:29:34 by hmickey           #+#    #+#             */
/*   Updated: 2021/02/03 09:27:13 by hmickey          ###   ########.fr       */
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

# define	COLUMN_HEIGHT		5
# define	RES_X				both->mlx.res_x
# define	RES_Y 				both->mlx.res_y
# define	HRES_Y 				both->mlx.half_res_y
# define	MINI_MAP_SCALE		80
# define	PLAYER_SCALE		(int)(MINI_MAP_SCALE/3)
# define 	px					both->player.x
# define	py					both->player.y
# define	connect				both->mlx.con
# define	win					both->mlx.window
# define	ROTATION_SPEED		4
# define	prot				both->player.rot
# define	pflag				both->player.flag
# define	SPEED				both->player.speedy
# define	SPEED_NORM			MINI_MAP_SCALE * 1
# define	DOUBLE_SPEED		SPEED_NORM * 1.5
# define	TXT					both->map.map
# define	KARTA				both->map.karta
# define	xstop				(int)(px + PLAYER_SCALE)/MINI_MAP_SCALE
# define	ystop				(int)(py + PLAYER_SCALE)/MINI_MAP_SCALE
# define	NUM					both->counter
# define	ANGLE				(float)M_PI/3	//60 градусов обзор
# define	RAYS				both->mlx.rays // КОЛ-ВО ЛУЧЕЙ
# define	FIX_ANGLE			(float)(ANGLE/RAYS) // ШАГ ЛУЧЕЙ
# define	x_stop				(int)(OLD1/MINI_MAP_SCALE)
# define	y_stop				(int)(OLD2/MINI_MAP_SCALE)
# define	press_w				both->player.move_w
# define	press_a				both->player.move_a
# define	press_s				both->player.move_s
# define	press_d				both->player.move_d
# define	press_rot			both->player.move_rot
# define	HIDE_MAP			both->map.map_hide
# define	FLOOR_COLOR			0x777777
# define	SKY_COLOR			0xB3FFF1
# define	white_space			" \n\t\v\f\r"
# define	OLD1				both->player.old_x
# define	OLD2				both->player.old_y
# define	LEVEL				both->drawing.height
# define	DRAW_Y				both->drawing.y_for_me
# define	DRAW_X				both->drawing.x_for_me
# define	SCALER				both->drawing.scale_for_me
# define	SP_COUNTER			both->schetchik.sprite_counter
# define	QUALITY				2		// HIGHER NUMBER - WORSE QUALITY
# define	SPR_NUM				both->get_info
# define	C_COS				both->player.calc_cos
# define	C_SIN				both->player.calc_sin
# define	LEN_COUNTER			SPR_NUM[counter].len_counter
# define	ROW_FLAG			both->schetchik.flag_color_row


typedef struct		s_mlx
{
	void			*con;
	void			*window;
	int				res_x;
	int				res_y;
	int				half_res_y;
	int				rays;
}					t_mlx;

typedef struct		s_minimap
{
	float			mpx;
	float			mpy;
}					t_minimap;


typedef struct 		s_map
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
	float			*av_len;
	float			f_x_hit;
	float			f_y_hit;
	int				x_hit;
	int				y_hit;
	float			first_angle;
	float			angle;
	int				rays;
	int				position;
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
	int				scale_for_me;
	float			sprite_counter;
}					t_drawing;


typedef struct 		s_sprite
{
    void    	    *img;
    char    	    *addr;
	int				width;
	int				height;
	char			*path;
    int				bits_per_pixel;
    int				line_length;
    int				endian;
	int				color_mass[500][500]; // ВРЕМЕННЫЙ КОСТЫЛЬ
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
}					t_counters;


typedef struct	s_both
{
	t_mlx				mlx;
	t_player			player;
	t_data				img;
	t_data				minimap;
	t_data				miniplayer;
	t_sprite			north;
	t_sprite			south;
	t_sprite			east;
	t_sprite			west;
	t_sprite			sprite;
	t_drawing			drawing;
	t_sprite_info		get_info[50];
	int					flag_minimap;
	int					flag_wall;
	int					flag_sprite;
	int					counter;
	t_counters			schetchik;
	t_map				map;
	float				*cos_table;
	int					save_from_crash;
	int					color;
}						t_both;

void	my_pixel_put(t_data *data, int x, int y, int color);
void	paint_move(t_both *both);
void	create_img(t_both *both, t_data *img, int size_x, int size_y);
int		check_key(int keycode, t_both *both);
int		key_release(int keycode, t_both *both);
void	error_message(char *message, t_both *both);
void	fill_map(t_both *both);
void	parse_map(t_both *both);
void	recieve_map(t_both *both);
void	draw_map(char **a);				// НЕ ЗАБЫТЬ УБРАТЬ!!! ТАМ ПРИНТФ!! ЪУЪ!!!
void	get_minimap(t_both *both);
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
void	get_mini_map(t_both *both);
void	get_north(t_both *both);
void	get_west(t_both *both);
void	get_east(t_both *both);
void	get_south(t_both *both);
void	get_sprite(t_both *both);
int		search_texture(t_both *both, char letter, char letter2);
void	skip_spaces(t_both *both, int i, t_sprite *name);
void	check_sprite(t_both *both, float len, float angle);
void	clear_sprites(t_both *both);
void	sprite3d(t_both *both, float another_one);
void	sprite_changer(t_both *both);
void	sort_sprite(t_both *both);
void	make_avarage_len(t_both *both);
void	check_sprite_row(t_both *both, float x, float y);
void	swap_sprites(t_both *both, int end, int i);



#endif
