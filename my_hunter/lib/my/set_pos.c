/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/

#include "SFML/Graphics.h"
#include "../../include/my.h"
#include "stdlib.h"
#include "stdio.h"

int set_pos(menu_t *menu)
{
    int i = 0;

    sfSprite_setPosition(menu->sp[i].oiseau, menu->sp[i].move);
    return 0;
}
