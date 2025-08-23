# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weijian <weijian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 12:31:07 by weijian           #+#    #+#              #
#    Updated: 2025/08/23 13:20:12 by weijian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NAME === #
NAME = ex03

# === OBJS === #
OBJS_DIR = objs/

# === CLASS == #
CLASS = HumanA HumanB Weapon
CLASS_INCL = $(addsuffix ${CLASS},.hpp)
CLASS_SRCS = $(addsuffix ${CLASS},.cpp)
CLASS_OBJS = $(addprefix ${OBJS_DIR},$(CLASS_SRCS:%.cpp=%.o))

# === OTHERS === #
OTHER_SRCS = main.cpp
OTHER_OBJS = $(addprefix ${OBJS_DIR},$(OTHER_SRCS:%.cpp=%.o))
# --- ALL
OBJS = ${CLASS_OBJS} ${OTHER_OBJS}

# === COMPILATION === #
CC			= c++
VER			= -std=c++98
CFLAGS		= -Wall -Werror -Wextra ${VER}

# === RULES === #
all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

${OBJS}: ${CLASS_OBJS} ${OTHER_OBJS} 

${OTHER_OBJS}%.o: ${OTHER_SRCS}% $(CLASS_INCL) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

${OBJS_DIR}%.o: %.cpp %.hpp | ${OBJS_DIR}
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