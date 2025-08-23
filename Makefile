NAME = ex03

SRCS = main.cpp
CL = HumanA HumanB Weapon
CL_SRCS = $(addsuffix ${CL},.cpp)
CL_INCL = $(addsuffix ${CL},.h)

OBJS_DIR = objs/
OBJS = $(addprefix ${OBJS_DIR},$(SRCS=%.o:%.c))
CL_OBJS = $(addprefix ${OBJS_DIR, $(CL_SRCS=%.o:%.c)
