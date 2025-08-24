# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 09:51:11 by weijian           #+#    #+#              #
#    Updated: 2025/08/24 09:56:40 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME = ex04

# === SOURCE === #
SRCS = main.cpp

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -Wall -Werror -Wextra ${VER}

# === RULES === #
all: ${NAME}

${NAME}: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o $@

# === CLEANUP === #
clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re