/*
** EPITECH PROJECT, 2025
** Project: my_putstr.c libs
** File description:
** Just the 'my_putstr.c' script.
*/

#include "../../include/my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    char output;

    while (*str != '\0') {
        output = *str;
        my_putchar(output);
        str++;
    }
    return 0;
}
