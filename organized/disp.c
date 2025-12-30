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

int disp(void *data, char **args)
{
    list_t *list = (list_t *)data;
    node_t *current = list->head;

    if (args[0] != NULL)
        return 84;
    while (current != NULL) {
        my_putstr(current->type);
        my_putstr(" n°");
        my_put_nbr(current->id);
        my_putstr(" - ");
        my_putchar('"');
        my_putstr(current->name);
        my_putchar('"');
        my_putchar('\n');
        current = current->next;
    }
    return 0;
}
