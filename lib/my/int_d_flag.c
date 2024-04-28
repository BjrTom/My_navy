/*
** EPITECH PROJECT, 2023
** d case
** File description:
** d
*/

#include <stdarg.h>
#include "my.h"

int d_flag(va_list ap)
{
    int d;

    d = va_arg(ap, int);
    my_put_nbr(d);
    return nb_len(d);
}
