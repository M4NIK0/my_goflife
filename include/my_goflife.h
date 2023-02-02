/*
** EPITECH PROJECT, 2023
** my_goflife
** File description:
** the game of life with ncurses
*/

#ifndef G_LIFE_H_
    #define G_LIFE_H_

    #include "libmy.h"

    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>

    typedef struct st_flag {
        char flag;
        char *file;
    } flag;

    #include "my_goflife_h/debug.h" // Debug (Useless in final version)

    #include "my_goflife_h/help.h"
    #include "my_goflife_h/flag_gest.h"

#endif /* !G_LIFE_H_ */
