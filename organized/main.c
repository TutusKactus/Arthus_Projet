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

int free_function(list_t *list)
{
    node_t *current = list->head;
    node_t *temp;

    while (current != NULL) {
        temp = current->next;
        free(current);
        current = current->next;
    }
    return 0;
}

int main(int argc, char **argv)
{
    list_t list;
    int z = 0;

    list.head = NULL;
    list.id = 0;
    z = workshop_shell(&list);
    free_function(&list);
    return z;
}
