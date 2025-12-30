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
#include "include/shell.h"

int print_del(node_t *current)
{
    my_putstr(current->type);
    my_putchar(' ');
    my_putstr("n°");
    my_put_nbr(current->id);
    my_putstr(" - ");
    my_putchar('"');
    my_putstr(current->name);
    my_putchar('"');
    my_putstr(" deleted.\n");
    return 0;
}

int existing_node(list_t *list, char **args, int i)
{
    int number = 0;
    node_t *current = list->head;

    if (current == NULL) {
        return 84;
    }
    number = my_atoi(args[i]);
    while (current != NULL) {
        if (number == current->id)
            return 0;
        current = current->next;
    }
    return 84;
}

int head_or_not(node_t *current, int number, node_t *temp, list_t *list)
{
    if (temp == NULL)
        list->head = current->next;
    else
        temp->next = current->next;
    free(current);
    return 0;
}

int delete_node(list_t *list, int number)
{
    node_t *current = list->head;
    node_t *temp = NULL;

    while (current != NULL) {
        if (current->id == number) {
            print_del(current);
            head_or_not(current, number, temp, list);
            break;
        }
        temp = current;
        current = current->next;
    }
    return 0;
}

int del(void *data, char **args)
{
    list_t *list = (list_t *)data;
    int number = 0;

    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (existing_node(list, args, i) == 84)
            return 84;
        number = my_atoi(args[i]);
        if (number > list->id - 1) {
            write(2, "ERROR WHILE USING DEL\n", 23);
            return 84;
        }
        delete_node(list, number);
    }
    return 0;
}
