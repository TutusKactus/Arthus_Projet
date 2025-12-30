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

int my_strcomp(char *str1, char *str2)
{
    int i = 0;

    for (i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return 1;
    }
    return 0;
}
