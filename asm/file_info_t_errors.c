/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** file_info_t_errors
*/

#include "format.h"

void file_info_t_errors(file_info_t *sfile)
{
    if (is_all_empty(sfile->name, PROG_NAME_LENGTH))
        errno = NO_NAME;
    if (errno_error_test(1))
        return;
    if (is_all_empty(sfile->comment, COMMENT_LENGTH))
        errno = NO_COMMENT;
    errno_error_test(2);
}
