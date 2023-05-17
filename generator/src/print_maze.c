/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "myg.h"

void print_maze(dante_s *dante)
{
    for (int i = 0; dante->maze[i] != NULL; i++) {
        if (i == dante->y - 1)
            printf("%s", dante->maze[i]);
        else
            printf("%s\n", dante->maze[i]);
    }
}
