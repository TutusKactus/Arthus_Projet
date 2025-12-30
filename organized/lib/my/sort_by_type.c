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
#include "../../include/my.h"
#include "stdbool.h"
#include "fcntl.h"
#include "stdlib.h"

node_t *sorting_type_r(node_t *head, node_t *tail)
{
    int compp = 0;

    if (head == NULL)
        return tail;
    if (tail == NULL)
        return head;
    compp = ascii_comp(head->type, tail->type);
    if (compp == 0) {
        head->next = sorting_type_r(head->next, tail);
        return head;
    } else {
        tail->next = sorting_type_r(head, tail->next);
        return tail;
    }
}

node_t *sort_by_type_r(node_t *head)
{
    node_t *tail;

    if (head == NULL || head->next == NULL)
        return head;
    tail = search_middle(head);
    head = sort_by_type_r(head);
    tail = sort_by_type_r(tail);
    return sorting_type_r(head, tail);
}

node_t *sorting_type(node_t *head, node_t *tail)
{
    int comp = 0;

    if (head == NULL)
        return tail;
    if (tail == NULL)
        return head;
    comp = ascii_comp(head->type, tail->type);
    if (comp == 1) {
        head->next = sorting_type(head->next, tail);
        return head;
    } else {
        tail->next = sorting_type(head, tail->next);
        return tail;
    }
}

node_t *sort_by_type(node_t *head)
{
    node_t *tail;

    if (head == NULL || head->next == NULL)
        return head;
    tail = search_middle(head);
    head = sort_by_type(head);
    tail = sort_by_type(tail);
    return sorting_type(head, tail);
}
