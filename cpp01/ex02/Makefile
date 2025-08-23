# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 22:48:09 by weijian           #+#    #+#              #
#    Updated: 2025/08/23 12:31:34 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME = ex02

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
	rm -r ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re