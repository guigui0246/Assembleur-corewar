/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** write_command
*/

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include "format.h"
#include "op.h"

static unsigned int last_return(unsigned int i, char const *line)
{
    i += (line[i] == ',');
    for (; line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'); i++);
    return i;
}

static unsigned int fill_args_loops(unsigned int i, char const *line)
{
    for (; line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'); i++);
    for (; line[i] != '\0' && line[i] != ' ' && line[i] != '\t'; i++);
    for (; line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'); i++);
    return i;
}

static bool fill_args(char *arg[MAX_ARGS_NUMBER], char const *line,
    unsigned int line_of_op_tab)
{
    unsigned int i = 0;
    unsigned int j = 0;
    size_t len[3] = {0, 0, 0};

    i = fill_args_loops(i, line);
    for (; line[i] != '\0' && j < MAX_ARGS_NUMBER; j++) {
        len[0] = my_strlen_until(&line[i], ',');
        len[1] = my_strlen_until(&line[i], ' ');
        len[2] = my_strlen_until(&line[i], '\t');
        arg[j] = my_strndup(&line[i], min(min(len[0], len[1]), len[2]));
        if (i + min(min(len[0], len[1]), len[2]) > my_strlen(line))
            break;
        i += min(min(len[0], len[1]), len[2]);
        i = last_return(i, line);
    }
    if (op_tab[line_of_op_tab].nbr_args != (char) j) {
        errno = WRONG_ARG_NUMBER;
        return false;
    }
    return true;
}

static void write_header(file_info_t *sfile, FILE *file, size_t len)
{
    header_t header = {0};

    if (file == NULL)
        return;
    fseek(file, 0, 0);
    header.magic = TO_BIG(COREWAR_EXEC_MAGIC);
    my_strcpy_until(header.prog_name, &sfile->name
        [sfile->name[0] == '\"'], '\"');
    my_strcpy_until(header.comment, &sfile->comment
        [sfile->comment[0] == '\"'], '\"');
    header.prog_size = TO_BIG(len);
    fwrite(&header, sizeof(header_t), 1, file);
    fseek(file, 0, 2);
}

//Loop to know how to call errno_error_test
bool asm_loop(const char *const *file_lines, FILE *file, file_info_t *sfile)
{
    unsigned int line_of_op_tab = 0;
    char *arg[MAX_ARGS_NUMBER] = {0};
    size_t len = 0;

    write_header(sfile, file, len);
    for (unsigned int i = 0; file_lines[i] != NULL; i++) {
        line_of_op_tab = find_op_tab_line(file_lines[i]);
        if (!fill_args(arg, file_lines[i], line_of_op_tab)) {
            errno_error_test(i + 3);
            return false;
        }
        if (!execute(&len, line_of_op_tab, (char const *const *) arg, file)) {
            errno_error_test(i + 3 + 20000);
            return false;
        }
    }
    write_header(sfile, file, len);
    return true;
}
