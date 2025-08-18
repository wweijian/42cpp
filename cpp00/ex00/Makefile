# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 09:35:27 by weijian           #+#    #+#              #
#    Updated: 2025/08/18 19:29:24 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

# === DEFINTIONS === #

SRC		= ${NAME}.cpp
OBJ		= ${NAME}.o

# === COMPILATION === #

CC = c++
VER = -std=c++98
CFLAGS = -Wall -Werror -Wextra ${VER}

# === RULE === #

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o $@

${OBJ}: %.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

# === CLEANUP === #

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re