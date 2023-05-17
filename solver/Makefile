##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = solver

SRC = ./src/main.c \
	  ./src/check_error.c \
	  ./src/start_solver.c \
	  ./src/solver_maze.c \
	  ./src/print_maze.c \
	  ./src/queue.c \
	  ./src/find_path.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -I ./include/ -W -Wall -Wextra -g3

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
