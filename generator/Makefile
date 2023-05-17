##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = generator

SRC = ./src/main.c \
	  ./src/check_error.c \
	  ./src/create_maze.c \
	  ./src/start_dante.c \
	  ./src/make_perfect_imperfect.c \
	  ./src/print_maze.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -I ./include/ -W -Wall -Wextra

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
