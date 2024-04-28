/*
** EPITECH PROJECT, 2023
** nb_lenght
** File description:
** the lenght of a number
*/

#include <stdarg.h>
#include "my.h"

int nb_len(long int nb)
{
    int count = 0;

    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return count;
}
