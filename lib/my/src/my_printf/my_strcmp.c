/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** function that compares string and return which one is "higher"
*/

#include <stdlib.h>

char *my_strncpy(char const *src, int n);
int my_strlen(char const *);

int my_comp_char(char a, char b)
{
    return (int)((unsigned char)a - (unsigned char)b);
}

int my_strcmp(char const *s1, char const *s2)
{
    int s1_size = my_strlen(s1), s2_size = my_strlen(s2);
    int size_creation = 0, cmp = 0;
    char *s1_c, *s2_c;
    if (s1_size >= s2_size)
        size_creation = s1_size;
    else
        size_creation = s2_size;
    s1_c = my_strncpy(s1, size_creation);
    s2_c = my_strncpy(s2, size_creation);
    for (int i = 0; i < size_creation; i++) {
        if (my_comp_char(s1_c[i], s2_c[i]) != 0) {
            cmp = my_comp_char(s1_c[i], s2_c[i]);
            i = size_creation;
        }
    }
    free(s1_c);
    free(s2_c);
    return cmp;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_size = my_strlen(s1), s2_size = my_strlen(s2);
    int size_creation = 0, cmp = 0;
    char *s1_c, *s2_c;
    if (s1_size >= s2_size)
        size_creation = s1_size;
    else
        size_creation = s2_size;
    if (size_creation < n)
        size_creation = n;
    s1_c = my_strncpy(s1, size_creation);
    s2_c = my_strncpy(s2, size_creation);
    for (int i = 0; i < n; i++) {
        if (my_comp_char(s1_c[i], s2_c[i]) != 0) {
            cmp = my_comp_char(s1_c[i], s2_c[i]);
            i = size_creation;
        }
    }
    free(s1_c);
    free(s2_c);
    return cmp;
}
