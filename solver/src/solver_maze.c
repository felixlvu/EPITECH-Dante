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

int **malloc_visited(solver_s *solver)
{
    int **visited = malloc(sizeof(int *) * solver->y);
    for (int i = 0; i != solver->y; i++) {
        visited[i] = malloc(sizeof(int) * solver->x);
        memset(visited[i], 0, (sizeof(int) * solver->x));
    }
    return (visited);
}

position **malloc_parent(solver_s *solver)
{
    position **parent = malloc(sizeof(position *) * solver->y);
    for (int i = 0; i != solver->y; i++) {
        parent[i] = malloc(sizeof(position) * solver->x);
        memset(parent[i], -1, (sizeof(position) * solver->x));
    }
    return (parent);
}

int solver_maze(char **maze, solver_s *solver)
{
    solver->path_len = 0;
    position start = {0, 0};
    position end = {(solver->y - 1), (solver->x - 1)};
    position path[solver->y * solver->x];
    solver->path_len = find_path(start, end, path, solver);

    if (solver->path_len == 0) {
        printf("No path found\n");
    } else {
        print_maze(maze, solver, path);
    }
    return 0;
}
