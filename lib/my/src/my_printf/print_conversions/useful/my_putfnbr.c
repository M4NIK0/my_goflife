/*
** EPITECH PROJECT, 2022
** my_putfnbr
** File description:
** function returning str from float
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

long long my_powed(int, int);
int my_checkpow(long long, int);
int print_base(long long int, char *);
int my_strlen(char *);

int print_base_double(long double num, int dec, char *base_to,
struct flags *flags)
{
    char *number_int, *number_dec, *final_return, *miss_z;
    int zeros, size = 0;
    size += print_base((long long int)num, base_to);
    num -= (long long int)num;
    if (dec != 0) {
        size += write(1, ".", 1);
        num *= (long double)my_powed(10, dec);
        zeros = dec - my_checkpow((long long int)num, 10);
        for (int i = zeros - 1; i > 0; i--)
            size += write(1, "0", 1);
        if (num - (long long int)num >= 0.5)
            num++;
        size += print_base((long long int)num, base_to);
    }
    return size;
}

int print_e_pow(int value, struct flags *flags, char *base_to)
{
    int counter = 0;
    if (value == 0)
        return 0;
    if (flags->conversion == 7)
        counter += write(1, "e", 1);
    else
        counter += write(1, "E", 1);
    if (value >= 0) {
        counter += write(1, "+", 1);
    } else {
        counter += write(1, "-", 1);
        value = (-value);
    }
    if (value < 10)
        counter += write(1, "0", 1);
    counter += print_base((long long int)value, base_to);
    return counter;
}
