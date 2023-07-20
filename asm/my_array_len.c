/*
** EPITECH PROJECT, 2023
** my_array_len.c
** File description:
** return the lenght of an array
*/
#include <stddef.h>
#include <stdbool.h>

size_t my_array_len(void **ptr)
{
    if (ptr == NULL)
        return 0;
    for (unsigned int i = 0;; i++)
        if (ptr[i] == NULL)
            return i;
}
