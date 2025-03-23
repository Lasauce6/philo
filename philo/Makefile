# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:29:18 by rbaticle          #+#    #+#              #
#    Updated: 2025/03/23 15:28:38 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c \
	   init.c \
	   start.c \
	   monitor.c \
	   actions.c \
	   utils.c
OBJS = $(SRCS:.c=.o)

HEADERS = philo.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

fsan: $(HEADERS)
	$(CC) $(CFLAGS) -g3 -fsanitize=thread $(SRCS) -o $(NAME)

debug: $(HEADERS)
	$(CC) $(CFLAGS) -g3 $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re fsan debug
