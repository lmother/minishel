# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmother <lmother@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 14:54:36 by lmother           #+#    #+#              #
#    Updated: 2022/02/23 20:28:52 by lmother          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIB		=	./Libft
LIBFT		=	libft.a

INC			=	./minishel.h

NAME		=	minishell

SRCS		=	minishell.c \
				utils.c \
				builtin_cd.c \
				builtin_echo.c \
				builtin_env.c \
				builtin_pwd.c \
				builtin_export.c \
				builtin_unset.c \
				builtin_env1.c \
				builtin_exit.c \
				sort_export.c

OBJS		=	$(SRCS:.c=.o)

%.o:		%.c $(INC)
			$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror -g -include $(INC)

.PHONY:	all clean fclean re bonus

all:		
			$(MAKE) -C $(SRC_LIB) -j 4
			$(MAKE) $(NAME) -j 4

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) -lreadline $(CFLAGS) -o $(NAME) $(OBJS) $(SRC_LIB)/$(LIBFT)

clean:
			$(MAKE) clean -C $(SRC_LIB)
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re :		fclean all

