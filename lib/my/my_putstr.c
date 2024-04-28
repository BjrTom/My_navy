/*
** EPITECH PROJECT, 2023
** putstr
** File description:
** display str
*/

#include <unistd.h>
#include <stdarg.h>

void my_putstr(char const *str)
{
    int c = 0;

    while (str[c] != '\0') {
        write(1, &str[c], 1);
        c++;
    }
}
