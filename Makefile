# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dias <dias@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 10:15:03 by dias              #+#    #+#              #
#    Updated: 2025/04/19 18:33:50 by dias             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= actions.c cleanup.c ft_atoi.c init.c is_simulation_finished.c \
			monitor_routine.c parse_arguments.c philo_routine.c philosophers.c \
			start_simulation.c time.c ft_strcmp.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re