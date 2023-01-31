/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** function that compares string and return which one is "higher"
*/

int my_strlen(char const *str);
char *my_strcpy(char *, char const *);
int my_comp_char(char a, char b);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_size = my_strlen(s1), s2_size = my_strlen(s2);
    int size_creation = 0;
    if (s1_size >= s2_size) {
        size_creation = s1_size;
    } else {
        size_creation = s2_size;
    }
    char s1_c[size_creation], s2_c[size_creation];
    my_strcpy(s1_c, s1);
    my_strcpy(s2_c, s2);
    for (int i = 0; i < n; i++) {
        if (my_comp_char(s1_c[i], s2_c[i]) != 0) {
            return my_comp_char(s1_c[i], s2_c[i]);
        }
    }
    return 0;
}
