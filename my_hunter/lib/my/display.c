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

int display_sprite(menu_t *menu, window_t *w1)
{
    int i = 0;

    sfRenderWindow_drawSprite(w1->window, menu->sp[i].oiseau, NULL);
    return 0;
}
