SRC =	events_manager.c\
		fractal_renderer.c\
		init.c\
		main.c\
		utils.c \
		ft_atod.c

SRCS = ${addprefix ${CDIR},${SRC}}

NAME = fract-ol

CDIR = ./srcs/

HEADDIR = ./includes/

OBJS = ${SRCS:%.c=%.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -I/usr/include -Imlx_linux -O3

MLX_PATH = ./minilibx-linux --no-print-directory

all: $(NAME)

$(MLX_NAME):
	@make -C $(MLX_PATH)

$(NAME): $(OBJS)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	@make clean -C $(MLX_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
