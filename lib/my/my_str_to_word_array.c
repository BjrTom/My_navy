/*
** EPITECH PROJECT, 2024
** All_code
** File description:
** my_str_to_word_array
*/

#include "my.h"

int count_word(char *str, int l)
{
    int i = 0;

    for (; str[l] != ' '; l++)
    i++;
    return i;
}

int count_space(char *str)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != '\0')
            count++;
    }
    if (str[0] == ' ')
        count--;
    return count;
}

char **my_str_to_word_array(char *str)
{
    int l = 0;
    int wsize = 0;
    int size = count_space(str);
    char **tab = malloc(sizeof(char *) * size);

    for (int i = 0; i != size; i++) {
        wsize = count_word(str, l);
        tab[i] = malloc(sizeof(char) * 100);
        for (int n = 0; n != wsize; n++) {
            tab[i][n] = str[l];
            l++;
        }
        l++;
    }
    return tab;
}
