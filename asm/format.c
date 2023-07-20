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

static bool str_is_digit(const char *str)
{
    for (unsigned int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}

bool is_dir(const char *arg)
{
    if (*arg != DIRECT_CHAR || !str_is_digit(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    return true;
}

//Test if a string is a register
bool is_reg(const char *arg)
{
    if (*arg != 'r' || !str_is_digit(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    if (my_getnbr(&arg[1]) < 1 || my_getnbr(&arg[1]) > REG_NUMBER) {
        errno = UNKNOWN_REGISTER;
        return false;
    }
    return true;
}

//Test if a string is a indirect number
bool is_ind(const char *arg)
{
    if (!str_is_digit(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    return true;
}
