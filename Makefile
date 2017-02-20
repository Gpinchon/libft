# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 16:34:53 by gpinchon          #+#    #+#              #
#    Updated: 2017/02/20 15:15:43 by gpinchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		=	./src/ft_bzero.c \
			./src/ft_isdigit.c \
			./src/ft_memccpy.c \
			./src/ft_memchr.c \
			./src/ft_memcmp.c \
			./src/ft_memcpy.c \
			./src/ft_memset.c \
			./src/ft_strcat.c \
			./src/ft_strchr.c \
			./src/ft_strcpy.c \
			./src/ft_strdup.c \
			./src/ft_strlen.c \
			./src/ft_strncat.c \
			./src/ft_strncpy.c \
			./src/ft_strnstr.c \
			./src/ft_strrchr.c \
			./src/ft_strstr.c \
			./src/ft_strcmp.c \
			./src/ft_strncmp.c \
			./src/ft_isdigit.c \
			./src/ft_atoi.c \
			./src/ft_isalpha.c \
			./src/ft_isalnum.c \
			./src/ft_isascii.c \
			./src/ft_isprint.c \
			./src/ft_toupper.c \
			./src/ft_tolower.c \
			./src/ft_memalloc.c \
			./src/ft_memdel.c \
			./src/ft_strnew.c \
			./src/ft_strdel.c \
			./src/ft_strclr.c \
			./src/ft_striter.c \
			./src/ft_striteri.c \
			./src/ft_strmap.c \
			./src/ft_strmapi.c \
			./src/ft_strequ.c \
			./src/ft_strnequ.c \
			./src/ft_strsub.c \
			./src/ft_strjoin.c \
			./src/ft_strjoinfree.c \
			./src/ft_strtrim.c \
			./src/ft_putchar.c \
			./src/ft_putstr.c \
			./src/ft_putendl.c \
			./src/ft_putnbr.c \
			./src/ft_putchar_fd.c \
			./src/ft_putstr_fd.c \
			./src/ft_putendl_fd.c \
			./src/ft_putnbr_fd.c \
			./src/ft_itoa.c \
			./src/ft_strsplit.c \
			./src/ft_strsplitwspace.c \
			./src/ft_memmove.c \
			./src/ft_strlcat.c \
			./src/ft_strrev.c \
			./src/ft_charswap.c \
			./src/ft_intswap.c \
			./src/ft_free_chartab.c	\
			./src/get_next_line.c \
			./src/clamp.c	\
			./src/cycle.c	\
			./src/countchar.c	\
			./src/file_to_str.c

OBJ		= $(SRC:.c=.o)
INCLUDE	= -I ./include/
CC		= gcc
CFLAGS	= -Ofast -Wall -Wextra -Werror $(INCLUDE)


$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
