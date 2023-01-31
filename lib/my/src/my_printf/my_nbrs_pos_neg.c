/*
** EPITECH PROJECT, 2022
** zemmour
** File description:
** macronie
*/

int my_pow(int x, int p)
{
    int y = 1;
    for (int i = 0; i < p; i++) {
        y *= x;
    }
    return y;
}

int my_negative_nbr(char const *str, int start_index, int end_index)
{
    int final = 0;
    for (int i = 0; i <= end_index - start_index; i++) {
        final += (str[end_index - i] - 48) * my_pow(10, i);
        if (final < 0) {
            return 0;
        }
    }
    return final;
}

int my_positive_nbr(char const *str, int start_index, int end_index)
{
    int final = 0;
    for (int i = 0; i <= end_index - start_index; i++) {
        final -= (str[end_index - i] - 48) * my_pow(10, i);
        if (final > 0) {
            return 0;
        }
    }
    return final;
}
