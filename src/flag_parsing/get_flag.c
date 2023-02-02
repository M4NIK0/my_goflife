/*
** EPITECH PROJECT, 2023
** My Game of Life
** File description:
** flag get from arguments
*/

#include "../../include/my_goflife.h"

int test_flag(char *str)
{
    if (str[0] == '-' && str[1] == 'r' && str[2] == '\0')
        return 1;
    if (str[0] == '-' && str[1] == 'l' && str[2] == '\0')
        return 2;
    return 0;
}

int get_flag(int ac, char **av, flag *flag)
{
    flag->flag = test_flag(av[1]);
    if (flag->flag == 2 && ac >= 3)
        flag->file = av[2];
    return 0;
}
