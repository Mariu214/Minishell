# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:01:59 by malaimo           #+#    #+#              #
#    Updated: 2026/03/12 14:25:57 by jdelmott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcat ft_strlcpy \
      ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
      ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd get_next_line ft_putnbr_base \
      ft_putnbr_p ft_putnbr_u ft_printf ft_putchar ft_putstr ft_putnbr ft_lstnew ft_lsadd_front ft_lstsize ft_lstlast ft_lstadd_back \
      ft_lstdelone ft_lstclear ft_lstiter ft_lstmap ft_strnstr_back ft_strcmp ft_getenv ft_printf_fd ft_putnbr_base_fd ft_putnbr_p_fd \
      ft_putnbr_u_fd free_tab gnl_lim is_there ft_split_space ft_calloc_gc ft_free_all_gc ft_lstadd_gc ft_strdup_gc ft_strjoin_gc \
	  ft_split_gc ft_split_space_gc ft_error_gc \
      
SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Werror -Wextra

INCLUDE =  include/libft.h

SRC = $(addprefix $(SRC_DIR), $(addsuffix) .c, $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \033[33m
RESET = \033[0;39m

$(OBJF):
	@mkdir -p $(OBJ_DIR)

vpath %.c $(SRC_DIR) $(SRC_DIR)printf $(SRC_DIR)printf_fd $(SRC_DIR)string $(SRC_DIR)memory \
	$(SRC_DIR)list $(SRC_DIR)is $(SRC_DIR)env $(SRC_DIR)get_next_line $(SRC_DIR)conv_type $(SRC_DIR)gc \

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "$(GREEN)libft Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)libft: make clean$(RESET)"

fclean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "$(YELLOW)libft: make fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re
