/*
** EPITECH PROJECT, 2022
** myg.r
** File description:
** myg.r
*/

#ifndef MYG_H
    #define MYG_H

typedef struct dante_s {
    char **maze;
    int x;
    int y;
} dante_s;

    #include <stdlib.h>
    #include <stdio.h>

    int main(int arc, char *arv[]);
    int check_error(int arc, char **arv);
    int start_dante(int arc, char **arv, dante_s *dante);
    int create_maze(char **arv, dante_s *dante, int type);
    void make_perfect(dante_s *dante);
    void make_imperfect(dante_s *dante);
    void print_maze(dante_s *dante);
#endif
