/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-damian.gil
** File description:
** random
*/

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int get_randint(int min, int max)
{
    int fd = open("/dev/random", O_RDONLY);
    int nb = 0;
    unsigned int diff = max - min;

    if (fd == -1)
        return 0;
    read(fd, &nb, 4);
    close(fd);

    nb = nb % (diff + 1);
    return nb + min;
}
