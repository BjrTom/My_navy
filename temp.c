/*
** EPITECH PROJECT, 2024
** All_code [WSL: Ubuntu]
** File description:
** temp
*/

#include "my.h"

int place_boat(int **boat, values *v)
{
    for (int i = 0; i != 4; i++){
        if (boat[i][1] == boat[i][3])
            vertical(v, boat, i);
        if (boat[i][2] == boat[i][4])
            horizontal(v, boat, i);
    }
    if (v->error == 84)
        return 84;
}

int sub_check(int *boat)
{
    for (int i = 0; i != 5; i++)
        if (boat[i] < 0)
            return 84;
    if (boat[1] != boat[3] && boat[2] != boat[4])
        return 84;
}

void in_game(values *v)
{
    signal(SIGUSR1, sig_one);
    signal(SIGUSR2, sig_two);
    v->victory = 0;
    v->loose = 0;
    if (v->player == 1) {
        if (player_one(v) == 1)
            return;
    } else {
        if (player_two(v) == 1)
            return;
    }
}

void end_program(values *v)
{
    my_putstr("my navy:\n");
    print_tab(v->tab);
    my_putstr("\nenemy navy:\n");
    print_tab(v->tab2);
    if (v->victory == 14) {
        my_putstr("\nI won\n");
        return;
    } else {
        my_putstr("\nEnemy won\n");
        return;
    }
}

int hit_check(char **tab, char *pos)
{
    char str1[] = "12345678";
    char str2[] = "ABCDEFGH";
    int pos_x = 0;
    int pos_y = 0;

    for (int i = 0; i != 8; i++) {
        if (pos[0] == str2[i]) {
            pos_x = i;
        }
        if (pos[1] == str1[i])
            pos_y = i;
    }
    if (tab[pos_y][pos_x] == '.' || tab[pos_y][pos_x] == 'o'){
        tab[pos_y][pos_x] = 'o';
        return 1;
    } else if (tab[pos_y][pos_x] == 'x')
        return 1;
    else
        tab[pos_y][pos_x] = 'x';
    return 0;
}
