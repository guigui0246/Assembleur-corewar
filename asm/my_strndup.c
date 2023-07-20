/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** dupplicate an array
*/

#include <stdlib.h>
#include <sys/param.h>
#include "format.h"

char *my_strndup(char const *src, size_t n)
{
    char *to_return = NULL;

    if (my_strlen(src) < 1 || n < 1) {
        to_return = malloc_empty(sizeof(char));
        to_return[0] = '\0';
        return to_return;
    };
    to_return = malloc_empty(sizeof(char) * min(my_strlen(src) + 1, n + 1));
    for (unsigned int i = 0; i < my_strlen(src) && i < n; i++)
        to_return[i] = src[i];
    to_return[min(my_strlen(src), n)] = '\0';
    return to_return;
}
