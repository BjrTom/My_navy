/*
** EPITECH PROJECT, 2024
** All_code
** File description:
** *
*/

#include "my.h"

int **set_up(int **boat, char *file_name)
{
    int nb = 0;
    char buffer[32];
    int file = open(file_name, O_RDONLY);

    read(file, buffer, 32);
    close(file);
    for (int i = 0; i != 4; i++){
        boat[i][0] = (buffer[nb] - 48);
        nb += 2;
        boat[i][1] = (buffer[nb] - 65);
        nb += 1;
        boat[i][2] = (buffer[nb] - 49);
        nb += 2;
        boat[i][3] = (buffer[nb] - 65);
        nb++;
        boat[i][4] = (buffer[nb] - 49);
        nb += 2;
    }
    return boat;
}

char **create_tab(void)
{
    char **tab = malloc(sizeof(char *) * 8);

    for (int i = 0; i != 8; i++){
        tab[i] = malloc(sizeof(char) * 9);
        for (int n = 0; n != 8; n++)
            tab[i][n] = '.';
        tab[i][8] = '\0';
    }
    return tab;
}

static int check_file(char *file_name)
{
    char buffer[32];
    int file = open(file_name, O_RDONLY);

    read(file, buffer, 32);
    close(file);
    if (buffer[1] != ':' || buffer[4] != ':')
        return 84;
    if (buffer[9] != ':' || buffer[12] != ':')
        return 84;
    if (buffer[17] != ':' || buffer[20] != ':')
        return 84;
    if (buffer[25] != ':' || buffer[28] != ':')
        return 84;
    return 0;
}

int create_boat(char *file_name, values *v)
{
    int **boat = malloc(sizeof(int *) * 4);

    if (check_file(file_name) == 84)
        return 84;
    for (int i = 0; i != 4; i++)
        boat[i] = malloc(sizeof(int) * 5);
    boat = set_up(boat, file_name);
    if (check_values(boat) == 84)
        return 84;
    if (place_boat(boat, v) == 84)
        return 84;
    free_tab_int(4, boat);
}

void free_all(values *v)
{
    for (int i = 0; i < 8; i++) {
        free(v->tab[i]);
    }
    free(v->tab);
    free(v->input);
    free(v->binaire);
}
