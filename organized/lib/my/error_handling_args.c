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

int enought_args(char **args)
{
    int i = 0;

    if (args[0] == NULL)
        return 84;
    while (args[i] != NULL) {
        if (args[i + 1] == NULL)
            return 84;
        i += 2;
    }
    return 0;
}

int correct_type(char **args)
{
    int i = 0;
    int result = 0;

    for (i = 0; args[i] != NULL;) {
        result = my_strcomp(args[i], "DEVICE");
        result += my_strcomp(args[i], "SENSOR");
        result += my_strcomp(args[i], "PROCESSOR");
        result += my_strcomp(args[i], "ACTUATOR");
        result += my_strcomp(args[i], "WIRE");
        if (result == 5)
            return 84;
        else {
            result = 0;
            i += 2;
        }
    }
    return 0;
}

int error_handling_args(char **args)
{
    if (enought_args(args) == 84) {
        return 84;
    }
    if (correct_type(args) == 84) {
        return 84;
    }
    return 0;
}
