/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** fill_line
*/

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "format.h"

static bool fill_lines_in(file_info_t *sfile, char *str)
{
    if (my_strlen(str) < 3)
        return true;
    while (*str == ' ' || *str == '\t')
        str++;
    if (!my_strncmp(str, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING))) {
        str = &str[my_strlen(NAME_CMD_STRING)];
        while (*str == ' ' || *str == '\t' || *str == '\"')
            str++;
        my_strcpy_until(sfile->name, str, '\"');
        return true;
    }
    if (!my_strncmp(str, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))) {
        str = &str[my_strlen(COMMENT_CMD_STRING)];
        while (*str == ' ' || *str == '\t' || *str == '\"')
            str++;
        my_strcpy_until(sfile->comment, str, '\"');
        return true;
    }
    return false;
}

bool last_fill_lines(file_info_t *sfile, char **str)
{
    if (!pointer_add_to_list((void ***) &sfile->lines, str)) {
        rm_2d_array(sfile->lines);
        return false;
    }
    return true;
}

void fill_lines_shorten(char *str, ssize_t n)
{
    if (str[n - 1] == '\n')
        str[n - 1] = '\0';
    if (str[my_strlen_until(str, COMMENT_CHAR)] == COMMENT_CHAR)
        str[my_strlen_until(str, COMMENT_CHAR)] = '\0';
}

bool fill_lines(file_info_t *sfile, FILE *rfile)
{
    char *str = NULL;
    size_t m = 0;
    sfile->lines = malloc_empty(sizeof(char *) * 2);

    if (sfile->lines == NULL)
        return false;
    for (ssize_t n = 0; n != -1; n = getline(&str, &m, rfile)) {
        if (n < 3)
            continue;
        fill_lines_shorten(str, n);
        if (fill_lines_in(sfile, str)) {
            free(str);
            (str) = NULL;
            continue;
        }
        if (!last_fill_lines(sfile, &str))
            return false;
    }
    return !is_all_empty(sfile->name, PROG_NAME_LENGTH)
        && !is_all_empty(sfile->comment, COMMENT_LENGTH);
}
