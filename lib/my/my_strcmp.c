/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** int
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int nb = my_strlen(s2);

    while (s1[i] && s1[i] == s2[i]) {
        i++;
    }
    if (i == nb)
        return 0;
    return 1;
}
