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

int parsing(pars_t *pars, char **args)
{
    int i = 0;

    if (args[0] == NULL)
        return 84;
    while (args[i] != NULL) {
        if (my_strcomp(args[i], "NAME") == 0)
            pars->name = true;
        if (my_strcomp(args[i], "TYPE") == 0)
            pars->type = true;
        if (my_strcomp(args[i], "ID") == 0)
            pars->id = true;
        if (my_strcomp(args[i], "-r") == 0)
            pars->reverse = true;
        i++;
    }
    return 0;
}

struct node *search_middle(node_t *head)
{
    node_t *end = head;
    node_t *middle = head;
    node_t *temp;

    while (end != NULL && end->next != NULL) {
        end = end->next->next;
        if (end != NULL) {
            middle = middle->next;
        }
    }
    temp = middle->next;
    middle->next = NULL;
    return temp;
}

int setup(pars_t *pars)
{
    pars->id = false;
    pars->name = false;
    pars->type = false;
    pars->reverse = false;
    return 0;
}

node_t *which_sort(node_t *head, pars_t *pars)
{
    if (pars->id == true && pars->reverse == false)
        head = sort_by_id(head);
    if (pars->id == true && pars->reverse == true)
        head = sort_by_id_r(head);
    if (pars->name == true && pars->reverse == false)
        head = sort_by_name(head);
    if (pars->name == true && pars->reverse == true)
        head = sort_by_name_r(head);
    if (pars->type == true && pars->reverse == false)
        head = sort_by_type(head);
    if (pars->type == true && pars->reverse == true)
        head = sort_by_type_r(head);
    return head;
}

static int handling_args(pars_t *pars)
{
    if (pars->id == false && pars->name == false && pars->type == false)
        return 84;
    else
        return 0;
}

int sort(void *data, char **args)
{
    list_t *list = (list_t *)data;
    pars_t *pars = malloc(sizeof(pars_t));
    node_t *head = list->head;

    setup(pars);
    if (parsing(pars, args) == 84)
        return 84;
    if (args[1] && my_strcomp(args[1], "-r") != 0)
        return 84;
    if (handling_args(pars) == 84)
        return 84;
    list->head = which_sort(head, pars);
    free(pars);
    return 0;
}
