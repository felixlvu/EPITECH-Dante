/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "myg.h"

void make_imperfect_rand(dante_s *dante, int i, int j)
{
    int temp = 0;

    temp = rand() % 2;
    if (temp == 0) {
        if (j < dante->x - 1) {
            dante->maze[i][j + 1] = '*';
        }
    } else {
        if (i < dante->y - 1) {
            dante->maze[i + 1][j] = '*';
        }
    }
    dante->maze[dante->y - 1][dante->x - 2] = '*';
    dante->maze[dante->y - 2][dante->x - 1] = '*';
}

void make_imperfect(dante_s *dante)
{
    int i = 0;
    int j = 0;

    for (i = 1; i < dante->y; i += 2) {
        for (j = 1; j < dante->x; j += 2) {
            make_imperfect_rand(dante, i, j);
        }
    }
}

void make_perfect_rand(dante_s *dante, int i, int j, int temp)
{
    temp = rand () % 2;
    if (temp == 0 && dante->x > 1 && dante->y > 1) {
        dante->maze[i - 1][j] = '*';
        dante->maze[i][j - 1] = 'X';
    } else if (dante->x > 1 && dante->y > 1){
        dante->maze[i][j - 1] = '*';
        dante->maze[i - 1][j] = 'X';
    }
}

void make_perfect(dante_s *dante)
{
    int temp = 0;

    temp = rand () % 2;
    if (dante->x > 1 && dante->y > 1)
        dante->maze[dante->y - 1][dante->x - 1] = '*';
    if (temp == 0 && dante->x > 1 && dante->y > 1)
        dante->maze[dante->y - 1][dante->x - 2] = '*';
    else if (dante->x > 1 && dante->y > 1)
        dante->maze[dante->y - 2][dante->x - 1] = '*';
    for (int i = 2; i < dante->y; i += 2) {
        for (int j = 2; j < dante->x; j += 2) {
            make_perfect_rand(dante, i, j, temp);
        }
    }
    if (2 == dante->y || 2 == dante->x)
        make_perfect_rand(dante, 1, 1, temp);
}
