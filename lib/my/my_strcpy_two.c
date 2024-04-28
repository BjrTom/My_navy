/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** char *
*/

#include <stdio.h>

char *my_strcpy_two(char *dest, char const *src, int len, int pos)
{
    int i = 0;

    for (; i != len; i++) {
        dest[i] = src[pos];
    pos++;
    }
    dest[i] = '\0';
    return dest;
}
