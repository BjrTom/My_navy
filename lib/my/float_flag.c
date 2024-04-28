/*
** EPITECH PROJECT, 2023
** float
** File description:
** print float
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#include "my.h"

int rounding(float f)
{
    int nb;
    int test;

    nb = f;
    nb = nb * 10;
    test = f * 10 - nb;
    nb = nb / 10;
    if (test > 4) {
        nb += 1;
    }
    my_put_nbr(nb);
}

int f_flag(va_list list)
{
    float f;
    int nb;
    double i;
    int count = 0;
    int test = 0;

    f = va_arg(list, double);
    nb = f;
    i = f - nb;
    my_put_nbr(nb);
    my_putchar('.');
    while (count != 6) {
        i *= 10;
        nb = i;
        if (nb == 0)
            write(1, "0", 1);
        count++;
    }
    rounding(i);
    return (nb_len(f) + 7);
}
