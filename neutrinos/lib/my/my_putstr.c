/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/

#include "../../include/my.h"
#include "unistd.h"
#include "stdio.h"

int my_putstr(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count += my_putchar(str[i]);
    }
    return count;
}
