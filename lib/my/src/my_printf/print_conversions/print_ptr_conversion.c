/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for pointers conversions
*/

#include "../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

int print_ubase(unsigned long long int number, char *base_to);

void print_flag_n(va_list *ap, struct flags *flags, int *counter)
{
    if (flags->len_modif[7] == 1) {
        *(va_arg(*ap, int *)) = *counter;
        return;
    } if (flags->len_modif[5] == 1) {
        *(va_arg(*ap, int *)) = *counter;
        return;
    } if (flags->len_modif[0] == 1) {
        *(va_arg(*ap, long int *)) = *counter;
        return;
    } if (flags->len_modif[6] == 1) {
        *(va_arg(*ap, long long int *)) = *counter;
        return;
    }
}

void print_flag_percent(va_list *ap, struct flags *flags, int *counter)
{
    *counter += write(1, "%", 1);
}

void print_flag_p(va_list *ap, struct flags *flags, int *counter)
{
    unsigned long long int value = (long long int)va_arg(*ap, void *);
    if (value == 0) {
        *counter += write(1, "(nil)", 5);
    } else {
        *counter += write(1, "0x", 2);
        *counter += print_ubase(value, "0123456789abcdef");
    }
}
