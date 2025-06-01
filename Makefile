# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 17:00:11 by yosherau          #+#    #+#              #
#    Updated: 2025/06/01 18:47:31 by yosherau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

SRCS_DIR	=	./srcs

SRCS		=	$(wildcard $(SRCS_DIR)/*.c) philosophers.c

OBJS_DIR	=	./objs

OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c | $(OBJS_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
					mkdir -p $(OBJS_DIR)

clean:
				$(RM) $(OBJS_DIR) philosophers.o

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re