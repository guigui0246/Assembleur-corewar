/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** format
*/

#ifndef FORMAT_H_
    #define FORMAT_H_

    #include <stdbool.h>
    #include <errno.h>
    #include <stdio.h>
    #include "op.h"
    #include <sys/param.h>
    #include <endian.h>

    #ifndef ERRNO_ASM_NAMES
        #define ERRNO_ASM_NAMES
        #define WRONG_ARG_NUMBER E2BIG
        #define WRONG_ARG EINVAL
        #define UNKNOWN_REGISTER EFAULT
        #define NO_COMMENT ENOMSG
        #define NO_NAME ENOKEY
    #endif

    #ifndef BYTE_SIZE
        #define BYTE_SIZE 1UL
    #endif

    #ifndef min
        #define min(a, b) MIN(a, b)
    #endif
    #ifndef max
        #define max(a, b) MAX(a, b)
    #endif

    #if __BYTE_ORDER == __LITTLE_ENDIAN
        #ifndef TO_BIG
            #define TO_BIG1(a) (((a) & 0xff) << 24)
            #define TO_BIG2(a) (((a) & 0xff00) << 8)
            #define TO_BIG3(a) (((a) & 0xff0000) >> 8)
            #define TO_BIG4(a) (((a) & 0xff000000) >> 24)
            #define TO_BIG(a) TO_BIG1(a) | TO_BIG2(a) | TO_BIG3(a) | TO_BIG4(a)
            #define TO_LIT(a) (a)
            #define BIG_TO_MEM(a) TO_BIG(a)
            #define LIT_TO_MEM(a) TO_LIT(a)
        #endif
    #elif __BYTE_ORDER == __BIG_ENDIAN
        #ifndef TO_BIG
            #define TO_BIG(a) (a)
            #define TO_LIT1(a) (((a) & 0xff) << 24)
            #define TO_LIT2(a) (((a) & 0xff00) << 8)
            #define TO_LIT3(a) (((a) & 0xff0000) >> 8)
            #define TO_LIT4(a) (((a) & 0xff000000) >> 24)
            #define TO_LIT(a) TO_LIT1(a) | TO_LIT2(a) | TO_LIT3(a) | TO_LIT4(a)
            #define BIG_TO_MEM(a) TO_BIG(a)
            #define LIT_TO_MEM(a) TO_LIT(a)
        #endif
    #endif

typedef struct type_of_args_s type_of_args_t;

struct type_of_args_s{
    args_type_t args[4];
    type_of_args_t *next;
};

    #if (MAX_ARGS_NUMBER < 5)
        #ifndef TYPE_VALUE_DEF
            typedef __uint8_t type_value_t;
            //defined as 8bits
            #define TYPE_VALUE_DEF
        #endif
    #endif
    #if (MAX_ARGS_NUMBER < 9)
        #ifndef TYPE_VALUE_DEF
            typedef __uint16_t type_value_t;
            //defined as 16bits
            #define TYPE_VALUE_DEF
        #endif
    #endif
    #if (MAX_ARGS_NUMBER < 17)
        #ifndef TYPE_VALUE_DEF
            typedef __uint32_t type_value_t;
            //defined as 32bits
            #define TYPE_VALUE_DEF
        #endif
    #endif
    #if (MAX_ARGS_NUMBER < 33)
        #ifndef TYPE_VALUE_DEF
            typedef __uint64_t type_value_t;
            //defined as 64bits
            #define TYPE_VALUE_DEF
        #endif
    #endif

    #define HELP_ASM "Asm in help mode : printing to error output\n\n"\
    "./asm asm_file cor_file\n"\
    "ARGUMENTS:\n"\
    "    asm_file    The file you coded in asm\n"\
    "    cor_file    The file that will have the compiled code\n\n"\
    "OPTIONS:\n"\
    "    -h | --help Print this help message\n\n"\
    "Can also be used main_asm(FILE *read_file, const char *write_filepath)\n"\
    "    read_file   the file to read from with the pointer on the start\n"\
    "    write_file  path the pathto the file to write to\n\n"\
    "RETURN VALUES:\n"\
    "    0           No errors occured\n"\
    "    84          Some errors occured, in that case errno is set :\n"\
    "        E2BIG   wrong number of arguments\n"\
    "        EINVAL  wrong argument or not allowed here\n"\
    "        EFAULT  register unkwnown or not in allowed range\n"\
    "        ENOMSG  No comment were found\n"\
    "        ENOKEY  No name were found\n"\
    "        errno can also be set for one of the values of :\n"\
    "            malloc\n"\
    "            getline\n"\
    "            fclose\n"\
    "            free\n"\
    "            fseek\n"\
    "            write\n"\
    "            fwrite\n"\
    "            open\n"\
    "            close\n"\
    "            read\n"\
    "            fopen\n\n"

typedef struct {
    char name[PROG_NAME_LENGTH];
    char comment[COMMENT_LENGTH];
    char **lines;
} file_info_t;

bool main_asm(FILE *rfile, char const *wfilepath);
bool asm_loop(const char *const *file_lines, FILE *file, file_info_t *sfile);
bool execute(size_t *len, unsigned int line_of_op_tab, char const *const *arg,
    FILE *file);
bool is_dir(const char *arg);
bool is_reg(const char *arg);
bool is_ind(const char *arg);
bool is_lab_arg(const char *arg);
bool fill_lines(file_info_t *sfile, FILE *rfile);
bool errno_error_test(unsigned int line);
unsigned int find_op_tab_line(const char *line);
bool op_t_is_null(const op_t *op);
void write_reg(const char *str, FILE *file, type_value_t *type_value);
void write_dir(const char *str, FILE *file, type_value_t *type_value);
void write_ind(const char *str, FILE *file, type_value_t *type_value);
void write_lab(const char *str, FILE *file, type_value_t *type_value);
void file_info_t_errors(file_info_t *sfile);

//lib my
char *my_strncpy(char *dest, char const *src, size_t n);
int my_strlen_until(char const *str, char c);
bool pointer_add_to_list(void ***arr, char **ptr);
int fclose_protected(FILE *flux);
int get_randint(int min, int max);
size_t my_strlen(char const *str);
char *my_strnbr_base(int nbr, char const *base);
void *malloc_empty(size_t size);
int my_strncmp(const char* s1, const char* s2, int n);
size_t my_array_len(void *ptr);
char *my_strcpy(char *dest, char const *src);
void rm_2d_array(char **map);
int my_getnbr(char const *str);
char *my_strdup(char const *src);
char *my_strndup(char const *src, size_t n);
int my_strcmp(const char* s1, const char* s2);
bool is_all_empty(void *ptr, size_t size_in_byte);
char *my_strcpy_until(char *dest, char const *src, char end);

#endif
