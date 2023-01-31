/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for %g
*/

#include "../include/my_printf.h"
#include <unistd.h>
int print_e_pow(int, struct flags *, char *);
int print_base_double(long double, int, char *, struct flags *);

void print_g_f(long double value, struct flags *flags, int *counter)
{
    int precision = 0;
    if (flags->precision == -1)
        precision = 6;
    else
        precision = flags->precision;
    if (value < 0) {
        value = (-value);
        *counter += write(1, "-", 1);
    }
    *counter += print_base_double(value, precision, "0123456789", flags);
}

void print_g_e(long double value, struct flags *flags, int *counter)
{
    int precision = 0, power = 0;
    if (flags->precision == -1)
        precision = 6;
    else
        precision = flags->precision;
    if (value < 0) {
        value = (-value);
        *counter += write(1, "-", 1);
    } while (value >= 10) {
        power++;
        value /= 10;
    } while (value < 1) {
        power--;
        value *= 10;
    }
    *counter += print_base_double(value, precision, "0123456789", flags);
    *counter += print_e_pow(power, flags, "0123456789");
}

int power_g_verif(long double value)
{
    int power = 0;
    if (value < 0) {
        value = (-value);
    }
    while (value >= 10) {
        power++;
        value /= 10;
    } while (value < 1) {
        power--;
        value *= 10;
    }
    return power;
}
