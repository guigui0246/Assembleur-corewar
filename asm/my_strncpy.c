/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** copy src in dest
*/

#include <stddef.h>

char *my_strncpy(char *dest, char const *src, size_t n)
{
    unsigned int i = 0;

    while (src[i] != '\0' || i < n) {
        dest[i] = src[i];
        i++;
    };
    dest[i] = '\0';
    return dest;
}
