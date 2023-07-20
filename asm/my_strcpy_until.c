/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** copy src in dest
*/

char *my_strcpy_until(char *dest, char const *src, char end)
{
    int i = 0;

    while (src[i] != '\0' && src[i] != end) {
        dest[i] = src[i];
        i++;
    };
    dest[i] = '\0';
    return dest;
}
