/*
** EPITECH PROJECT, 2023
** i case
** File description:
** i
*/

#include <stdarg.h>
#include "my.h"

int i_flag(va_list ap)
{
    int d;

    d = va_arg(ap, int);
    my_put_nbr(d);
    return nb_len(d);
}
