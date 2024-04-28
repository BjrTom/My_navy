/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** just cp a str to another
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    int nb = my_strlen(str);
    char *strdu = malloc(sizeof(char) * nb);

    for (int i = 0; i != nb; i++)
        strdu[i] = str[i];
    return strdu;
}
