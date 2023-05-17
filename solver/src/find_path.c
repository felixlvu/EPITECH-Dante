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

void move_path_left(position **parent, kueue* queue,
position current, solver_s *solver)
{
    if (current.row > 0 && solver->maze[current.row - 1][current.col] == '*' &&
    !solver->visited[current.row - 1][current.col]) {
        position next = {current.row - 1, current.col};
        parent[next.row][next.col] = current;
        enqueue(queue, next);
    }
    if (current.col > 0 && solver->maze[current.row][current.col - 1] == '*' &&
    !solver->visited[current.row][current.col - 1]) {
        position next = {current.row, current.col - 1};
        parent[next.row][next.col] = current;
        enqueue(queue, next);
    }
}

void move_path_right(position **parent,
kueue* queue, position current, solver_s *solver)
{
    if (current.row < solver->maxlen - 1 &&
    solver->maze[current.row + 1] != NULL &&
    solver->maze[current.row + 1][current.col] == '*' &&
    !solver->visited[current.row + 1][current.col]) {
        position next = {current.row + 1, current.col};
        parent[next.row][next.col] = current;
        enqueue(queue, next);
    }
    if (current.col < solver->maxlen - 1 &&
    solver->maze[current.row][current.col + 1] == '*' &&
    !solver->visited[current.row][current.col + 1]) {
        position next = {current.row, current.col + 1};
        parent[next.row][next.col] = current;
        enqueue(queue, next);
    }
}

void move_for_path(kueue* queue, solver_s *solver,
position **parent, position end)
{
    while (!is_queue_empty(queue)) {
        position current = dequeue(queue);
        if (current.row == end.row && current.col == end.col)
            break;
        if (solver->visited[current.row][current.col])
            continue;
        solver->visited[current.row][current.col] = 1;
        move_path_right(parent, queue, current, solver);
        move_path_left(parent, queue, current, solver);
    }
}

int find_path(position start, position end, position* path, solver_s *solver)
{
    solver->visited = malloc_visited(solver);
    int path_len = 0;
    int i = 0;
    kueue* queue = create_queue();
    enqueue(queue, start);
    position **parent = malloc_parent(solver);
    move_for_path(queue, solver, parent, end);
    position current = end;
    while (current.row != - 1 && current.col != - 1) {
        path[path_len++] = current;
        current = parent[current.row][current.col];
    }
    if (path_len > 0) {
        for (i = 0; i < path_len / 2; i++) {
            position temp = path[i];
            path[i] = path[path_len - i - 1];
            path[path_len - i - 1] = temp;
        }
    }
    return path_len;
}
