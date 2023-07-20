/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** format
*/

#include <errno.h>
#include <stdbool.h>
#include "../includes/op.h"
#include "../includes/format.h"

static bool str_is_label(const char *str)
{
    unsigned int j = 0;

    for (unsigned int i = 0; str[j] != '\0'; i++) {
        if (LABEL_CHARS[i] == str[j]) {
            j++;
            i = 0;
        }
        if (LABEL_CHARS[i] == '\0')
            return false;
    }
    return true;
}

//Test if a string is a label
bool is_lab_arg(const char *arg)
{
    if (*arg == DIRECT_CHAR)
        arg++;
    if (*arg != LABEL_CHAR || !str_is_label(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    return true;
}
