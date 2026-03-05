# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:01:59 by malaimo           #+#    #+#              #
#    Updated: 2026/02/10 14:22:46 by jdelmott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./ft_isalpha.c\
      ./ft_isdigit.c\
      ./ft_isalnum.c\
      ./ft_isascii.c\
      ./ft_isprint.c\
      ./ft_strlen.c\
      ./ft_memset.c\
      ./ft_bzero.c\
      ./ft_memcpy.c\
      ./ft_memmove.c\
      ./ft_strlcat.c\
      ./ft_strlcpy.c\
      ./ft_toupper.c\
      ./ft_tolower.c\
      ./ft_strchr.c\
      ./ft_strrchr.c\
      ./ft_strncmp.c\
      ./ft_memchr.c\
      ./ft_memcmp.c\
      ./ft_strnstr.c\
      ./ft_atoi.c\
      ./ft_calloc.c\
      ./ft_strdup.c\
      ./ft_substr.c\
      ./ft_strjoin.c\
      ./ft_strtrim.c\
      ./ft_split.c\
      ./ft_itoa.c\
      ./ft_strmapi.c\
      ./ft_striteri.c\
      ./ft_putchar_fd.c\
      ./ft_putstr_fd.c\
      ./ft_putendl_fd.c\
      ./ft_putnbr_fd.c\
      ./get_next_line.c\
      ./ft_putnbr_base.c\
      ./ft_putnbr_p.c\
      ./ft_putnbr_u.c\
      ./ft_printf.c\
      ./ft_putchar.c\
      ./ft_putstr.c\
      ./ft_putnbr.c\
      ./ft_lstnew.c\
      ./ft_lsadd_front.c\
      ./ft_lstsize.c\
      ./ft_lstlast.c\
      ./ft_lstadd_back.c\
      ./ft_lstdelone.c\
      ./ft_lstclear.c\
      ./ft_lstiter.c\
      ./ft_lstmap.c\
      ./ft_strnstr_back.c\
      ./ft_strcmp.c\
      ./ft_getenv.c\
      ./ft_printf_fd.c\
      ./ft_putnbr_base_fd.c\
      ./ft_putnbr_p_fd.c\
      ./ft_putnbr_u_fd.c\
      ./free_tab.c\

CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $^ -c

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
