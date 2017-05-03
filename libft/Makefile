# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angavrel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 13:55:55 by angavrel          #+#    #+#              #
#    Updated: 2017/02/14 06:54:09 by angavrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

FLAG = -Wall -Wextra -Werror

LIBFILES = $(SRC:.c=.o)

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isascii.c \
	  ft_isalpha.c \
	  ft_isalnum.c \
	  ft_isspace.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memalloc.c \
	  ft_lstnew.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c\
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_memchr.c \
	  ft_itoa.c \
	  ft_memccpy.c \
	  ft_memdel.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_putchar.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_memmove.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strchr.c \
	  ft_strcat.c \
	  ft_strdel.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_strmap.c \
	  ft_strncmp.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strnew.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strrchr.c \
	  ft_strsub.c \
	  ft_swap.c \
	  ft_strstr.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_strsplit.c \
	  ft_strlencmp.c \
	  ft_clamp.c \
	  ft_strctrim.c \
	  ft_memswap.c \
	  ft_strrev.c \
	  ft_bubblesort_array.c \
	  ft_strndup.c \
	  ft_strnjoin.c \
	  ft_strjoinfree.c \
	  ft_strnjoinfree.c \
	  ft_strdupfree.c \
	  ft_intnew.c \
	  ft_putnbr_base.c \
	  ft_error.c \
	  ft_is_power_of_x.c \
	  ft_htoi.c \
	  ft_rand.c \
	  ft_color_converter.c \
	  ft_abs.c \
	  ft_fclamp.c \
	  ft_str2lower.c \
	  ft_itoa_base.c \
	  ft_pow.c \
	  ft_wcharlen.c \
	  ft_wstrlen.c \
	  ft_putwstr.c \
	  ft_wstrjoin.c \
	  ft_wstrsub.c \
	  ft_wstrdup.c \
	  ft_iswascii.c \
	  ft_putwchar.c \
	  ft_ulltoa_base.c \
	  ft_lltoa_base.c \
	  ft_ldtoa.c \
	  ft_round.c \
	  ft_putstr_free.c

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(LIBFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(LIBFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
