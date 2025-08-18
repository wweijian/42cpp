# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 13:25:20 by weijian           #+#    #+#              #
#    Updated: 2025/08/18 19:29:42 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME = account

# === HEADER FILES === #
INCL = Account.hpp

# === SOURCE FILES === #
SRCS		= Account.cpp tests.cpp

# === OBJECTS === #
OBJS_DIR	= objs/
OBJS		:= $(addprefix ${OBJS_DIR},$(SRCS:%.cpp=%.o))

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -Wall -Werror -Wextra ${VER}

# === RULES === #
all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

${OBJS_DIR}%.o: %.cpp ${INCL} | ${OBJS_DIR}
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