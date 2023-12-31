/*
** EPITECH PROJECT, 2023
** lib my
** File description:
** add_ptr_to_list
*/

#include <stdbool.h>
#include <stdlib.h>
#include "format.h"

bool pointer_add_to_list(void ***arr, char **ptr)
{
    void **new_arr = NULL;
    size_t len = my_array_len(*arr);

    new_arr = malloc_empty(sizeof(void *) * (len + 2));
    if (new_arr == NULL) {
        free(*ptr);
        return false;
    }
    for (unsigned int i = 0; i <= len; i++) {
        new_arr[i] = (*arr)[i];
    }
    for (; **ptr != '\t' && **ptr != ' ' && **ptr != '\0'; (*ptr)++);
    new_arr[len] = my_strdup(*ptr);
    free(*ptr);
    (*ptr) = NULL;
    if (new_arr[len] == NULL)
        return false;
    free(*arr);
    (*arr) = new_arr;
    return true;
}
