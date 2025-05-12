# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matt <matt@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:47:49 by mgalvez           #+#    #+#              #
#    Updated: 2025/05/12 20:32:38 by matt             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutantStack

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

DIR_SRCS = srcs
DIR_INCS = includes
DIR_OBJS = .objs

LST_SRCS = main.cpp
LST_INCS = Colors.hpp
LST_OBJS = $(LST_SRCS:.cpp=.o)

SRCS = $(addprefix ${DIR_SRCS}/, ${LST_SRCS})
OBJS = $(addprefix $(DIR_OBJS)/, ${LST_OBJS})
INCS = $(addprefix $(DIR_INCS)/, ${LST_INCS})

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

$(DIR_OBJS)/%.o: ${DIR_SRCS}/%.cpp $(INCS) Makefile
	@ mkdir -p $(DIR_OBJS)
	@ $(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@
	@ printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

all : ${NAME}

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
	$(CC) -fsanitize=address -g $(SRCS) -I $(DIR_INCS) $(CFLAGS) -o $@

g3 :
	$(CC) -g3 $(SRCS) -I $(DIR_INCS) $(CFLAGS) -o $@

.PHONY: all clean fclean re fsanitize g3
