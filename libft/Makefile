# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 12:35:02 by atemunov          #+#    #+#              #
#    Updated: 2018/06/19 22:35:07 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SRCS = ft_toupper \
	   ft_tolower \
	   ft_isprint \
	   ft_isdigit \
	   ft_isascii \
	   ft_isalnum \
	   ft_isalpha \
	   ft_isspace \
	   ft_strlen \
	   ft_strdup \
	   ft_strcpy \
	   ft_strncpy \
	   ft_strcat \
	   ft_strncat \
	   ft_strlcat \
	   ft_strchr \
	   ft_strrchr \
	   ft_strcmp \
	   ft_strncmp \
	   ft_strnew \
	   ft_strdel \
	   ft_strclr \
	   ft_strequ \
	   ft_strnequ \
	   ft_strsub \
	   ft_strstr \
	   ft_strnstr \
	   ft_striter \
	   ft_striteri \
	   ft_strmap \
	   ft_strmapi \
	   ft_strtrim \
	   ft_strsplit \
	   ft_strjoin \
	   ft_atoi \
	   ft_itoa \
	   ft_bzero \
	   ft_memcmp \
	   ft_memcpy \
	   ft_memccpy \
	   ft_memchr \
	   ft_memalloc \
	   ft_memset \
	   ft_memdel \
	   ft_memmove \
	   ft_putchar \
	   ft_putchar_fd \
	   ft_putstr \
	   ft_putstr_fd \
	   ft_putnbr \
	   ft_putnbr_fd \
	   print_bits \
	   ft_putendl \
	   ft_putendl_fd \
	   ft_lstnew \
	   ft_lstdelone \
	   ft_lstdel \
	   ft_lstadd \
	   ft_lstnew \
	   ft_lstiter \
	   ft_lstmap \
	   ft_lstrev \
	   get_next_line \


CFILES= $(addsuffix .c, $(SRCS))

OFILES= $(addsuffix .o, $(SRCS))

OBJS= $(addsuffix .o, $(notdir $(SRCS)))

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

$(OBJ): $(CFILES)
	$(CC) $(INCLUDE) $(CFLAGS) $(CFILES) -c

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: make all clean fclean re
