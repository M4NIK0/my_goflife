/*
** EPITECH PROJECT, 2022
** convert_base
** File description:
** function converting a base to another
*/

#include <stdlib.h>
int my_powed(int, int);
int my_checkpow(int, int);
int my_checkfac(int, int, int);

int my_putnbr_str_use(char *final_return, int cursor, int isneg)
{
    if (isneg == 1) {
        final_return[cursor] = '-';
        cursor++;
    }
    return cursor;
}

char *my_putnbr_str(int number)
{
    char *final_return, *base_to = "0123456789";
    if (number == 0) {
        final_return = malloc(sizeof(char) * 2);
        final_return[0] = '0';
        final_return[1] = '\0';
        return final_return;
    } int base_t = 10, isneg = 0, cursor = 0, num;
    if (number < 0) {
        isneg++;
        number = -number;
    } int final_power = (my_checkpow(number, base_t));
    final_return = malloc(sizeof(char) * (final_power + 1 + isneg));
    cursor = my_putnbr_str_use(final_return, cursor, isneg);
    for (int i = final_power; i >= 0; i--) {
        num = my_checkfac(number, i, base_t);
        number -= (num * my_powed(base_t, i));
        final_return[cursor] = base_to[num];
        cursor++;
    } final_return[cursor + 1] = '\0';
    return final_return;
}
