SRC =	arg_parser.c \
		lst_operations.c \
		lst_informations.c \
		main.c \
		print_values.c \
		basic_stack_operations.c \
		stack_sorter.c

SRCS = ${addprefix ${CDIR},${SRC}}

NAME = push_swap

CDIR = ./srcs/

HEADDIR = ./includes/

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c -I ${HEADDIR} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME} 

debug:
	${CC} ${CFLAGS} ${SRCS} -I ${HEADDIR} -g3 -o ${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean;
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
