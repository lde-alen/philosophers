# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 14:22:14 by lde-alen          #+#    #+#              #
#    Updated: 2023/01/29 13:54:42 by lde-alen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	srcs/main.c

CFLAGS		=	-Wall -Wextra -Werror -g3

INCLUDES	=	-I./includes

CC			=	gcc

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)
				

.c.o		:
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME)		:	$(OBJS)
				@echo " \033[0;32mSucccess creating philo .o files \033[0m"
				@$(CC) $(CFLAGS) $(OBJS) -pthread $(INCLUDES) -o $(NAME) 
				@echo " \033[0;32mSucccess creating executable \033[0m"

BANNER		:
				@bash -e assets/story.sh
				
clean		:
				@rm -rf $(OBJS)
				@echo " \033[0;32mRemoved philo .o files \033[0m"

fclean		:	clean
				@rm -rf $(NAME)
				@echo " \033[0;32mRemoved Philo executable \033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re
