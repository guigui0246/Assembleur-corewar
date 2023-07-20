/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** dupplicate an array
*/

#include <stdlib.h>
#include "format.h"

char *my_strdup(char const *src)
{
    char *to_return = NULL;

    if (my_strlen(src) < 1) {
        to_return = malloc_empty(sizeof(char));
        to_return[0] = '\0';
        return to_return;
    };
    to_return = malloc_empty(sizeof(char) * (my_strlen(src) + 1));
    for (unsigned int i = 0; i <= my_strlen(src); i++)
        to_return[i] = src[i];
    to_return[my_strlen(src)] = '\0';
    return to_return;
}
