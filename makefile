# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 07:43:52 by dvargas           #+#    #+#              #
#    Updated: 2022/12/07 07:26:50 by dvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS	=	main.c \
			set.c \
			render.c \
			utils.c \
			ignite.c \
			help.c

OBJS		= ${SRCS:%.c=%.o}
NAME		= fractol
LIB			= libft/libft.a
CC			= cc
CCFLAGS		= -Wall -Wextra
LIBFT_PATH  = libft/
MLX_PATH 	= mlx_linux/
TEST_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:		${NAME}

$(NAME):	${OBJS}
			@ echo 'Creating the monster ${NAME}'
			make all -C $(LIBFT_PATH)
			make all -C $(MLX_PATH)
			${CC} ${CCFLAGS} ${OBJS} ${LIB} ${TEST_FLAGS} -o ${NAME}
			@ echo ' '
			@ echo 'ITS ALIVE!!!!!!!!!'
			@ echo ' '

%.o: %.c
			${CC} ${CCFLAGS} -I/usr/include -lmlx_Linux -O3 -c $< -o $@
			@ echo ' '

clean:
			@ echo 'clean rule'
			rm -f ${OBJS} bonus.o
			make clean -C $(LIBFT_PATH)
			@ echo ' '

fclean:		clean
			@ echo 'Removing ${NAME}'
			rm -f ${NAMEBONUS}
			rm -f ${NAME}
			make fclean -C $(LIBFT_PATH)
			@ echo ' '

re:			fclean all
			@ echo 're rule. . . .$<'
			@ echo ' '

.PHONY:		all clean fclean re
