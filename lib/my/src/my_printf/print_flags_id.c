/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** functions returning id of characters
*/

int my_strlen(char const *);
int my_strncmp(char *, char *, int);

int print_id_conversion(char a)
{
    char *flags = "%diouxXeEfFgGaAcsSbnp";
    int lenflags = my_strlen(flags);
    int i;
    for (i = 0; i < lenflags && flags[i] != a; i++)
        if (i == lenflags - 1)
            return (-1);
    return i;
}

int print_id_chars(char a)
{
    char *flags = "-+#0, (";
    int lenflags = my_strlen(flags);
    int i;
    for (i = 0; i < lenflags && flags[i] != a; i++)
        if (i == lenflags - 1)
            return (-1);
    return i;
}

int print_id_len_modif(char *str, int *i)
{
    char *flags = "ltzjLh";
    char *flags_m[2] = {"ll", "hh"};
    int lenflags = my_strlen(flags);
    int found = -1;
    for (int j = 0; j < lenflags; j++) {
        if (str[*i] == flags[j]) {
            found = j;
        }
    }
    for (int j = 0; j < 2; j++) {
        if (my_strncmp(&str[*i], flags_m[j], 2) == 0) {
            *i = *i + 1;
            return (lenflags + j);
        }
    }
    return found;
}
