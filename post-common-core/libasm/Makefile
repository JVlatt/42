DIR_OBJS = .objs

LIBASM = ft_read.s ft_strcmp.s ft_strlen.s ft_write.s ft_strcpy.s ft_strdup.s

LST_OBJS = ${LIBASM:.s=.o}

SRCS = ${LIBASM}
OBJS = ${addprefix $(DIR_OBJS)/, ${LST_OBJS}}

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = out

all: ${NAME}

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

$(DIR_OBJS)/%.o: ./%.s Makefile
	@ mkdir -p $(DIR_OBJS)
	@ $(CC) $(FLAGS) -c $< -o $@
	@ printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

${NAME}: ${OBJS}
	@ $(CC) $(FLAGS) main.c ${OBJS} -o ${NAME}
	@ printf "$(ERASE)$(GREEN)$@ made\n$(END)"

clean:
	@ rm -rdf ${DIR_OBJS}
	@ printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"

fclean:	clean
	@ rm -rdf	$(NAME)
	@ printf "$(YELLOW)$(NAME) removed$(END)\n"

re:	fclean all

.PHONY: all clean fclean re bonus
