/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/

#ifndef MY_H
    #define MY_H

    #include "stdbool.h"

typedef struct stock {
    int n;
    double a;
    double h;
    double sd;
    double sq_somme;
    double quadra;
    double value;
} s_t;

typedef struct pars {
    int i;
    int j;
} pars_t;
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_putstr(char *str);
int my_putchar(char c);

#endif
