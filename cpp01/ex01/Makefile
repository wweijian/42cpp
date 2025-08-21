# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 22:48:09 by weijian           #+#    #+#              #
#    Updated: 2025/08/20 23:13:12 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME = zombie

# === INCLUDES === #
INCL = Zombie.hpp

# === SOURCE === #
SRCS = Zombie.cpp main.cpp randomChump.cpp newZombie.cpp

# === OBJECTS === #
OBJS_DIR = objs/
OBJS = $(addprefix ${OBJS_DIR},$(SRCS:%.cpp=%.o))

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -Wall -Werror -Wextra ${VER}

# === RULES === #
all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp ${INCL} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p $@

# === CLEANUP === #
clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re