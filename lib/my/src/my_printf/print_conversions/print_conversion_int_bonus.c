/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing bonus flags
*/

#include <stdarg.h>
#include <unistd.h>
#include "../include/my_printf.h"

long long int my_get_type_uint(va_list *ap, struct flags *flags);
int print_ubase(unsigned long long int, char *);

void print_flag_b(va_list *ap, struct flags *flags, int *counter)
{
    unsigned long long int value = my_get_type_uint(ap, flags);
    *counter += print_ubase(value, "01");
}
