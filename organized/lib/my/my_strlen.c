/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/
#include "unistd.h"
#include "../../include/my.h"

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}
