/*
** EPITECH PROJECT, 2023
** octal case
** File description:
** octal
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#include "my.h"

int u_flag(va_list ap)
{
    unsigned int nb;
    int U_num = 0;
    unsigned int U_Number[100];
    int i = 1;

    nb = va_arg(ap, unsigned int);
    while (nb != 0) {
        U_Number[i] = nb % 10;
        nb = nb / 10;
        i++;
    }
    for (int j = i - 1; j > 0; j--) {
        U_num = U_num * 10 + U_Number[j];
        my_put_nbr(U_Number[j]);
    }
    return (i - 1);
}
