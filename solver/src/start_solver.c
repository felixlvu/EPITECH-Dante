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

void find_len_maze(solver_s *solver)
{
    int x = 0;
    int y = 0;

    for (y = 0; solver->maze[y] != NULL; y++) {
        for (x = 0; solver->maze[y][x] != '\0'; x++);
    }
    solver->x = x;
    solver->y = y;
    if (x < y)
        solver->maxlen = y;
    else
        solver->maxlen = x;
}

void fill_maze(char **arv, solver_s *solver, struct stat sfile, char *buffer)
{
    char *token = NULL;
    int i = 0;

    solver->maze = malloc(sizeof(char *) * sfile.st_size + 1);
    token = strtok(buffer, "\n\0");
    while (token != NULL) {
        solver->maze[i] = token;
        i++;
        token = strtok(NULL, "\n\0");
    }
    solver->maze[i] = NULL;
}

int open_maze(char **arv, solver_s *solver)
{
    struct stat sfile;
    stat(arv[1], &sfile);
    char *buffer = NULL;
    int fd = 0;

    buffer = malloc(sizeof(char) * sfile.st_size + 1);
    buffer[sfile.st_size] = '\0';
    fd = open(arv[1], O_RDONLY);
    fd = read(fd, buffer, sfile.st_size);
    if (fd == -1 || sfile.st_size == 0) {
        close(fd);
        return (84);
    }
    fill_maze(arv, solver, sfile, buffer);
    close(fd);

    return (0);
}

int start_solver(char **arv, solver_s *solver)
{
    if (open_maze(arv, solver) == 84)
        return (84);
    find_len_maze(solver);

    solver_maze(solver->maze, solver);
    return (0);
}
