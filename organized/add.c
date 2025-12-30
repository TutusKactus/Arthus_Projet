/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/

#include "stdio.h"
#include "sys/stat.h"
#include "unistd.h"
#include "sys/types.h"
#include "dirent.h"
#include "include/my.h"
#include "stdbool.h"
#include "fcntl.h"
#include "stdlib.h"

int display_added(node_t *new)
{
    my_putstr(new->type);
    my_putchar(' ');
    my_putstr("n°");
    my_put_nbr(new->id);
    my_putstr(" - ");
    my_putchar('"');
    my_putstr(new->name);
    my_putchar('"');
    my_putstr(" added.\n");
    return 0;
}

int set_new_node(list_t *list, char **args, int i)
{
    node_t *new = malloc(sizeof(node_t));

    new->id = list->id;
    new->name = malloc(sizeof(char) * my_strlen(args[i + 1]) + 1);
    new->type = malloc(sizeof(char) * my_strlen(args[i]) + 1);
    new->name = my_strcpy(args[i + 1], new->name);
    new->type = my_strcpy(args[i], new->type);
    new->name[my_strlen(args[i + 1])] = '\0';
    new->type[my_strlen(args[i])] = '\0';
    new->next = list->head;
    list->head = new;
    display_added(new);
    return 0;
}

int add(void *data, char **args)
{
    list_t *list = (list_t *)data;
    int i = 0;

    if (error_handling_args(args) == 84) {
        write(2, "ERROR WHILE USING ADD\n", 23);
        return 84;
    }
    while (args[i] != NULL && args[i + 1] != NULL) {
        set_new_node(list, args, i);
        i = i + 2;
        list->id++;
    }
    return 0;
}
