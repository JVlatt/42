# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:47:49 by mgalvez           #+#    #+#              #
#    Updated: 2025/03/31 19:10:58 by mmanuell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	@ make -C ./ex00
	@ make -C ./ex01
	@ make -C ./ex02
	@ make -C ./ex03
	@ make -C ./ex04
	@ make -C ./ex05
	@ make -C ./ex06

clean:
	@ make clean -C ./ex00
	@ make clean -C ./ex01
	@ make clean -C ./ex02
	@ make clean -C ./ex03
	@ make clean -C ./ex04
	@ make clean -C ./ex05
	@ make clean -C ./ex06

fclean:	clean
	@ make fclean -C ./ex00
	@ make fclean -C ./ex01
	@ make fclean -C ./ex02
	@ make fclean -C ./ex03
	@ make fclean -C ./ex04
	@ make fclean -C ./ex05
	@ make fclean -C ./ex06

re:	fclean all

.PHONY: all clean fclean re
