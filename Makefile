# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 15:52:53 by hmickey           #+#    #+#              #
#    Updated: 2021/02/14 18:05:04 by hmickey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	сub3D

INCLUDE		=	./cub3d.h get_next_line/get_next_line.h mlx/mlx.h dylib/mlx.h

PATH_CONF	=	./src/parse_config/

PATH_GNL	=	./get_next_line/

PATH_IMG	=	./src/create_img/

PATH_PLAYER	=	./src/player/

SRCS		=	cub3d.c\
				paint.c\
				errors.c\
				make3d.c\
				sprite3d.c\
				sprite3d2.c\
				${PATH_CONF}read_config.c\
				${PATH_CONF}read_config2.c\
				${PATH_CONF}map_validator.c\
				${PATH_CONF}map_validator2.c\
				${PATH_CONF}fill_map.c\
				${PATH_CONF}check_file.c\
				${PATH_CONF}get_colors.c\
				${PATH_GNL}get_next_line.c\
				${PATH_GNL}get_next_line_utils.c\
				${PATH_PLAYER}player_movement.c\
				${PATH_PLAYER}player_angle.c\
				${PATH_PLAYER}move_functions.c\
				${PATH_IMG}create_img.c\
				${PATH_IMG}get_xpm.c\
				${PATH_IMG}parse_img.c\
				${PATH_IMG}put_sprite.c\
				${PATH_IMG}fix_sprites.c\
				${PATH_IMG}screenshot.c\




OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror 

FRAME		= mlx/libmlx.a dylib/libmlx.dylib -framework OpenGL -framework AppKit ./libft/libft.a

.c.o:		= ${CC} -g ${CFLAGS} -c $< -o ${<:.c=.o}


.PHONY:			all clean fclean re

$(NAME):		${OBJS} ${INCLUDE}
				@${MAKE} -C ./libft
				@${MAKE} -C ./mlx
				@${MAKE} -C ./dylib
				@${CC} ${FRAME} ${OBJS} -o cub3D

all:			${NAME}

clean:
				${RM} ${OBJS}
				${MAKE} clean -C ./libft
				${MAKE} clean -C ./mlx
				${MAKE} clean -C ./dylib

fclean:			clean
				${RM} ${NAME} ./libft/libft.a cub3D

re:				fclean all