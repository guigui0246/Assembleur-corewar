/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** asm
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include "format.h"

static int help(void)
{
    write(2, HELP_ASM, my_strlen(HELP_ASM));
    return 0;
}

static bool has_help(unsigned int ac, char const *const *av)
{
    for (unsigned int i = 0; i < ac; i++) {
        if ((!my_strcmp(av[i], "-h")) || (!my_strcmp(av[i], "--help")))
            return true;
    }
    return false;
}

int main(int ac, char const *const *av)
{
    FILE *file = NULL;

    if (has_help((unsigned int) ac, av))
        return help();
    if (ac != 3) {
        write(2, "\e[30m\e[47mWrong number of arguments !\e[0m\n", 42);
        return 84;
    }
    file = fopen(av[1], "r");
    if (file == NULL) {
        write(2, "Fopen failed\n", 13);
        return 84;
    }
    if (!main_asm(file, av[2]))
        return 84;
    return 0;
}

bool main_asm_condition(file_info_t *sfile, FILE *rfile)
{
    if (!fill_lines(sfile, rfile)) {
        rm_2d_array(sfile->lines);
        fclose_protected(rfile);
        file_info_t_errors(sfile);
        return false;
    }
    return true;
}

bool main_asm(FILE *rfile, char const *wfilepath)
{
    file_info_t sfile = {0};
    FILE *wfile = NULL;

    if (!main_asm_condition(&sfile, rfile))
        return false;
    fclose_protected(rfile);
    if (!asm_loop((const char *const *) sfile.lines, NULL, &sfile)) {
        rm_2d_array(sfile.lines);
        return false;
    }
    wfile = fopen(wfilepath, "w");
    if (wfile == NULL) {
        write(2, "Fopen failed\n", 13);
        rm_2d_array(sfile.lines);
        return false;
    }
    asm_loop((const char *const *) sfile.lines, wfile, &sfile);
    fclose_protected(wfile);
    rm_2d_array(sfile.lines);
    return true;
}
