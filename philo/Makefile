# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:29:18 by rbaticle          #+#    #+#              #
#    Updated: 2025/02/03 14:47:42 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS = philo_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS_DIR = ./srcs/
SRCS_NAMES = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES))
OBJS = $(SRCS:.c=.o)

SRCS_NAMES_BONUS = 
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES_BONUS))
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES = ./includes/
HEADER_FILES = philo.h
HEADERS = $(addprefix $(INCLUDES), $(HEADER_FILES))

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES) -o $(NAME)

bonus: $(OBJS_BONUS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(INCLUDES) -o $(BONUS)

fsan: $(HEADERS)
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(SRCS) -I $(INCLUDES) -o $(NAME)

fsanb: $(HEADERS)
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(SRCS_BONUS) -I $(INCLUDES) -o $(BONUS)

debug: $(HEADERS)
	$(CC) $(CFLAGS) -g3 $(SRCS) -I $(INCLUDES) -o $(NAME)

debugb: $(HEADERS)
	$(CC) $(CFLAGS) -g3 $(SRCS) -I $(INCLUDES) -o $(BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re fsan debug bonus fsanb debugb
