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

int display_hb(menu_t *menu, window_t *w1, int *i)
{
    sfIntRect h_b[6] = {
        {28, 44, 172, 152},
        {224, 44, 172, 152},
        {421, 44, 172, 152},
        {28, 214, 172, 152},
        {224, 214, 172, 152},
        {421, 214, 172, 152},
    };

    sfSprite_setTextureRect(menu->sp[1].oiseau, h_b[*i]);
    (*i)++;
    return 0;
}
