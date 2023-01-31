/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all declarations for my_printf
*/

#ifndef CONVERSIONS_H_
    #define CONVERSIONS_H_

void print_flag_c(va_list *ap, struct flags *flags, int *counter);
void print_flag_e(va_list *ap, struct flags *flags, int *counter);
void print_flag_f(va_list *ap, struct flags *flags, int *counter);
void print_flag_b(va_list *ap, struct flags *flags, int *counter);
void print_flag_a(va_list *ap, struct flags *flags, int *counter);
void print_flag_g(va_list *ap, struct flags *flags, int *counter);
void print_flag_hex(va_list *ap, struct flags *flags, int *counter);
void print_flag_int(va_list *ap, struct flags *flags, int *counter);
void print_flag_n(va_list *ap, struct flags *flags, int *counter);
void print_flag_oct(va_list *ap, struct flags *flags, int *counter);
void print_flag_s(va_list *ap, struct flags *flags, int *counter);
void print_flag_unsigned(va_list *ap, struct flags *flags, int *counter);
void print_flag_percent(va_list *ap, struct flags *flags, int *counter);
void print_flag_p(va_list *ap, struct flags *flags, int *counter);

#endif //CONVERSIONS_H_
