# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 20:42:10 by allentemu         #+#    #+#              #
#    Updated: 2018/08/21 02:23:09 by allentemu        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

INCLUDES = ./libft/libft.h libft/libft.a

SRCS = srcs/main.c \
	srcs/valid.c \
	srcs/init.c \
	srcs/print.c \
	srcs/keycode.c \
	srcs/keys.c \
	srcs/arrows.c \
	srcs/original.c \
	srcs/signal.c \

OBJS = $(SRCS:.c=.o)

READY = @echo "\033[0;32mft_select ready to use!"

all : $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	cp ./libft/libft.a ./lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCLUDES) -ltermcap
	$(READY)

clean:
	make clean -C ./libft
	/bin/rm -f ./lib

fclean:
	/bin/rm -f $(NAME)
	/bin/rm -f $(OBJS)
	make -C ./libft fclean

re: fclean all
