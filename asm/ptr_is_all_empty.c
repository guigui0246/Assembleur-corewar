/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** ptr_is_all_empty
*/

#include <stddef.h>
#include <stdbool.h>

static bool is_all_empty_char(char *ptr, size_t size_in_byte)
{
    for (unsigned int i = 0; i < size_in_byte; i++)
        if (ptr[i])
            return false;
    return true;
}

bool is_all_empty(void *ptr, size_t size_in_byte)
{
    return is_all_empty_char((char *) ptr, size_in_byte);
}
