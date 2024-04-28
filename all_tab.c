/*
** EPITECH PROJECT, 2024
** All_code [WSL: Ubuntu]
** File description:
** all_tab
*/

#include "my.h"

char *interpret(char *flux)
{
    char *base = {"12345678ABCDEFGH"};
    char *log = malloc(sizeof(char) * 3);
    int tab[4] = { 8, 4, 2, 1 };
    int f = 0;

    for (int i = 0; i != 4; i++) {
        if (flux[i] == '1')
            f += tab[i];
    }
    log[0] = base[f];
    f = 0;
    for (int i = 4; i != 8; i++) {
        if (flux[i] == '1')
            f += tab[i - 4];
    }
    log[1] = base[f];
    log[2] = '\0';
    my_putchar(log[0]);
    my_putchar(log[1]);
    return log;
}

void send_input(values *v)
{
    send(v->input, v);
    my_putstr("\nresult: ");
    my_putchar(v->input[0]);
    my_putchar(v->input[1]);
    my_putstr(":");
}

int temporary(char str, char base, int a, int temp)
{
    if (str == base)
        return a;
    return temp;
}

void send(char *str, values *v)
{
    char *base = {"12345678ABCDEFGH"};
    char val1[] = "0000";
    char val2[] = "0000";
    int temp = 0;

    for (int i = 0; i != 2; i++) {
        for (int a = 0; a != 16; a++) {
            temp = temporary(str[i], base[a], a, temp);
        }
        if (i == 0)
            trs_binaire(val1, temp);
        else
            trs_binaire(val2, temp);
    }
    send_bis(val1, v);
    send_bis(val2, v);
}

void send_bis(char *val, values *v)
{
    for (int i = 0; i != 4; i++) {
        usleep(150);
        if (val[i] == '0')
            kill(v->pid, SIGUSR1);
        else
            kill(v->pid, SIGUSR2);
    }
}
