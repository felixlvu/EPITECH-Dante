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

int check_error(int arc, char *arv[])
{
    int fd = 0;

    if (arc != 2)
        return (84);
    fd = open(arv[1], O_RDONLY);
    if (fd == -1) {
        close(fd);
        return (84);
    }
    close(fd);
    return (0);
}
