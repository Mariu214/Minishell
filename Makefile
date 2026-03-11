C = cc
FLAGS = -Wall -Werror -Wextra
NAME = test
LIBFT_DIR = ./libft
LIBFT =$(LIBFT_DIR)/libft.a
OBJ = test.o

all: $(LIBFT) test

%.o: %.c
	$(C) $(FLAGS) -c -g $< -o $@

test: test.o
	$(C) $(FLAGS) -g3 test.o $(LIBFT) -o test

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f test
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
