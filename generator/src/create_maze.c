/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "myg.h"
#include <time.h>

void malloc_maze(dante_s *dante)
{
    dante->maze = NULL;
    dante->maze = malloc(sizeof(char *) * (dante->y + 1));

    for (int i = 0; i < dante->y; i++) {
        dante->maze[i] = malloc(sizeof(char) * (dante->x + 1));
        dante->maze[i][dante->x] = '\0';
    }
    dante->maze[dante->y] = NULL;
}

void fill_maze_character(dante_s *dante, int i, int j)
{
    if (i == 0 || j == 0) {
        dante->maze[i][j] = '*';
    } else {
        dante->maze[i][j] = 'X';
    }
}

void fill_maze(dante_s *dante)
{
    for (int i = 0; i < dante->y; i++) {
        for (int j = 0; j < dante->x; j++) {
            fill_maze_character(dante, i, j);
        }
    }
    for (int i = 2; i < dante->y; i += 2) {
        for (int j = 2; j < dante->x; j += 2) {
            dante->maze[i][j] = '*';
        }
    }
}

int create_maze(char **arv, dante_s *dante, int type)
{
    dante->x = atoi(arv[1]);
    dante->y = atoi(arv[2]);
    dante->maze = NULL;
    srand(time(0));

    if (dante->x < 1 || dante->y < 1)
        return (84);
    malloc_maze(dante);
    fill_maze(dante);
    make_perfect(dante);

    if (type == 1)
        make_imperfect(dante);

    return (0);
}
