/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** function returning a pointer to a copy of a str
*/

#include <stdlib.h>

int my_strlen(char *);

char *my_strcpy(char *src)
{
    int size = my_strlen(src);
    char *dest;
    if (my_strlen(src) > 0) {
        dest = malloc(sizeof(char) * (size + 1));
    } else {
        dest = malloc(sizeof(char) * 2);
    }
    for (int i = 0; i < size;  i++) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
    return dest;
}

char *my_strncpy(char *src, int n)
{
    int size = my_strlen(src), i;
    char *dest;
    dest = malloc(sizeof(char) * (n + 1));
    for (i = 0; i < size && i < n;  i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
