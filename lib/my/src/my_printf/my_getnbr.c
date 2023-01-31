/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** function counting - and + returning num
*/

int my_positive_nbr(char const *, int, int);
int my_negative_nbr(char const *, int, int);

int my_sign(char const *str, int sign, int start_index)
{
    for (int i = 0; i < start_index; i++) {
        if (str[i] == '-') {
            sign++;
        }
    }
    if (sign % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

int nbr_absolute(char const *str, int start_index, int end_index, int sign)
{
    int final = 0;
    if (end_index - start_index > 10) {
        return 0;
    }
    if (sign == 0) {
        final = my_negative_nbr(str, start_index, end_index);
    } else {
        final = my_positive_nbr(str, start_index, end_index);
    }
    return final;
}

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 0, start_index = 0, end_index;
    while (str[start_index] > '9' || str[start_index] < '0') {
        if (str[start_index] == '\0') {
            return 0;
        }
        start_index++;
    }
    end_index = start_index;
    while (str[end_index] <= '9' && str[end_index] >= '0') {
        end_index++;
    }
    end_index--;
    sign = my_sign(str, sign, start_index);
    result = nbr_absolute(str, start_index, end_index, sign);
    return result;
}
