/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** function returning given upcased strs
*/

int my_strlen(char *);

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
