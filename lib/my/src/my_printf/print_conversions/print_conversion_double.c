/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for double conversions
*/

#include "../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

int print_base_double(long double, int, char *, struct flags *);
long double my_get_type_double(va_list *ap, struct flags *flags);
int print_e_pow(int, struct flags *, char *);
void print_g_f(long double value, struct flags *flags, int *counter);
void print_g_e(long double value, struct flags *flags, int *counter);
int power_g_verif(long double value);

void print_flag_f(va_list *ap, struct flags *flags, int *counter)
{
    long double value = my_get_type_double(ap, flags);
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

void print_flag_e(va_list *ap, struct flags *flags, int *counter)
{
    long double value = my_get_type_double(ap, flags);
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

void print_flag_a(va_list *ap, struct flags *flags, int *counter)
{
    long double value = my_get_type_double(ap, flags);
    int precision = 0;
    if (flags->precision == -1)
        precision = 6;
    else
        precision = flags->precision;
    if (value < 0) {
        value = (-value);
        *counter += write(1, "-", 1);
    }
    if (flags->conversion == 13)
        *counter += print_base_double(value,
        precision, "0123456789abcdef", flags);
    else
        *counter += print_base_double(value, precision,
        "0123456789ABCDEF", flags);
    return;
}

void print_flag_g(va_list *ap, struct flags *flags, int *counter)
{
    long double value = my_get_type_double(ap, flags);
    int power = 0;
    power = power_g_verif(value);
    if (flags->precision == -1)
        flags->precision = 0;
    if (power < -4 || power >= flags->precision) {
        flags->conversion = flags->conversion - 4;
        flags->precision = 2;
        print_g_e(value, flags, counter);
    } else {
        flags->conversion = flags->conversion - 2;
        flags->precision = 4;
        print_g_f(value, flags, counter);
    }
}
