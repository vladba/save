#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/07 08:30:35 by lsalomme          #+#    #+#              #
#    Updated: 2015/01/14 11:13:52 by vbargues         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = main.c pixel.c key_events.c mouse_event.c
OBJ = $(SRC:.c=.o)
#HEADERS = libft/includes
LIB = -L/usr/X11/lib -lmlx -lX11 -lXext
#-L./libft -lft
OPT = -Wall -Wextra -Werror
NAME = casse_briques

all: $(NAME)

$(NAME):
#	make -C libft/ re
	gcc $(OPT) -c $(SRC) $(LIB)
	gcc $(OPT) -o $(NAME) $(OBJ) -I./$(HEADERS) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

reclean: re clean
