/*
** EPITECH PROJECT, 2022
** mys.r
** File description:
** mys.r
*/

#ifndef MYS_H
    #define MYS_H

typedef struct solver_s {
    char **maze;
    char **maze_solve;
    int **visited;
    int path_len;
    int maxlen;
    int x;
    int y;
    int prtx;
    int prty;
} solver_s;

typedef struct {
    int row;
    int col;
} position;

typedef struct node {
    position data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} kueue;

    int main(int arc, char *arv[]);
    int check_error(int arc, char *arv[]);
    int start_solver(char **arv, solver_s *solver);
    int solver_maze(char **maze, solver_s *solver);
    void print_maze(char **maze, solver_s *solver, position *path);
    int is_queue_empty(kueue* queue);
    position dequeue(kueue* queue);
    void enqueue(kueue* queue, position data);
    int find_path(position start, position end,
    position* path, solver_s *solver);
    position **malloc_parent(solver_s *solver);
    int **malloc_visited(solver_s *solver);
    kueue* create_queue(void);
#endif
