/*
** EPITECH PROJECT, 2023
** c case
** File description:
** c
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int c_flag(va_list ap)
{
    char c;

    c = va_arg(ap, int);
    write(1, &c, 1);
    return 1;
}
