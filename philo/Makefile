# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:29:18 by rbaticle          #+#    #+#              #
#    Updated: 2025/03/17 12:39:42 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS_DIR = ./srcs/
SRCS_NAMES = main.c \
			 init.c \
			 free.c \
			 mutex_threads.c \
			 start.c \
			 utils.c \
			 getter_setters.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES))
OBJS = $(SRCS:.c=.o)

HEADERS = philo.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

fsan: $(HEADERS)
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(SRCS) -o $(NAME)

debug: $(HEADERS)
	$(CC) $(CFLAGS) -g3 $(SRCS) -I $(INCLUDES) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re fsan debug
