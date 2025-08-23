# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 14:35:03 by wjhoe             #+#    #+#              #
#    Updated: 2025/08/23 15:02:55 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME		 = ex03

# === CLASS === #
CL			= HumanA HumanB Weapon
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

${ALL_OBJS}: ${OBJS} ${CL_OBJS} | ${OBJS_DIR}

${OBJS}: ${OBJS_DIR}%.o: %.cpp ${CL_INCL}
	${CC} ${CFLAGS} -c $< -o $@

${CL_OBJS}: ${OBJS_DIR}%.o: %.cpp %.hpp
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
