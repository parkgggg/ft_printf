# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gupark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 03:00:14 by gupark            #+#    #+#              #
#    Updated: 2022/03/16 03:04:23 by gupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_print_nbr.c ft_print_str.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJS)
	  ar -cr $(NAME) $(OBJS)

%.o:%.c ft_print.h
	cc $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
