SRCS	=	sources/parsing/parsing_utils.c 	\
			sources/parsing/textures.c 			\
			sources/main.c						\
			sources/mlx_utils/put_pixel.c		\
			sources/mlx_utils/get_pixel.c		\
			sources/mlx_utils/put_img_to_img.c	\
			sources/mlx_utils/img_create.c		\
			sources/colors/clr_make_trgb.c		\
			sources/colors/clr_get.c			\
			sources/events/key_handler.c		\
			sources/events/close_handler.c		\
			sources/ctx/ctx_init.c				\
			sources/ctx/ctx_show.c				\
			sources/ctx/ctx_free.c				\
			sources/win/win_init.c				\
			sources/win/win_free.c				\
			sources/gameloop/gameloop.c			\
			sources/gameloop/raycasting.c		\
			sources/player/player_init.c		\
			sources/init.c

NAME	=	cub3D

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

RM      =	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address,undefined

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS	=	-Llibft -lft -L./minilibx/linux -lmlx -lXext -lX11 -lm -lbsd
	MLX_DIR = minilibx/linux
else
	LIBS = -Llibft -lft -L./minilibx/macOS -lmlx -framework OpenGL -framework AppKit
	MLX_DIR = minilibx/macOS
endif


all: 				$(NAME)

%.o: 				%.c
					${CC} ${CFLAGS} -Iincludes -Ilibft -I${MLX_DIR} -c $? -o $@

${NAME}:			${OBJS}
					@make -C libft
					@make -C ${MLX_DIR}
					${CC} ${CFLAGS} $^ ${LIBS} -o ${NAME}

clean:
					${RM} $(OBJS)
					@make -C libft clean
					@make -C ${MLX_DIR} clean

fclean:				clean
					${RM} $(NAME)
					@make -C libft fclean

re: 				fclean all

.PHONY:				all  clean fclean re
