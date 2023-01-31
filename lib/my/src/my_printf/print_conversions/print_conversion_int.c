/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for int conversions
*/

#include "../include/my_printf.h"
#include <unistd.h>
#include <stdarg.h>

int print_base(long long int, char *);
int print_ubase(unsigned long long int, char *);
long long int my_get_type_int(va_list *, struct flags *);
unsigned long long int my_get_type_uint(va_list *, struct flags *);

void print_flag_int(va_list *ap, struct flags *flags, int *counter)
{
    long long int value = my_get_type_int(ap, flags);
    *counter += print_base(value, "0123456789");
    return;
}

void print_flag_unsigned(va_list *ap, struct flags *flags, int *counter)
{
    unsigned long long int value = my_get_type_uint(ap, flags);
    *counter += print_ubase(value, "0123456789");
    return;
}

void print_flag_oct(va_list *ap, struct flags *flags, int *counter)
{
    unsigned long long int value = my_get_type_uint(ap, flags);
    if (flags->chars[2] == 1)
        *counter += write(1, "0", 1);
    *counter += print_ubase(value, "01234567");
    return;
}

void print_flag_hex(va_list *ap, struct flags *flags, int *counter)
{
    unsigned long long int value = my_get_type_uint(ap, flags);
    if (flags->conversion == 5) {
        if (flags->chars[2] == 1)
            *counter += write(1, "0x", 2);
        *counter += print_ubase(value, "0123456789abcdef");
    } else {
        if (flags->chars[2] == 1)
            *counter += write(1, "0X", 2);
        *counter += print_ubase(value, "0123456789ABCDEF");
    }
    return;
}
