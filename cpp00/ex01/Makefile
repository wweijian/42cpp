# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 09:35:27 by weijian           #+#    #+#              #
#    Updated: 2025/08/14 14:03:44 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

SRC		= main.cpp
OBJ		= ${SRCS:%.cpp=%.o}
INCL	= Contact.hpp PhoneBook.hpp
# === COMPILATION === #

CC = c++
VER = -std=c++98
CFLAGS = -Wall -Werror -Wextra ${VER}

# === RULE === #

all: ${NAME}

${NAME}: ${OBJ} ${INCL}
	${CC} ${CFLAGS} ${OBJ} -o $@

${OBJ}: %.o: %.cpp ${INCL}
	${CC} ${CFLAGS} -c $< -o $@

# === CLEANUP === #

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}
