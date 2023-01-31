/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** file containing all functions for unsigned int types
*/

#include <unistd.h>

int my_strlen(const char *);

unsigned long long int my_upowed(int n, int p)
{
    unsigned long long powd = 1;
    for (int i = 0; i < p; i++) {
        powd *= n;
    }
    return powd;
}

unsigned long long int my_ucheckfac(long long number, int power, int base)
{
    unsigned long long powed = my_upowed(base, power);
    int num = 0;
    while (num * powed <= number) {
        num++;
    }
    return (num - 1);
}

int my_ucheckpow(unsigned long long number, int base_to)
{
    int power = 0;
    while (my_upowed(base_to, power) <= number) {
        power++;
    }
    return (power - 1);
}

int print_ubase(unsigned long long int number, char *base_to)
{
    if (number == 0)
        return write(1, "0", 1);
    int base_t = my_strlen(base_to);
    int counter = 0, num;
    int final_power = (my_ucheckpow(number, base_t));
    for (int i = final_power; i >= 0; i--) {
        num = my_ucheckfac(number, i, base_t);
        number -= (num * my_upowed(base_t, i));
        counter += write(1, &base_to[num], 1);
    }
    return counter;
}
