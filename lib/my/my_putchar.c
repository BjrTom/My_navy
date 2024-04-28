/*
** EPITECH PROJECT, 2023
** putchar
** File description:
** aa
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
