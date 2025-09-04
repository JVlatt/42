SRC =	ft_print_alpha.c ft_printf.c ft_print_num.c

SRCS = ${addprefix ${CDIR},${SRC}}

NAME = libftprintf.a

CDIR = ./srcs/

HEADDIR = ./includes/

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c -I ${HEADDIR} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rsc ${NAME} ${OBJS}

all: ${NAME} 

exec: ${OBJS}
	${CC} ${CFLAGS} -I ${HEADDIR} ${OBJS} -o printf_test

clean:
	rm -f ${OBJS}

fclean:	clean;
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
