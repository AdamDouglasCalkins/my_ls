NAME = my_ls

SRC = main.c start_list.c alter_list.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = /bin/rm -f

$(NAME):
	$(CC) -o $(NAME) $(CFLAGS) $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)

all: $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY : all, re, clean, fclean
