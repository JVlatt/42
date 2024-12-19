NAME = libft.a

DIR_SRCS = srcs
DIR_INCS = includes
DIR_OBJS = .objs

LIBC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstsize.c

FT_PRINTF = ft_printf/ft_print_alpha.c \
			ft_printf/ft_print_num.c \
			ft_printf/ft_printf.c 

GNL	=	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
BUFFER_SIZE	= 4096

LST_SRCS = ${LIBC} ${FT_PRINTF} ${GNL}
LST_OBJS = ${LST_SRCS:.c=.o}
LST_INCS = libft.h get_next_line.h ft_printf.h

SRCS = ${addprefix $(DIR_SRCS)/,${LIBC} ${FT_PRINTF} ${GNL}}
OBJS = ${addprefix $(DIR_OBJS)/, ${LST_OBJS}}
INCS = ${addprefix $(DIR_INCS)/, ${LST_INCS}}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile
	@ mkdir -p $(DIR_OBJS)
	@ mkdir -p $(DIR_OBJS)/get_next_line
	@ mkdir -p $(DIR_OBJS)/ft_printf
	@ $(CC) $(FLAGS) -D BUFFER_SIZE=${BUFFER_SIZE} -I $(DIR_INCS) -c $< -o $@
	@ printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

${NAME}: ${OBJS}
	@ ar -rsc ${NAME} ${OBJS}
	@ printf "$(ERASE)$(GREEN)$@ made\n$(END)"

clean:
	@ rm -f ${OBJS}
	@ printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"

fclean:	clean
	@ rm -rdf	$(NAME)
	@ printf "$(YELLOW)$(NAME) removed$(END)\n"

re:	fclean all

.PHONY: all clean fclean re bonus
