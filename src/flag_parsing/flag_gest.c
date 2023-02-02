/*
** EPITECH PROJECT, 2023
** My Game of Life
** File description:
** flag struct generation
*/

#include "../../include/my_goflife.h"

void print_prog_flag(flag *to_print)
{
    char *flags[3] = {"None", "-r", "-l"};
    my_printf("Flag found: %s\n", flags[to_print->flag]);
    my_printf("File ptr: %p", to_print->file);
    if (to_print->file != NULL)
        my_printf("File name: %s", to_print->file);
}

flag *gen_flag(void)
{
    flag *to_return = malloc(sizeof(flag));
    to_return->flag = 0;
    to_return->file = NULL;
    return to_return;
}

void kill_flag(flag *to_kill)
{
    free(to_kill);
    my_printf("Successfuly freed flag struct. at %p\n", to_kill);
}
