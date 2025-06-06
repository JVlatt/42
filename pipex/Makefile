NAME = pipex

CC = cc 
CFLAGS = -Wall -Werror -Wextra
LIBS = -Llibft -lft

DIR_SRCS = srcs
DIR_INCS = includes
DIR_OBJS = .objs

LST_SRCS =	main.c \
			utils.c \
			path.c \
			pipex.c

LST_OBJS = $(LST_SRCS:.c=.o)
LST_INCS = pipex.h

SRCS = $(addprefix ${DIR_SRCS}/, ${LST_SRCS})
OBJS = $(addprefix $(DIR_OBJS)/, ${LST_OBJS})
INCS = $(addprefix $(DIR_INCS)/, ${LST_INCS})

LST_SRCS_BONUS =	main_bonus.c \
					utils.c \
					path.c \
					pipex.c \
					here_doc.c

LST_OBJS_BONUS = $(LST_SRCS_BONUS:.c=.o)

SRCS_BONUS = $(addprefix ${DIR_SRCS}/, ${LST_SRCS_BONUS})
OBJS_BONUS = $(addprefix $(DIR_OBJS)/, ${LST_OBJS_BONUS})

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

$(DIR_OBJS)/%.o: ${DIR_SRCS}/%.c $(INCS) Makefile libft/libft.a
	@ mkdir -p $(DIR_OBJS)
	@ $(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@
	@ printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

all : libft ${NAME}

bonus : libft $(OBJS_BONUS)
	@ $(CC) $(CFLAGS) $(OBJS_BONUS) ${LIBS} -o $@
	@ printf "$(ERASE)$(GREEN)$@ made\n$(END)"

$(NAME):	$(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) ${LIBS} -o $@
	@ printf "$(ERASE)$(GREEN)$@ made\n$(END)"

libft/libft.a :
	@ make -C libft

clean:
	@ printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	@ rm -rdf $(DIR_OBJS)
	@ printf "libft : "
	@ make clean -C libft

fclean:		clean
	@ printf "$(YELLOW)$(NAME) removed$(END)\n"
	@ rm -rf $(NAME) bonus
	@ printf "libft : "
	@ make fclean -C libft

re:	fclean all

debug : libft/libft.a
	$(CC) -g3 $(SRCS) -I $(DIR_INCS) $(CFLAGS) ${LIBS} -o $@

.PHONY: all clean fclean re libft bonus
