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

int health_bar(menu_t *menu)
{
    menu->sp[1].clock = sfClock_create();
    menu->sp[1].oiseau = sfSprite_create();
    menu->sp[1].oiseau_texture = sfTexture_createFromFile("h_b.png", NULL);
    sfSprite_setTexture(menu->sp[1].oiseau, menu->sp[1].oiseau_texture,
        sfFalse);
    menu->sp[1].rect.left = -204;
    menu->sp[1].rect.top = -204;
    menu->sp[1].rect.width = 612;
    menu->sp[1].rect.height = 408;
    menu->sp[1].scale = (sfVector2f) {0.5, 0.5};
    sfSprite_setScale(menu->sp[1].oiseau, menu->sp[1].scale);
    return 0;
}

int oizo1(menu_t *menu)
{
    int i = 0;

    menu->sp[i].clock = sfClock_create();
    menu->sp[i].oiseau = sfSprite_create();
    menu->sp[i].oiseau_texture = sfTexture_createFromFile("oiso.png", NULL);
    sfSprite_setTexture(menu->sp[i].oiseau, menu->sp[i].oiseau_texture, sfTrue);
    menu->sp[i].rect.left = 0;
    menu->sp[i].rect.top = 0;
    menu->sp[i].rect.width = 110;
    menu->sp[i].rect.height = 110;
    return 0;
}

int setup_sprite(menu_t *menu)
{
    oizo1(menu);
    return 0;
}

int sprite_game(menu_t *menu)
{
    menu->sp = malloc(sizeof(sp_t) * 5);
    setup_sprite(menu);
    health_bar(menu);
    return 0;
}
