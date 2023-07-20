/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** op_t_is_null
*/

#include <stddef.h>
#include <stdbool.h>
#include "op.h"

bool op_t_is_null(const op_t *op)
{
    return (op->mnemonique == NULL || op->nbr_args > MAX_ARGS_NUMBER);
}
