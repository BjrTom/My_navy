/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** main
*/

#include "my.h"

int main_bis(int argc, char **argv, values *v)
{
    if (argc == 3) {
        v->pid = my_getnbr(argv[1]);
        if (v->pid < 1) {
            write(2, "Error\n", 6);
            return 84;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    values v;
    int temp = 0;

    temp = main_bis(argc, argv, &v);
    if (temp == 84)
        return temp;
    if (argv[1][1] == 'h') {
        usage();
        return 0;
    }
    if (launch(argc, argv, &v) == 84) {
        write(2, "Error\n", 6);
        return 84;
    }
    free_all(&v);
    if (v.victory == 14)
        return 0;
    return 1;
}
