/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "mys.h"
#include <stdlib.h>

int main(int arc, char *arv[])
{
    solver_s *solver = malloc(sizeof(solver_s));
    if (check_error(arc, arv) == 84)
        return (84);
    return (start_solver(arv, solver));
}
