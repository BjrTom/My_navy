/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** does part of printf function
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int mini_buff(va_list list, char type, int tempcounter)
{
    int counter = 0;
    int i = 0;
    char string[] = "scdioxXfFu";

    if (type == '%') {
        my_putchar('%');
        counter ++;
    }
    while (string[i] != type) {
        i += 1;
    }
    counter = function[i](list);
    return counter;
}

int increment(int count, char c)
{
    count += 1;
    my_putchar(c);
    return count;
}

int my_printf(const char *str, ...)
{
    va_list list;
    int big_counter = 0;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            big_counter += mini_buff(list, str[i + 1], big_counter);
            i += 2;
        }
        if (str[i] == '\n' && str[i + 1] != '\0') {
            big_counter += increment(big_counter, str[i]);
            i ++;
        }
        if (i <= (my_strlen(str) - 1)) {
            my_putchar(str[i]);
            big_counter += 1;
        }
    }
    va_end(list);
    return big_counter;
}
