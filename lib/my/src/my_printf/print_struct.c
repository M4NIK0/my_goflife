/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#include "include/my_printf.h"
#include <stdlib.h>

struct flags *gen_flags(void)
{
    struct flags *to_return = malloc(sizeof(struct flags));
    int *a = malloc(sizeof(int) * 10);
    int *b = malloc(sizeof(int) * 10);
    to_return->chars = a;
    to_return->width = -1;
    to_return->precision = -1;
    to_return->len_modif = b;
    to_return->conversion = -1;
    return to_return;
}
