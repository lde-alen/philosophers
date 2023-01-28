# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 14:22:14 by lde-alen          #+#    #+#              #
#    Updated: 2023/01/28 14:25:29 by lde-alen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	src/utils/utils.c											\
				src/utils/utils2.c											\
				src/utils/init.c											\
				src/utils/freedom.c											\
				src/error_handling/error_check.c							\
				src/error_handling/error_print.c							\
				src/dinning_problem/setup.c									\
				src/main.c													\
				src/dinning_problem/setup2.c								\

CFLAGS		=	-Wall -Wextra -Werror -g3

INCLUDES	=	-I./include

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
