# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:47:49 by mgalvez           #+#    #+#              #
#    Updated: 2025/04/03 16:13:30 by mmanuell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	@ make -C ./CPP00
	@ make -C ./CPP01
	@ make -C ./CPP02
	@ make -C ./CPP03
	@ make -C ./CPP04

clean:
	@ make clean -C ./CPP00
	@ make clean -C ./CPP01
	@ make clean -C ./CPP02
	@ make clean -C ./CPP03
	@ make clean -C ./CPP04

fclean:	clean
	@ make fclean -C ./CPP00
	@ make fclean -C ./CPP01
	@ make fclean -C ./CPP02
	@ make fclean -C ./CPP03
	@ make fclean -C ./CPP04

re:	fclean all

.PHONY: all clean fclean re
