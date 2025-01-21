NAME = libft.a

DIR_SRCS = srcs
DIR_INCS = includes
DIR_OBJS = .objs

LIBC_IS =	is/ft_isalnum.c is/ft_isalpha.c is/ft_isascii.c is/ft_isdigit.c is/ft_isprint.c 

LIBC_LST =	lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c \
			lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c \
			lst/ft_lstmap.c lst/ft_lstnew.c lst/ft_lstsize.c

LIBC_MEM =	mem/ft_bzero.c mem/ft_calloc.c \
			mem/ft_memchr.c	mem/ft_memcmp.c mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c

LIBC_PUT =	put/ft_putchar_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c put/ft_putstr_fd.c

LIBC_STR =	str/ft_strchr.c str/ft_strdup.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c \
			str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c str/ft_split.c str/ft_strjoin.c \
			str/ft_strmapi.c str/ft_strtrim.c str/ft_substr.c str/ft_striteri.c 
		
LIBC_TO =	to/ft_tolower.c to/ft_toupper.c \
			to/ft_atoi.c to/ft_itoa.c

LIBC = ${addprefix libc/,${LIBC_IS} ${LIBC_LST} ${LIBC_MEM} ${LIBC_PUT} ${LIBC_STR} ${LIBC_TO}}

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
	@ mkdir -p $(DIR_OBJS)/libc/is
	@ mkdir -p $(DIR_OBJS)/libc/lst
	@ mkdir -p $(DIR_OBJS)/libc/mem
	@ mkdir -p $(DIR_OBJS)/libc/put
	@ mkdir -p $(DIR_OBJS)/libc/str
	@ mkdir -p $(DIR_OBJS)/libc/to
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
