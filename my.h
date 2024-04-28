/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** proto case
*/

#ifndef STN
    #define STN

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <signal.h>

typedef struct values {
    char **tab;
    char **tab2;
    char *input;
    char *binaire;
    int error;
    int victory;
    int loose;
    int pid;
    int pos;
    int player;
}values;

int my_printf(const char *str, ...);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char my_putchar(char c);
int my_strlen(char *str);
int my_getnbr(const char *str);
void my_putstr(char const *str);
int my_strlen_n(char const *str);
char *my_strdup(char *);
char **my_str_to_word_array(char *str);

int **set_up(int **boat, char *file_name);
int create_boat(char *file_name, values *v);
char **create_tab(void);
void free_tab_int(int nb, int **tab);
void free_tab(int nb, char **tab);
void horizontal(values *v, int **boat, int i);
void vertical(values *v, int **boat, int i);
void print_tab(char **tab);
int check_values(int **boat);
int sub_check(int *boat);
int place_boat(int **boat, values *v);
void usage(void);
void all_print(values *v);
char *fonction_read(void);
void trs_binaire(char *val, int temp);
void send_bis(char *val, values *v);
void send(char *str, values *v);
void send_input(values *v);
char *interpret(char *flux);
int hit_check(char **tab, char *pos);
void free_all(values *v);
void sig_two(int signum);
void sig_one(int signum);
void in_game(values *v);
int player_two(values *v);
int player_one(values *v);
void end_program(values *v);
int launch(int argc, char **argv, values *v);

#endif
