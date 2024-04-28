/*
** EPITECH PROJECT, 2024
** All_code
** File description:
** other
*/

#include "my.h"

void free_tab_int(int nb, int **tab)
{
    for (int i = 0; i < nb; i++) {
        free(tab[i]);
    }
    free(tab);
}

void free_tab(int nb, char **tab)
{
    for (int i = 0; i < nb; i++) {
        free(tab[i]);
    }
    free(tab);
}

static int horizon_1(int **boat, values *v, int i)
{
    for (int nb = boat[i][1]; nb <= (boat[i][3]); nb++) {
        if (v->tab[boat[i][2]][nb] != '.')
            return 84;
        v->tab[boat[i][2]][nb] = (boat[i][0] + 48);
    }
}

static int horizon_2(int **boat, values *v, int i)
{
    for (int nb = boat[i][1]; nb >= (boat[i][3]); nb--) {
        if (v->tab[boat[i][2]][nb] != '.')
            return 84;
        v->tab[boat[i][2]][nb] = (boat[i][0] + 48);
    }
}

void horizontal(values *v, int **boat, int i)
{
    if (boat[i][1] < boat[i][3]) {
        if ((boat[i][3] - boat[i][1]) != boat[i][0] - 1)
            v->error = 84;
        if (horizon_1(boat, v, i) == 84)
            v->error = 84;
    }
    if (boat[i][1] > boat[i][3]) {
        if (horizon_2(boat, v, i) == 84)
            v->error = 84;
        if ((boat[i][1] - boat[i][3]) != boat[i][0] - 1)
            v->error = 84;
    }
}

static int verti_1(int **boat, values *v, int i)
{
    for (int nb = boat[i][2]; nb != (boat[i][4] + 1); nb++) {
        if (v->tab[nb][boat[i][1]] != '.')
            return 84;
        v->tab[nb][boat[i][1]] = (boat[i][0] + 48);
    }
}

static int verti_2(int **boat, values *v, int i)
{
    for (int nb = boat[i][2]; nb != (boat[i][4] + 1); nb--) {
        if (v->tab[nb][boat[i][1]] != '.')
            return 84;
        v->tab[nb][boat[i][1]] = (boat[i][0] + 48);
    }
}

void vertical(values *v, int **boat, int i)
{
    if (boat[i][2] < boat[i][4]) {
        if (verti_1(boat, v, i) == 84)
            v->error = 84;
        if ((boat[i][4] - boat[i][2]) != boat[i][0] - 1)
            v->error = 84;
    }
    if (boat[i][2] > boat[i][4]) {
        if (verti_2(boat, v, i) == 84)
            v->error = 84;
        if ((boat[i][2] - boat[i][4]) != boat[i][0] - 1)
            v->error = 84;
    }
}

void print_tab(char **tab)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i != 8; i++){
        my_putchar(49 + i);
        my_putchar('|');
        for (int n = 0; n != 7; n++) {
            my_putchar(tab[i][n]);
            my_putchar(' ');
        }
        my_putchar(tab[i][7]);
        my_putchar('\n');
    }
}
