/*
** EPITECH PROJECT, 2023
** revstr
** File description:
** reverse str
*/

#include <stdarg.h>
#include "my.h"

char *my_revstr(char *str)
{
    int counter = 0;
    int start;
    int end;
    char rstr[counter];

    while (str[counter] != '\0') {
        counter++;
        end = counter;
    }
    for (start = 0; start <= counter; start++) {
        rstr[start] = str[end];
        end--;
    }
    (rstr[start] = '\0');
    return str;
}
