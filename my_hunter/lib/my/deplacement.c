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

int sprite_volant(menu_t *menu, int j)
{
    menu->secondes = sfTime_asSeconds(sfClock_getElapsedTime(menu->sp->clock));
    menu->sp[j].move.x += menu->speed * menu->secondes;
    menu->sp[j].move.y = menu->sp[j].pos.y;
    if (menu->secondes > 0.01) {
        set_pos(menu);
        sfClock_restart(menu->sp->clock);
    }
    while (menu->sp->i > 10) {
        if (menu->sp[j].rect.left == 220) {
            menu->sp[j].rect.left = 0;
            menu->sp->i = 0;
        } else {
            menu->sp[j].rect.left += 110;
            menu->sp->i = 0;    
        }
    }
    sfSprite_setTextureRect(menu->sp[j].oiseau, menu->sp[j].rect);
    menu->sp->i++;
    return 0;
}

int deplacement(menu_t *menu)
{
    int i = 0;

    sprite_volant(menu, i);
    menu->sp[i].hitbox_sprite = (sfFloatRect) {menu->sp[i].move.x,
        menu->sp[i].pos.y, 110, 110};
    return 0;
}
