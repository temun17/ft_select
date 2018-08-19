NAME = ft_select

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

INCLUDES = ./libft/libft.h libft/libft.a

SRCS = srcs/main.c \
	srcs/signal.c \
	srcs/display.c \
	srcs/term.c \
	srcs/keyhook.c \
	srcs/keys.c \
	srcs/valid.c \
	srcs/actions.c \
	srcs/arrows.c

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
