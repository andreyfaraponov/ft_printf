# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 13:16:27 by afarapon          #+#    #+#              #
#    Updated: 2018/01/06 19:08:05 by afarapon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

IDIR = ./includes

CFLAGS = -I$(IDIR)

LIBDIR = ./libft

LIBFT = $(LIBDIR)/libft.a

SRCDIR = src

SRC =	additional.c \
		basic_functions.c \
		get_flags.c \
		print_characters.c \
		print_u_characters.c \
		print_u_string.c \
		print_hex.c \
		print_integer.c \
		print_memory.c \
		print_octal.c \
		print_percent.c \
		print_strings.c \
		print_uint.c \
		service_one.c
		
_OBJ = $(SRC:%.c=%.o)

_DEPS = libftprintf.h

OBJ = $(SRC:.c=.o)

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(LIBFT) $(OBJ)
			@cp libft/libft.a ./$(NAME)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

$(LIBFT):
	@make -C $(LIBDIR)

clean:
	@/bin/rm -rf *.o
	@/bin/rm -rf libft/*.o

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf libft/libft.a

re : fclean all

test: all
	gcc -o test main.c -L. -lftprintf