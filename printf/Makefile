# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 16:32:29 by fldumas-          #+#    #+#              #
#    Updated: 2025/10/25 22:27:55 by fldumas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = \
ft_printf.c \
ft_printflib.c

NAME = libftprintf.a

OBJ = ${SRC:.c=.o}

COMP = cc
FLAGS = -Wall -Werror -Wextra

%.o : %.c
	${COMP} ${FLAGS} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJ}
	ar rcs $@ $^

clean : 
	rm -rf ${OBJ}
fclean : clean
	rm -rf ${NAME}
re : fclean all

.PHONY : all clean bonus fclean re
