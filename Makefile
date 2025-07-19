NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = list_utils.c \
	  list_utils1.c \
	  list_utils2.c \
	  push_swap.c \
	  utils.c \
	  utils2.c
CC = cc
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "push_swap compiled successfully."

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "All executables removed."

re: fclean all

.PHONY: all clean fclean re