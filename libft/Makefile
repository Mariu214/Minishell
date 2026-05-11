# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:01:59 by malaimo           #+#    #+#              #
#    Updated: 2026/05/07 17:00:18 by jdelmott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = $(PRINTF_FD) $(PRINTF) $(MEMORY) $(IS) $(GET_NEXT_LINE) $(GC) $(CONV_TYPE) $(ENV) $(STRING) \

CONV_TYPE = ft_atoi ft_itoa \

ENV = ft_getenv \

GC = ft_calloc_gc ft_delone_gc ft_error_gc ft_free_all_gc ft_free_tab_gc ft_gnl_gc ft_lstadd_gc \
	ft_malloc_gc ft_renew_gc ft_split_gc ft_split_sentence_gc ft_splitdup_gc ft_strdup_gc \
	ft_strjoin_gc ft_substr_gc ft_scan_gc ft_getenv_gc ft_join_one_gc ft_renew_one_gc ft_itoa_gc \

GET_NEXT_LINE = get_next_line gnl_lim \

IS = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_tolower ft_toupper is_there \

MEMORY = ft_bzero ft_calloc ft_memchr ft_memcpy ft_memmove ft_memset \

PRINTF = ft_printf ft_putchar ft_putnbr_base ft_putnbr_p ft_putnbr_u ft_putnbr ft_putstr \

PRINTF_FD = ft_printf_fd ft_putchar_fd ft_putendl_fd ft_putnbr_base_fd ft_putnbr_fd ft_putnbr_p_fd ft_putnbr_u_fd \
	ft_putstr_fd \

STRING = ft_strlen ft_strlcat ft_strlcpy ft_strchr ft_strrchr ft_strncmp ft_strnstr ft_strdup ft_substr \
	ft_strjoin ft_strtrim ft_split ft_strmapi ft_striteri ft_strnstr_back ft_strcmp free_tab \
	ft_split_sentence ft_splitlen ft_splitdup ft_scan ft_join_one ft_renew_one \

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
	@echo -e "$(GREEN)libft Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo -e "$(YELLOW)libft: make clean$(RESET)"

fclean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo -e "$(YELLOW)libft: make fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re
