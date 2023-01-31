/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** a mini printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my_printf.h"
#include "include/print_conversions.h"

struct flags *gen_flags(void);
void get_width(int *, struct flags *, const char *, va_list *);
void get_len_modif(int *, struct flags *, const char *, va_list *);
void get_precision(int *, struct flags *, const char *, va_list *);
void get_chars(int *, struct flags *, const char *, va_list *);
void get_conversion(int *, struct flags *, const char *, va_list *);
int my_strlen(const char *);

void print_do_work(va_list *ap, char const *format,
    int *counter, struct flags *flags)
{
    void (*print_conversion[])(va_list *, struct flags *, int *) = {
        &print_flag_percent, &print_flag_int, &print_flag_int, &print_flag_oct,
        &print_flag_unsigned, &print_flag_hex, &print_flag_hex, &print_flag_e,
        &print_flag_e, &print_flag_f, &print_flag_f, &print_flag_g,
        &print_flag_g, &print_flag_a, &print_flag_a, &print_flag_c,
        &print_flag_s, &print_flag_s, &print_flag_b, &print_flag_n,
        &print_flag_p};
    print_conversion[flags->conversion](ap, flags, counter);
}

void print_flag(va_list *ap, int *i, char const *str, int *counter)
{
    int bckp_i = *i;
    *i = *i + 1;
    struct flags *flags = gen_flags();
    get_chars(i, flags, str, ap);
    get_width(i, flags, str, ap);
    get_precision(i, flags, str, ap);
    get_len_modif(i, flags, str, ap);
    get_conversion(i, flags, str, ap);
    if (flags->conversion == -1) {
        *i = bckp_i;
        *counter += write(1, "%", 1);
        return;
    } else {
        print_do_work(ap, str, counter, flags);
        return;
    }
}

int print_loop(va_list *ap, char const *str, int lenp)
{
    int format_len = my_strlen(str);
    for (int i = 0; i < format_len; i++) {
        if (str[i] == '%') {
            print_flag(ap, &i, str, &lenp);
        } else {
            lenp += write(1, &str[i], 1);
        }
    }
    return lenp;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int lenp = 0;
    va_start(ap, format);
    lenp = print_loop(&ap, format, lenp);
    va_end(ap);
    return lenp;
}
