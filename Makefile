# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:36:51 by hawadh            #+#    #+#              #
#    Updated: 2022/10/20 17:58:21 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	cub3D

SRCS		=	./srcs/main.c


MLX			=	libmlx.a

#Checks current OS and determines which to flags to set
OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR		=	./minilibx_opengl
	MLXFLG		=	./libmlx.a -framework OpenGL -framework Appkit
	CFLAGS		+=	-D OSX
else
	MLXDIR		=	./minilibx_linux
	MLXFLG		=	./libmlx.a -lXext -lX11 -lm -lz
	CFLAGS		+=	-D LINUX
endif

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		+=	-Wall -Werror -Wextra -g3

${NAME}:	${OBJS}
			${MAKE} -C ${MLXDIR}
			cp ${MLXDIR}/${MLX} ./
			${CC} ${CFLAGS} ${OBJS} ${MLXFLG} -o ${NAME}

all:	${NAME}

vg:		${NAME}
		valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3d file.cub

clean:
		rm -rf ${OBJS}
		rm -rf ${MLX}
		${MAKE} clean -C ${MLXDIR}

fclean:	clean
		rm -rf ${NAME}

re: fclean all

.PHONY : all clean re fclean