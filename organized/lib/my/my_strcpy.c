/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/
#include "unistd.h"
#include "../../include/my.h"

char *my_strcpy(char *src, char *dest)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
