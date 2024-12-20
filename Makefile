# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:15:57 by tmoragli          #+#    #+#              #
#    Updated: 2024/12/21 17:17:15 by tmoragli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------- LIBRARY --------------
NAME		= libasm.a
TESTER		= tester

# ----------- COMPILER FLAGS -------
CC				= nasm
CFLAGS			= -f elf64 -g
GCC				= gcc
GCCFLAGS		= -Iinc -g3
GCCFLAGS_CMP	= -Iinc -g3 -DLIBASM

# ----------- FILES ----------------
OBJ			= ./objs
SRC			= ./src
SRCS		= set_errno.s \
			ft_strlen.s ft_strcpy.s \
			ft_strcmp.s ft_write.s \
			ft_read.s ft_strdup.s

MAIN_OBJ	= main.o

OBJS		= $(patsubst %.s, $(OBJ)/%.o,$(SRCS))

# ----------- RULES ----------------
all		: ${NAME}
$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

$(OBJ)/%.o	: $(SRC)/%.s | $(OBJ)
	$(CC) $(CFLAGS)  $< -o $@

$(OBJ)	:
	mkdir $@

tests	: ${NAME}
	$(GCC) $(GCCFLAGS) -c main.c -o ${MAIN_OBJ}
	${GCC} ${MAIN_OBJ} ${NAME} -o ${TESTER}

tests_cmp	: ${NAME}
	$(GCC) $(GCCFLAGS_CMP) -c main.c -o ${MAIN_OBJ}
	${GCC} ${MAIN_OBJ} ${NAME} -o ${TESTER}

clean	:
	rm -rf ${OBJ}
	rm -rf ${MAIN_OBJ}

fclean	:	clean
	rm -f ${NAME}
	rm -f ${TESTER}
	rm -f ${MAIN_OBJ}

re		:	fclean all

.PHONY	: all tests clean fclean re