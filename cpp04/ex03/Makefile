# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 13:48:07 by weijian           #+#    #+#              #
#    Updated: 2025/09/15 18:54:48 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME		 = ex03

# === SRCS === #
SRCS		= main.cpp
SRCS_DIR	= srcs/
INCL_DIR	= includes/
SRCS		:= $(addprefix ${SRCS_DIR},${SRCS})

# === CLASS === #
CL			= AMateria Character Cure Ice MateriaSource ICharacter IMateriaSource
CL_SRCS		= $(addprefix ${SRCS_DIR},$(addsuffix .cpp,${CL}))
CL_INCL		= $(addprefix ${INCL_DIR},$(addsuffix .hpp,${CL}))

# === OBJS === #
OBJS_DIR	= objs/
OBJS 		= $(SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.o)
CL_OBJS 	= $(CL_SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.o)
ALL_OBJS	= ${OBJS} ${CL_OBJS}

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -g -Wall -Werror -Wextra ${VER} -I${INCL_DIR}

# === RULES === #
all: ${NAME}

${NAME}: ${ALL_OBJS}
	${CC} ${CFLAGS} ${ALL_OBJS} -o $@

${OBJS}: ${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp ${INCL_DIR} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${CL_OBJS}: ${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp ${INCL_DIR} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

# === DIRECTORY === #

${OBJS_DIR}:
	mkdir -p $@

# === CLEANUP === #
clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re