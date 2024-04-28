/*
** EPITECH PROJECT, 2023
** s case
** File description:
** s
*/

#include <stdarg.h>
#include "my.h"

int s_flag(va_list ap)
{
    int l = 0;
    char *str;

    str = va_arg(ap, char *);
    for (; str[l] != '\0'; l++) {
        my_putchar(str[l]);
    }
    return (l);
}
