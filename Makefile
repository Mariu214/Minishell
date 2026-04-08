# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:01:59 by malaimo           #+#    #+#              #
#    Updated: 2026/04/01 14:58:07 by malaimo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FILES = main heredoc exec_shell parsing_heredoc signals_handlers parsing_pipe parsing cd unset export \
		open_files redirection lexer lexer_utils parsing_cmd dollar ft_shellerror_gc echo new_lexer \
		init_list \

SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Werror -Wextra -O0

INCLUDE =  include/minishell.h

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

LIBFT_DIR = ./libft
LIBFT =$(LIBFT_DIR)/libft.a

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \033[33m
RESET = \033[0;39m

$(OBJF):
	@mkdir -p $(OBJ_DIR)

vpath %.c $(SRC_DIR) $(SRC_DIR)parsing $(SRC_DIR)execution $(SRC_DIR)pipe $(SRC_DIR)redirection $(SRC_DIR)hardcoded $(SRC_DIR)misc

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -Iinclude -lreadline -g3 -o $(NAME)
	@echo -e "$(GREEN)Minishell Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo -e "$(YELLOW)minishell: make clean$(RESET)"

fclean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo -e "$(YELLOW)minishell: make fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re
