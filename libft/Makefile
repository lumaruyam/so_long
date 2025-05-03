# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 16:04:43 by lulmaruy          #+#    #+#              #
#    Updated: 2025/04/07 20:22:11 by lulmaruy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -g -o -Wall -Wextra -Werror -D BUFFER_SIZE=42

HEAD = libft.h

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strcmp.c get_next_line.c ft_print_char.c ft_print_nbr.c ft_print_ptr.c \
	ft_print_str.c ft_print_hex.c ft_printf.c


OBJ = $(SRC:.c=.o)

B_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c  \
	ft_lstclear.c

B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(B_OBJ)
	ar rc $(NAME) $(OBJ) $(B_OBJ)
	ranlib $(NAME)

bonus: $(OBJ) $(B_OBJ)
	ar rc  $(NAME) $(B_OBJ)
	ranlib $(NAME)

%.o: %.c $(HEAD)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
