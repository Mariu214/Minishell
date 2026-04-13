# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:01:59 by malaimo           #+#    #+#              #
#    Updated: 2026/04/13 15:19:58 by jdelmott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FILES = main heredoc exec_shell parsing_heredoc signals_handlers parsing_pipe parsing cd unset export \
		open_files redirection parsing_cmd dollar ft_shellerror_gc echo lexer define_type \
		init_list ft_add_node ft_print_lex lexer_quotes lexer_redirections new_parsing parsing_built_in \
		lexer_cmd pipenb \

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

vpath %.c $(SRC_DIR) $(SRC_DIR)parsing $(SRC_DIR)execution $(SRC_DIR)pipe $(SRC_DIR)redirection $(SRC_DIR)hardcoded $(SRC_DIR)misc $(SRC_DIR)list $(SRC_DIR)lexer

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
