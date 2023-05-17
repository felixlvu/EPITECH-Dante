/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "mys.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_path(solver_s *solver, position *path, int found)
{
    int k = 0;

    for (k = 0; k < solver->path_len; k++) {
        if (path[k].row == solver->prty &&
        path[k].col == solver->prtx) {
            printf("o");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("*");
    }
}

void print_character(char **maze, solver_s *solver, position *path)
{
    int found = 0;

    if (maze[solver->prty][solver->prtx] == '*') {
        print_path(solver, path, found);
    } else {
        printf("X");
    }
}

void print_maze(char **maze, solver_s *solver, position *path)
{
    solver->prty = 0;
    solver->prtx = 0;
    for (solver->prty = 0; solver->prty < solver->y; solver->prty++) {
        for (solver->prtx = 0; solver->prtx < solver->x; solver->prtx++) {
            print_character(maze, solver, path);
        }
        if (solver->prty + 1 != solver->y)
            printf("\n");
    }
}
