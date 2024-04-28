/*
** EPITECH PROJECT, 2023
** octal case
** File description:
** octal
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int o_flag(va_list ap)
{
    unsigned int nb;
    int octalnum = 0;
    unsigned int octalNumber[100];
    int i = 1;

    nb = va_arg(ap, unsigned int);
    while (nb != 0) {
        octalNumber[i] = nb % 8;
        nb = nb / 8;
        i++;
    }
    for (int j = i - 1; j > 0; j--) {
        octalnum = octalnum * 10 + octalNumber[j];
        my_put_nbr(octalNumber[j]);
    }
    return (i - 1);
}
