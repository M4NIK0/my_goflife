/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for int types
*/

#include "../include/my_printf.h"
#include <stdarg.h>

long long int my_get_type_int(va_list *ap, struct flags *flags)
{
    if (flags->len_modif[7] == 1)
        return (long long int)va_arg(*ap, int);
    if (flags->len_modif[5] == 1)
        return (long long int)va_arg(*ap, int);
    if (flags->len_modif[0] == 1)
        return (long long int)va_arg(*ap, long int);
    if (flags->len_modif[6] == 1)
        return (long long int)va_arg(*ap, long long int);
    return va_arg(*ap, int);
}

unsigned long long int my_get_type_uint(va_list *ap, struct flags *flags)
{
    if (flags->len_modif[7] == 1)
        return (unsigned long long int)va_arg(*ap, unsigned int);
    if (flags->len_modif[5] == 1)
        return (unsigned long long int)va_arg(*ap, unsigned int);
    if (flags->len_modif[0] == 1)
        return (unsigned long long int)va_arg(*ap, unsigned long int);
    if (flags->len_modif[6] == 1)
        return (unsigned long long int)va_arg(*ap, unsigned long long int);
    return va_arg(*ap, int);
}

long double my_get_type_double(va_list *ap, struct flags *flags)
{
    if (flags->len_modif[4] == 1)
        return va_arg(*ap, long double);
    return (long double)va_arg(*ap, double);
}
/*    if (flags->len_modif[3] == 1)
        return (long long int)va_arg(*ap, int_max_t);
    if (flags->len_modif[2] == 1)
        return (long long int)va_arg(*ap, size_t);
    if (flags->len_modif[1] == 1)
        return (long long int)va_arg(*ap, ptr_diff_t); */
