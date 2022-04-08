# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmother <lmother@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 14:54:36 by lmother           #+#    #+#              #
#    Updated: 2022/04/07 19:42:36 by lmother          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIB		=	./Libft
LIBFT		=	libft.a

INC			=	./minishell.h

NAME		=	minishell

SRCS		=	utils_for_parser.c\
				put_syntax_error.c\
			  	preparsing.c\
			  	check_quotes.c\
			  	check_redirections_and_pipes.c\
			  	parsing.c\
			  	free.c\
			  	init_t_cmd.c\
			  	make_str_arr.c\
			  	handling_qoutes_and_slash.c\
			  	handling_dollar.c\
			  	handling_redirections.c\
			  	utils_for_redirections.c\
			  	put_errors.c\
			  	execute_commands.c\
			  	minishell.c\
			  	utils.c\
			  	builtin_cd.c\
			  	builtin_echo.c\
			  	builtin_env.c\
			  	builtin_pwd.c\
			  	builtin_export.c\
			  	builtin_unset.c\
			  	builtin_env1.c\
			  	builtin_exit.c\
			  	sort_export.c\
			  	sig_handle.c\
			  	execve_builtins.c\
			  	get_exit_code.c \
				builtin_env2.c

OBJS		=	$(SRCS:.c=.o)

%.o:		%.c $(INC)
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
			~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include $(OBJS) $(SRC_LIB)/$(LIBFT)

clean:
			$(MAKE) clean -C $(SRC_LIB)
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re :		fclean all

