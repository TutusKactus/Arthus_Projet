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

node_t *sorting_id(node_t *head, node_t *tail)
{
    if (head == NULL)
        return tail;
    if (tail == NULL)
        return head;
    if (head->id < tail->id) {
        head->next = sorting_id(head->next, tail);
        return head;
    } else {
        tail->next = sorting_id(head, tail->next);
        return tail;
    }
}

node_t *sort_by_id(node_t *head)
{
    node_t *tail;

    if (head == NULL || head->next == NULL)
        return head;
    tail = search_middle(head);
    head = sort_by_id(head);
    tail = sort_by_id(tail);
    return sorting_id(head, tail);
}

node_t *sorting_id_r(node_t *head, node_t *tail)
{
    if (head == NULL)
        return tail;
    if (tail == NULL)
        return head;
    if (head->id > tail->id) {
        head->next = sorting_id_r(head->next, tail);
        return head;
    } else {
        tail->next = sorting_id_r(head, tail->next);
        return tail;
    }
}

node_t *sort_by_id_r(node_t *head)
{
    node_t *tail;

    if (head == NULL || head->next == NULL)
        return head;
    tail = search_middle(head);
    head = sort_by_id_r(head);
    tail = sort_by_id_r(tail);
    return sorting_id_r(head, tail);
}
