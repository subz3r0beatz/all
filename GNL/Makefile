# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 16:32:29 by fldumas-          #+#    #+#              #
#    Updated: 2025/11/15 16:51:54 by fldumas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = \
get_next_line.c \
get_next_line_utils.c

BONUSSRC = \
get_next_line_bonus.c \
get_next_line_utils_bonus.c

NAME = get_next_line.a

OBJ = ${SRC:.c=.o}
BONUSOBJ = ${BONUSSRC:.c=.o}

COMP = cc
FLAGS = -Wall -Werror -Wextra

%.o : %.c
	${COMP} ${FLAGS} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJ}
	ar rcs $@ $^

bonus : ${BONUSOBJ}
	ar rcs ${NAME} ${BONUSOBJ}

clean : 
	rm -rf ${OBJ} ${BONUSOBJ}
fclean : clean
	rm -rf ${NAME}
re : fclean all

.PHONY : all clean bonus fclean re
