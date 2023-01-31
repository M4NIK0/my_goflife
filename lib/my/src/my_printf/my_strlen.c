/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** function counting the numbers of chars in a string
*/

int my_strlen(char const *str)
{
    int i;
    i = 0;
    if (str == 0)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
