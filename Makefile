NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = list_utils.c \
	  list_utils1.c \
	  sortbig.c \
	  sortlittle.c \
	  utils.c \
	  utils1.c \
	  split.c \
	  push_swap.c 
CC = cc
OBJ = $(SRC:.c=.o)
LIBFT = ./Libft/libft.a

all: $(NAME)

$(NAME):$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "push_swap compiled successfully."

$(LIBFT):
	$(MAKE) -C ./Libft bonus

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./Libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./Libft fclean
	@echo "All executables removed."

re: fclean all

.PHONY: all clean fclean re