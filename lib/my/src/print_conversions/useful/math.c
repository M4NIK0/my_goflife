/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for math
*/

#include <unistd.h>

int my_strlen(const char *);

long long my_powed(int n, int p)
{
    long long powd = 1;
    for (int i = 0; i < p; i++) {
        powd *= n;
    }
    return powd;
}

int my_checkpow(long long number, int base_to)
{
    int power = 0;
    while (my_powed(base_to, power) <= number) {
        power++;
    }
    if (power != 0)
        return (power - 1);
    else
        return 0;
}

long long my_checkfac(long long number, int power, int base)
{
    long long powed = my_powed(base, power);
    int num = 0;
    while (num * powed <= number) {
        num++;
    }
    return (num - 1);
}

int print_base(long long int number, char *base_to)
{
    if (number == 0)
        return write(1, "0", 1);
    int base_t = my_strlen(base_to);
    int counter = 0, num;
    if (number < 0) {
        counter += write(1, "-", 1);
        number = (-number);
    }
    int final_power = (my_checkpow(number, base_t));
    for (int i = final_power; i >= 0; i--) {
        num = my_checkfac(number, i, base_t);
        number -= (num * my_powed(base_t, i));
        counter += write(1, &base_to[num], 1);
    }
    return counter;
}
