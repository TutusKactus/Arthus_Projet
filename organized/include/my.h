/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/

#ifndef MY_H
    #define MY_H

    #include "stdbool.h"

typedef struct node {
    char *name;
    char *type;
    int id;
    struct node *next;
} node_t;

typedef struct list {
    struct node *head;
    int id;
} list_t;

typedef struct pars {
    bool name;
    bool type;
    bool id;
    bool reverse;
    int how_much;
} pars_t;

int my_atoi(char *args);
int ascii_comp(char *str, char *str1);
node_t *sorting_type(node_t *head, node_t *tail);
node_t *sorting_type_r(node_t *head, node_t *tail);
node_t *sorting_name(node_t *head, node_t *tail);
node_t *sorting_name_r(node_t *head, node_t *tail);
node_t *sorting_id(node_t *head, node_t *tail);
node_t *sorting_id_r(node_t *head, node_t *tail);
node_t *sort_by_id(node_t *head);
node_t *sort_by_id_r(node_t *head);
node_t *sort_by_type(node_t *head);
node_t *sort_by_type_r(node_t *head);
node_t *sort_by_name(node_t *head);
node_t *sort_by_name_r(node_t *head);
struct node *search_middle(node_t *head);
int error_handling_args(char **args);
int my_strcomp(char *str1, char *str2);
int my_put_nbr(int nb);
char *my_strcpy(char *src, char *dest);
int my_strlen(char *str);
int my_putstr(char *str);
int my_putchar(char c);

#endif
