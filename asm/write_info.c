/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** write_reg
*/

#include <stdio.h>
#include "format.h"

void write_reg(const char *str, FILE *file, type_value_t *type_value)
{
    int nbr = 0;

    if (file == NULL || str == NULL)
        return;
    (*type_value) = ((*type_value) << 2) + C_REG;
    nbr = my_getnbr(&str[1]);
    nbr = TO_BIG(nbr);
    fwrite(&nbr, BYTE_SIZE, REG_SIZE, file);
}

void write_dir(const char *str, FILE *file, type_value_t *type_value)
{
    int nbr = 0;

    if (file == NULL || str == NULL)
        return;
    (*type_value) = ((*type_value) << 2) + C_DIR;
    nbr = my_getnbr(&str[1]);
    nbr = TO_BIG(nbr);
    fwrite(&nbr, BYTE_SIZE, DIR_SIZE, file);
}

void write_ind(const char *str, FILE *file, type_value_t *type_value)
{
    int nbr = 0;

    if (file == NULL || str == NULL)
        return;
    (*type_value) = ((*type_value) << 2) + C_IND;
    nbr = my_getnbr(str);
    nbr = TO_BIG(nbr);
    fwrite(&nbr, BYTE_SIZE, IND_SIZE, file);
}

void write_lab(const char *str, FILE *file, type_value_t *type_value)
{
    int nbr = 0;
    size_t size = IND_SIZE;
    unsigned int pos = 1;

    if (file == NULL || str == NULL)
        return;
    pos += (str[1] == DIRECT_CHAR);
    if (str[1] == DIRECT_CHAR)
        size = DIR_SIZE;
    if (str[1] == DIRECT_CHAR)
        (*type_value) = ((*type_value) << 2) + C_DIR;
    else
        (*type_value) = ((*type_value) << 2) + C_IND;
    nbr = my_getnbr(&str[pos]);
    nbr = TO_BIG(nbr);
    fwrite(&nbr, BYTE_SIZE, size, file);
}
