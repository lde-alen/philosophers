# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 14:22:14 by lde-alen          #+#    #+#              #
#    Updated: 2023/01/29 18:58:52 by lde-alen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	srcs/main.c													\
				srcs/errors/error_check.c									\
				srcs/errors/error_print.c									\
				srcs/init/init.c											\
				srcs/init/threads.c											\
				srcs/simulation/monitoring.c								\
				srcs/simulation/simulation.c								\
				srcs/simulation/sim_utils.c									\
				srcs/simulation/thread_tasks.c								\
				srcs/utils/error_utils.c									\
				srcs/utils/philo_print_utils.c								\
				srcs/utils/time_utils.c										\
				srcs/utils/utils.c											\
				srcs/free/free.c											\


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
