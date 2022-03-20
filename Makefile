# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmother <lmother@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 14:54:36 by lmother           #+#    #+#              #
#    Updated: 2022/03/13 16:27:06 by lmother          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIB		=	./libft
LIBFT		=	libft.a

INC			=	./minishell.h

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
				sort_export.c \
				sig_handl.c \
				parser.c \
				utils_for_parser.c \
				preparser.c

OBJS		=	$(SRCS:.c=.o)

%.o:		%.c $(INC) Makefile
			$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address -include $(INC)

.PHONY:	all clean fclean re bonus

all:		
			$(MAKE) -C $(SRC_LIB) -j 4
			$(MAKE) $(NAME) -j 4

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) -lreadline $(CFLAGS) -o $(NAME) -lreadline -L \
			~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include \
			$(OBJS) $(SRC_LIB)/$(LIBFT)

clean:
			$(MAKE) clean -C $(SRC_LIB)
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re :		fclean all

