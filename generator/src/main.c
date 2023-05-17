/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "myg.h"

int main(int arc, char *arv[])
{
    dante_s *dante = malloc(sizeof(dante_s));
    if (check_error(arc, arv) == 84)
        return (84);
    return (start_dante(arc, arv, dante));
}
