/*
** EPITECH PROJECT, 2024
** All_code [WSL: Ubuntu]
** File description:
** main
*/

#include "my.h"

int gvalue;

static void handler(int signo, siginfo_t *info, void *context)
{
    gvalue = info->si_pid;
}

void sig_one(int signum)
{
    gvalue = 0;
}

void sig_two(int signum)
{
    gvalue = 1;
}

static int startup(char **argv, values *v)
{
    struct sigaction act = {0};

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler;
    sigaction(SIGUSR1, &act, NULL);
    my_printf("my_pid: %d\n\n", getpid());
    if (v->player == 1) {
        my_putstr("waiting for enemy...");
        pause();
        v->pid = gvalue;
        kill(v->pid, SIGUSR1);
        my_printf("\n\nenemy connected\n\n");
    } else {
        kill(my_getnbr(argv[1]), SIGUSR1);
        usleep(500);
        if (gvalue != v->pid)
            return 84;
        my_putstr("successfully connected to enemy\n\n");
    }
}

static void is_touch(int nb, values *v)
{
    if (gvalue == 1)
        my_putstr("missed\n\n");
    if (gvalue == 0) {
        my_putstr("hit\n\n");
    }
    if (nb == 1) {
        if (gvalue == 0)
            v->victory++;
    }
}

static int in_tab(char **tab, char *pos)
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
    if (tab[pos_y][pos_x] == '.'){
        if (gvalue == 0)
            tab[pos_y][pos_x] = 'x';
        else
            tab[pos_y][pos_x] = 'o';
    }
}

static void receive_value(values *v)
{
    char *log;

    for (int i = 0; i != 8; i++) {
        v->binaire[i] = gvalue + 48;
        if (i < 7)
            pause();
    }
    my_putstr("result: ");
    log = interpret(v->binaire);
    my_putstr(":");
    gvalue = hit_check(v->tab, log);
    free(log);
    if (gvalue == 0){
        kill(v->pid, SIGUSR1);
        v->loose += 1;
    } else
        kill(v->pid, SIGUSR2);
}

int player_one(values *v)
{
    while (1) {
        all_print(v);
        v->input = fonction_read();
        send_input(v);
        pause();
        is_touch(1, v);
        in_tab(v->tab2, v->input);
        if (v->victory == 14 || v->loose == 14) {
            end_program(v);
            return 1;
        }
        my_putstr("waiting for enemy's attack...");
        pause();
        my_putstr("\n\n");
        receive_value(v);
        is_touch(0, v);
    }
}

int player_two(values *v)
{
    while (1) {
        all_print(v);
        pause();
        my_putstr("\n\n");
        receive_value(v);
        is_touch(0, v);
        if (v->victory == 14 || v->loose == 14) {
            end_program(v);
            return 1;
        }
        my_putstr("attack: ");
        v->input = fonction_read();
        send_input(v);
        pause();
        is_touch(1, v);
        in_tab(v->tab2, v->input);
    }
}

int launch(int argc, char **argv, values *v)
{
    v->tab = create_tab();
    v->tab2 = create_tab();
    v->binaire = malloc(sizeof(char) * 9);
    for (int n = 0; n != 8; n++)
        v->binaire[n] = '0';
    v->binaire[8] = '\0';
    if (argc == 3) {
        if (create_boat(argv[2], v) == 84)
            return 84;
        v->player = 2;
    } else {
        if (create_boat(argv[1], v) == 84)
            return 84;
        v->player = 1;
    }
    if (startup(argv, v) == 84)
        return 84;
    in_game(v);
}
