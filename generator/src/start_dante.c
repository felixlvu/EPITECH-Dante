/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "myg.h"

int start_dante(int arc, char **arv, dante_s *dante)
{
    int ret = 0;

    if (arc == 4) {
        ret = create_maze(arv, dante, 0);
        if (ret == 84)
            return (84);
        print_maze(dante);
    } else {
        ret = create_maze(arv, dante, 1);
        if (ret == 84)
            return (84);
        print_maze(dante);
    }
    return 0;
}
