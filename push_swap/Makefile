NAME = push_swap

CC = cc 
CFLAGS = -Wall -Werror -Wextra
LIBS = -Llibft -lft

DIR_SRCS = srcs
DIR_INCS = includes
DIR_OBJS = .objs

LST_SRCS =	arg_parser.c \
		lst_operations.c \
		lst_informations.c \
		main.c \
		print_values.c \
		basic_stack_operations.c \
		complex_stack_sorter.c \
		basic_stack_sorter.c \
		actions_precalc.c \
		moves_precalc.c \
		execute_actions.c \
		execute_commands.c

LST_OBJS = $(LST_SRCS:.c=.o)
LST_INCS = push_swap.h

SRCS = $(addprefix ${DIR_SRCS}/, ${LST_SRCS})
OBJS = $(addprefix $(DIR_OBJS)/, ${LST_OBJS})
INCS = $(addprefix $(DIR_INCS)/, ${LST_INCS})

DIR_CHECKERINCS = includes/checker
DIR_CHECKERSRCS = srcs/checker
DIR_CHECKEROBJS = .objs/checker

LST_CHECKERSRCS = 	main.c \
					arg_parser.c \
					basic_stack_operations.c \
					execute_commands.c \
					lst_operations.c \
					print_values.c

LST_CHECKERINCS = checker.h
LST_CHECKEROBJS = $(LST_CHECKERSRCS:.c=.o)

CHECKERSRCS = $(addprefix ${DIR_CHECKERSRCS}/, ${LST_CHECKERSRCS})
CHECKEROBJS = $(addprefix $(DIR_CHECKEROBJS)/, ${LST_CHECKEROBJS})
CHECKERINCS = $(addprefix $(DIR_CHECKERINCS)/, ${LST_CHECKERINCS})

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

$(NAME):	$(OBJS)
	@ $(CC) $(OBJS) $(CFLAGS) ${LIBS} -o $@
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
	@ rm -rf $(NAME) checker
	@ printf "libft : "
	@ make fclean -C libft

re:	fclean all

debug : libft/libft.a
	$(CC) -g3 $(SRCS) -I $(DIR_INCS) $(CFLAGS) ${LIBS} -o $@

bonus : $(CHECKEROBJS)
	@ $(CC) $(CHECKEROBJS) $(CFLAGS) ${LIBS} -o checker
	@ printf "$(ERASE)$(GREEN)$@ made\n$(END)"

debugchecker : libft/libft.a
	$(CC) -g3 $(CHECKERSRCS) -I $(DIR_CHECKERINCS) $(CFLAGS) ${LIBS} -o $@

$(DIR_CHECKEROBJS)/%.o: ${DIR_CHECKERSRCS}/%.c $(CHECKERINCS) Makefile libft/libft.a
	@ mkdir -p $(DIR_CHECKEROBJS)
	@ $(CC) $(CFLAGS) -I $(DIR_CHECKERINCS) -c $< -o $@
	@ printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

.PHONY: all clean fclean re bonus libft debug debugchecker
