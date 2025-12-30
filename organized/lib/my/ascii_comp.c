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

int ascii_comp(char *str, char *str1)
{
    int i = 0;
    int len = my_strlen(str);
    int len1 = my_strlen(str1);

    while (str[i] != '\0' && str1[i] != '\0') {
        if (str[i] > str1[i])
            return 0;
        if (str[i] < str1[i])
            return 1;
        i++;
    }
    if (len > len1)
        return 0;
    if (len1 > len)
        return 1;
    return 84;
}
