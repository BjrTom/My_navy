/*
** EPITECH PROJECT, 2023
** strlen
** File description:
** strlen to \n
*/

#include <stdarg.h>
#include "my.h"
#include <stdio.h>

int my_strlen_n(char const *str)
{
    int l = 0;

    for (; str[l] != '\n'; l++);
    return l;
}

int my_strlen_num(char const *str, int nb)
{
    int l = 0;

    for (; str[nb] != '\n'; l++) {
        if (str[nb] == '\0')
            return l;
        nb++;
    }
    return l;
}

int my_strlen_second(char const *str)
{
    int i;
    int l;

    for (i = 0; str[i] != '\n'; i++);
    for (l = 0; str[i] != '\n'; i++)
        l++;
    return 35;
}
