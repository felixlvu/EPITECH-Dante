/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "myg.h"
#include <string.h>

int check_error(int arc, char **arv)
{
    if (arc < 3 || arc > 4) {
        printf("Usage: ./generator x y [perfect]\n");
        return (84);
    }
    if (atoi(arv[1]) == 0 || atoi(arv[2]) == 0)
        return (84);
    if (arc == 4 && strcmp(arv[3], "perfect") != 0) {
        printf("Wrong third argument.\n");
        return (84);
    }
    return (0);
}
