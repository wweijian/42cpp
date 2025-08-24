# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 14:35:03 by wjhoe             #+#    #+#              #
#    Updated: 2025/08/24 23:07:28 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME		 = ex02

# === CLASS === #
CL			= Fixed
CL_SRCS		= $(addsuffix .cpp,${CL})
CL_INCL		= $(addsuffix .hpp,${CL})

# === SRCS === #
SRCS		= main.cpp

# === OBJS === #
OBJS_DIR	= objs/
OBJS 		= $(addprefix ${OBJS_DIR},$(SRCS:%.cpp=%.o))
CL_OBJS 	= $(addprefix ${OBJS_DIR},$(CL_SRCS:%.cpp=%.o))
ALL_OBJS	= ${OBJS} ${CL_OBJS}

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -Wall -Werror -Wextra ${VER}


# === RULES === #
all: ${NAME}

${NAME}: ${ALL_OBJS}
	${CC} ${CFLAGS} ${ALL_OBJS} -o $@

${OBJS}: ${OBJS_DIR}%.o: %.cpp ${CL_INCL} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${CL_OBJS}: ${OBJS_DIR}%.o: %.cpp %.hpp | ${OBJS_DIR}
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
