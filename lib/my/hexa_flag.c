/*
** EPITECH PROJECT, 2023
** octal case
** File description:
** octal
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int x_flag(va_list ap)
{
    unsigned int nb;
    int Hexa_num = 0;
    unsigned int Hexa_Number[100];
    int i = 1;
    char *Hexa_tab = "0123456789abcdef";

    nb = va_arg(ap, unsigned int);
    while (nb != 0) {
        Hexa_Number[i] = nb % 16;
        nb = nb / 16;
        i++;
    }
    for (int j = i - 1; j > 0; j--) {
        my_putchar(Hexa_tab[Hexa_Number[j]]);
    }
    return (i - 1);
}
