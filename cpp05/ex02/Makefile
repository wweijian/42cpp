# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 10:01:29 by weijian           #+#    #+#              #
#    Updated: 2025/09/18 22:29:54 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME		 = ex02

# === SRCS === #
SRCS_DIR	= srcs/
INCL_DIR	= includes/

CLASS		= Bureaucrat AForm ShrubberyCreationForm \
				RobotomyRequestForm PresidentialPardonForm
INCL		= $(addprefix ${INCL_DIR},$(addsuffix .hpp,${CLASS}))
SRCS		= $(addsuffix .cpp,${CLASS})
SRCS		+= main.cpp
SRCS		:= $(addprefix ${SRCS_DIR},${SRCS})

# === OBJS === #
OBJS_DIR	= objs/
OBJS 		= $(SRCS:${SRCS_DIR}%.cpp=${OBJS_DIR}%.o)

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -Wall -Werror -Wextra ${VER} -I${INCL_DIR}

# === RULES === #
all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

${OBJS}: ${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp ${INCL} | ${OBJS_DIR}
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