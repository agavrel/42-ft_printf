# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 13:55:55 by angavrel          #+#    #+#              #
#    Updated: 2017/05/28 07:57:24 by angavrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2

HEADER = libft

LIBFILES = $(SRC:.c=.o)

SRC = ft_atoi_parse.c \
	  ft_bzero.c \
	  ft_memchr.c \
	  ft_memcpy.c \
	  ft_memset.c \
	  ft_pow.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_wcharlen.c \
	  ft_strchr_index.c \
	  ft_wstrlen.c \
	  ft_strdup.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(LIBFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(LIBFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
