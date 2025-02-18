# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:47:49 by mgalvez           #+#    #+#              #
#    Updated: 2025/02/18 20:03:36 by mmanuell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc 
CFLAGS = -Wall -Werror -Wextra -pthread

SRCS	= 	main.c \
			parsing.c \
			parsing_utils.c \
			utils.c \
			actions.c \
			routine.c \
			manager.c \
			ft_time.c
			
DIR_OBJS = .objs
OBJS = $(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

$(DIR_OBJS)/%.o: %.c Makefile
	@ mkdir -p $(DIR_OBJS)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

all : libft ${NAME}

$(NAME):	$(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) -o $@
	@ printf "$(ERASE)$(GREEN)$@ made\n$(END)"

clean:
	@ printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	@ rm -rdf $(DIR_OBJS)

fclean:		clean
	@ printf "$(YELLOW)$(NAME) removed$(END)\n"
	@ rm -rf $(NAME) fsanitize g3

re:	fclean all

fsanitize :
	$(CC) -fsanitize=thread -g $(SRCS) $(CFLAGS) -o $@

g3 : libft
	$(CC) -g3 $(SRCS) $(CFLAGS) -o $@
	
.PHONY: all clean fclean re libft fsanitize g3
