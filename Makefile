# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 23:28:11 by bedarenn          #+#    #+#              #
#    Updated: 2024/05/22 10:50:14 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCL = headers/
DIR_LIBS = libs/

SRCS = \
	philo_utils.c \
	thread_laucher.c \
	print_philo_emoji.c \
	manage_arg.c \
	manage_fork.c \
	manage_thrd.c \
	manage_philo.c \
	philo.c \
	main.c

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror# -g #-fsanitize=thread
IFLAGS = -I$(DIR_INCL)
LFLAGS = -L$(DIR_LIBS) -lpthread

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re