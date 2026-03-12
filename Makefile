# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:01:59 by malaimo           #+#    #+#              #
#    Updated: 2026/03/10 16:04:31 by jdelmott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FILES = main \
      
SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Werror -Wextra

INCLUDE =  minishell.h

SRC = $(addprefix $(SRC_DIR), $(addsuffix) .c, $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

LIBFT_DIR = ./libft
LIBFT =$(LIBFT_DIR)/libft.a

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \033[33m
RESET = \033[0;39m

$(OBJF):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -Iincludes -lreadline -g3 -o $(NAME)
	@echo "$(GREEN)Minishell Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)libft: make clean$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)libft: make fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re
