# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:47:49 by mgalvez           #+#    #+#              #
#    Updated: 2025/04/23 14:34:42 by mmanuell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	@ make -C ./ex00
	@ make -C ./ex01
	@ make -C ./ex02
	@ make -C ./ex03

clean:
	@ make clean -C ./ex00
	@ make clean -C ./ex01
	@ make clean -C ./ex02
	@ make clean -C ./ex03

fclean:	clean
	@ make fclean -C ./ex00
	@ make fclean -C ./ex01
	@ make fclean -C ./ex02
	@ make fclean -C ./ex03

re:	fclean all

.PHONY: all clean fclean re
