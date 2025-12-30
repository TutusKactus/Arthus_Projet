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

node_t *sorting_name(node_t *head, node_t *tail)
{
    int comp = 0;

    if (head == NULL)
        return tail;
    if (tail == NULL)
        return head;
    comp = ascii_comp(head->name, tail->name);
    if (comp == 1) {
        head->next = sorting_name(head->next, tail);
        return head;
    } else {
        tail->next = sorting_name(head, tail->next);
        return tail;
    }
}

node_t *sort_by_name(node_t *head)
{
    node_t *tail;

    if (head == NULL || head->next == NULL)
        return head;
    tail = search_middle(head);
    head = sort_by_name(head);
    tail = sort_by_name(tail);
    return sorting_name(head, tail);
}

node_t *sorting_name_r(node_t *head, node_t *tail)
{
    int comp = 0;

    if (head == NULL)
        return tail;
    if (tail == NULL)
        return head;
    comp = ascii_comp(head->name, tail->name);
    if (comp == 0) {
        head->next = sorting_name_r(head->next, tail);
        return head;
    } else {
        tail->next = sorting_name_r(head, tail->next);
        return tail;
    }
}

node_t *sort_by_name_r(node_t *head)
{
    node_t *tail;

    if (head == NULL || head->next == NULL)
        return head;
    tail = search_middle(head);
    head = sort_by_name_r(head);
    tail = sort_by_name_r(tail);
    return sorting_name_r(head, tail);
}
