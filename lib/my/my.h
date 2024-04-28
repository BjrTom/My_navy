/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** proto case
*/

#ifndef STN
    #define STN

    #include <stdarg.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <ncurses.h>

int my_printf(const char *str, ...);
int c_flag(va_list ap);
int d_flag(va_list ap);
int i_flag(va_list ap);
int s_flag(va_list ap);
int o_flag(va_list ap);
int x_flag(va_list ap);
int x_maj_flag(va_list ap);
int f_flag(va_list ap);
int rounding(float f);
int sci(double f, long int nb_len);
int n_flag(int *p, int counter);
int u_flag(va_list list);
int my_strlen(char const *str);
void my_putchar(char c);
char *my_strcpy_two(char *dest, char const *src, int len, int pos);
char *my_strcpy(char *dest, char const *src);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int nb_len(long int nb);
int my_getnbr(const char *str);
int my_strlen_first(int l, char const *str);
int my_strlen_n(char const *str);
int my_strlen_num(char const *str, int nb);
char *int_to_string(int num, char *str);
char *my_strdup(char *str);
static int(*function[255])(va_list list) = {s_flag, c_flag, d_flag, i_flag,
    o_flag, x_flag, x_maj_flag, f_flag, f_flag, u_flag};

#endif
