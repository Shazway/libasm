# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:15:57 by tmoragli          #+#    #+#              #
#    Updated: 2024/09/18 00:13:00 by tmoragli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------- LIBRARY --------------
NAME		= libasm.a
TESTER		= tester

# ----------- COMPILER FLAGS -------
CC			= nasm
CFLAGS		= -f elf64 -g

# ----------- FILES ----------------
OBJ			= ./objs
SRC			= ./src
SRCS		= is_null.s set_errno.s \
			ft_strlen.s ft_strcpy.s #ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
MAIN_OBJ	= main.o

OBJS		= $(patsubst %.s, $(OBJ)/%.o,$(SRCS))
OBJB		= $(patsubst %.s, $(OBJ)/%.o,$(SRCB))

# ----------- RULES ----------------
all		: ${NAME}
$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

$(OBJ)/%.o	: $(SRC)/%.s | $(OBJ)
	$(CC) $(CFLAGS)  $< -o $@

$(OBJ)/%.o	: $(SRC)/%.s | $(OBJ)
	$(CC) $(CFLAGS)  $< -o $@

$(OBJ)		:
	mkdir $@
	
bonus	: ${OBJB} ${OBJS}
	ar rcs ${NAME} ${OBJS} ${OBJB}

clean	:
	rm -rf ${OBJ}

fclean	:	clean
	rm -f ${NAME}
	rm -f ${TESTER}
	rm -f ${MAIN_OBJ}

re		:	fclean all

.PHONY	: all clean fclean re