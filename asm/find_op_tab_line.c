/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** find_op_tab_line
*/

#include <stddef.h>
#include "format.h"
#include "op.h"

unsigned int find_op_tab_line(const char *line)
{
    size_t len = 0;
    unsigned int i = 0;

    for (; *line != '\0' && (*line == ' ' || *line == '\t'); line++);
    len = min(my_strlen_until(line, ' '), my_strlen_until(line, '\t'));
    for (i = 0; !op_t_is_null(&op_tab[i]); i++)
        if (!my_strncmp(line, op_tab[i].mnemonique, len))
            return i;
    return i;
}
