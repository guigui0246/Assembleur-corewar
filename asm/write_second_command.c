/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** write_second_command
*/

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include "format.h"
#include "op.h"

static bool execute_loop(op_t *op, char const *const *arg,
    FILE *file, type_value_t *type_value)
{
    for (unsigned int i = 0; i < (unsigned int) op->nbr_args; i++, errno = 0) {
        if (op->type[i] & T_REG && is_reg(arg[i])) {
            write_reg(arg[i], file, type_value);
            continue;
        }
        if (op->type[i] & T_DIR && is_dir(arg[i])) {
            write_dir(arg[i], file, type_value);
            continue;
        }
        if (op->type[i] & T_IND && is_ind(arg[i])) {
            write_ind(arg[i], file, type_value);
            continue;
        }
        if (op->type[i] & T_LAB && is_lab_arg(arg[i])) {
            write_lab(arg[i], file, type_value);
            continue;
        }
        return false;
    }
    return true;
}

//Veirfy if it's live, fork lfork or zjump
static bool has_code_byte(const char *str)
{
    return !((!my_strcmp(str, "live")) || (!my_strcmp(str, "zjmp")) ||
        (!my_strcmp(str, "fork")) || (!my_strcmp(str, "lfork")));
}

static size_t cases(type_value_t tmp, size_t len)
{
    if (tmp == C_REG)
        len += REG_SIZE;
    if (tmp == C_DIR)
        len += DIR_SIZE;
    if (tmp == C_IND)
        len += IND_SIZE;
    return len;
}

static size_t try_write_types(FILE *file, type_value_t value, const char *str)
{
    type_value_t tmp = 0;
    size_t len = 0;

    for (unsigned int i = 0; i < MAX_ARGS_NUMBER; i++) {
        tmp = (value << ((MAX_ARGS_NUMBER * 2) - (2 * (i + 1))));
        tmp = (tmp >> ((MAX_ARGS_NUMBER - 1) * 2));
        len = cases(tmp, len);
    }
    if (!has_code_byte(str))
        return len;
    if (file == NULL)
        return len + sizeof(type_value_t);
    fseek(file, (long) -(len + 1), 1);
    fwrite(&value, sizeof(type_value_t), 1, file);
    fseek(file, (long) len, 1);
    return len + sizeof(type_value_t);
}

//verify and print what's found on the line
bool execute(size_t *len, unsigned int line_of_op_tab, char const *const *arg,
    FILE *file)
{
    op_t op = op_tab[line_of_op_tab];
    int zero = 0;
    type_value_t type_value = 0;

    if (file != NULL) {
        fwrite(&op.code, sizeof(op.code), 1, file);
        if (has_code_byte(op.mnemonique))
            fwrite(&zero, BYTE_SIZE, 1, file);
    }
    execute_loop(&op, arg, file, &type_value);
    (*len) += try_write_types(file, type_value, op.mnemonique);
    return true;
}
