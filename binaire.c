/*
** EPITECH PROJECT, 2024
** All_code [WSL: Ubuntu]
** File description:
** binaire
*/

#include "my.h"

void trs_binaire(char *val, int temp)
{
    int d = 0;
    int a = temp;
    int f = 16;

    while (a > 1) {
        f = f / 2;
        if (a >= f) {
            val[d] = '1';
            a -= f;
        } else
            val[d] = '0';
        d += 1;
    }
    if (a == 1)
        val[3] = '1';
}

char *fonction_read(void)
{
    int fd = 0;
    char *b = malloc(sizeof(char) * 100);

    read(fd, b, 100);
    for (int i = 0; b[i] != '\n' && i < 2; i++);
    if (b[2] != '\n' && b[2] != '\0' && (b[2] != '\n' && b[3] != '\0')) {
        my_putstr("\nwrong position\n\nattack: ");
        free(b);
        fonction_read();
    }
    if (b[0] < 65 || b[0] > 72 || b[1] < 49 || b[1] > 56){
        my_putstr("\nwrong position\n\nattack: ");
        free(b);
        fonction_read();
    }
    return b;
}

void all_print(values *v)
{
    my_putstr("my navy:\n");
    print_tab(v->tab);
    my_putstr("\nenemy navy:\n");
    print_tab(v->tab2);
    if (v->player == 1)
        my_putstr("\nattack: ");
    if (v->player == 2)
        my_putstr("\nwaiting for enemy's attack...");
}

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player. ");
    my_putstr("pid of the ships.\n");
    my_putstr("navy_positions : file representing the positions ");
    my_putstr("of the ships.\n");
    return;
}

int check_values(int **boat)
{
    int nb;

    for (int i = 0; i != 4; i++) {
        if (sub_check(boat[i]) == 84)
            return 84;
        nb = boat[i][0];
        if (nb != 2 && nb != 3 && nb != 4 && nb != 5)
            return 84;
        if (boat[i][1] > 7 || boat[i][3] > 7)
            return 84;
        if (boat[i][2] > 7 || boat[i][4] > 7)
            return 84;
    }
}
