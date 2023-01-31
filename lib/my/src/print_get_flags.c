/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing function to get flags as they are
*/

#include "include/my_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char *);
int print_id_conversion(char);
int print_id_chars(char);
int print_id_len_modif(char *, int *);
int my_getnbr(char const *);

void get_conversion(int *cursor, struct flags *flags, char *format, va_list *ap)
{
    int cursor_bckp = *cursor;
    int id;
    id = print_id_conversion(format[*cursor]);
    if (id == -1) {
        return;
    } else {
        flags->conversion = id;
        *cursor = *cursor + 1;
    }
    *cursor = cursor_bckp;
}

void get_precision(int *cursor, struct flags *flags, char *format, va_list *ap)
{
    int val = -1;
    if (format[*cursor] == '.') {
        val = 0;
        *cursor = *cursor + 1;
        if (format[*cursor] >= '0' && format[*cursor] <= '9') {
            val = my_getnbr(&format[*cursor]);
        }
    }
    flags->precision = val;
    while (format[*cursor] <= '9' && format[*cursor] >= '0')
        *cursor = *cursor + 1;
}

void get_len_modif(int *cursor, struct flags *flags, char *format, va_list *ap)
{
    int cursor_bckp = *cursor;
    int id;

    while (*cursor != my_strlen(format)) {
        id = print_id_len_modif(format, cursor);
        if (id == -1) {
            return;
        } else {
            flags->len_modif[id] = 1;
            *cursor = *cursor + 1;
        }
    }
    *cursor = cursor_bckp;
}

void get_width(int *cursor, struct flags *flags, char *format, va_list *ap)
{
    int wid = -1;
    if (format[*cursor] >= '0' && format[*cursor] <= '9')
        wid = my_getnbr(&format[*cursor]);
    else
        return;
    flags->width = wid;
    while (format[*cursor] >= '0' && format[*cursor] <= '9')
        *cursor = *cursor + 1;
}

void get_chars(int *cursor, struct flags *flags, char *format, va_list *ap)
{
    int cursor_bckp = *cursor;
    int id;

    while (*cursor != my_strlen(format)) {
        id = print_id_chars(format[*cursor]);
        if (id == -1) {
            return;
        } else {
            flags->chars[id] = 1;
            *cursor = *cursor + 1;
        }
    }
    *cursor = cursor_bckp;
}
