NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c stack_func.c stack_func_1.c stack_func_2.c stack_func_3.c sort.c sort1.c sort2.c \
utils.c split.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re