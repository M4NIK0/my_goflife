/*
** EPITECH PROJECT, 2023
** my game of life
** File description:
** main
*/

#include "../include/my_goflife.h"

int verif_args(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return 84;
    return 0;
}

int main(int ac, char **av, char **env)
{
    int verified = verif_args(ac, av, env);
    if (verified == 1)
        return 0;
    if (verified == 84)
        return 84;
    return 0;
}
