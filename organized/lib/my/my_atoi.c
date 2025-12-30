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

int str_to_int(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int my_atoi(char *args)
{
    int i = 0;

    if (args[i] >= '0' && args[i] <= '9')
        return str_to_int(args);
    return 84;
}
