# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 09:35:27 by weijian           #+#    #+#              #
#    Updated: 2025/08/18 13:27:42 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME		= phonebook

# === INCLUDES === #
INCL_DIR	= includes/
HEADERS		= Contact.hpp PhoneBook.hpp
INCL		= $(addprefix ${INCL_DIR},${HEADERS})

# === SOURCE FILES === #
SRCS_DIR	= srcs/
SRCS		= main.cpp Contact.cpp PhoneBook.cpp
SRCS		:= $(addprefix ${SRCS_DIR},${SRCS})

# === OBJECTS === #
OBJS_DIR	= objs/
OBJS		:= $(SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.o)

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -Wall -Werror -Wextra -I${INCL_DIR} ${VER}

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

.PHONY: all clean fclean