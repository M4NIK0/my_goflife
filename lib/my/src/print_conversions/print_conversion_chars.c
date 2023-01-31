/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for chars conversions
*/

#include "../include/my_printf.h"
#include <unistd.h>
#include <stdarg.h>

int print_base(long long int number, char *base_to);
int my_strlen(char *);

int print_ascii_non_printable(char a, struct flags *flags)
{
    int counter = 0;
    if (flags->conversion == 17 && (a < 32 || a > 126)) {
        counter += write(1, "/0", 2);
        counter += print_base((long long int)a, "01234567");
    } else {
        counter += write(1, &a, 1);
    }
    return counter;
}

void print_flag_c(va_list *ap, struct flags *flags, int *counter)
{
    char value = va_arg(*ap, int);
    *counter += write(1, &value, 1);
}

void print_flag_s(va_list *ap, struct flags *flags, int *counter)
{
    char *value = va_arg(*ap, char *);
    int precision = flags->precision;
    if (precision == -1)
        precision = my_strlen(value);
    for (int i = 0; i < my_strlen(value) && i < precision; i++)
        *counter += print_ascii_non_printable(value[i], flags);
    return;
}
