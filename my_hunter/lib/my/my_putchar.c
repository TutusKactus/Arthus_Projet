/*
** EPITECH PROJECT, 2025
** Project: my_putchar.c libs
** File description:
** Just the 'my_putchar.c' script.
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putchar_error(char c)
{
    write(2, &c, 1);
    return 0;
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}
