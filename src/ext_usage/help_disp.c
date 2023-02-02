/*
** EPITECH PROJECT, 2023
** My Game of Life
** File description:
** Help src
*/

#include "../../include/my_goflife.h"

void help_display(void)
{
    my_printf("A simple and easy-to-use Game of Life:\n\n");
    my_printf("./my_goflife [-h] [-l] [file] [-r]\n\n");
    my_printf("-h: Show this message\n");
    my_printf("-r: reset to base settings\n");
    my_printf("-l: Directly load a map.\n");
    my_printf("\t> ./my_goflife -l my_map.gol\n\n");
    my_printf("These flags are meant to be used one at a time,\n");
    my_printf("Only the first flag will be used.\n");
}
