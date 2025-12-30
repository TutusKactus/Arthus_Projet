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

int set_pos_spawn(menu_t *menu)
{
    int i = 0;

    menu->sp[i].pos.x = 0;
    menu->sp[i].pos.y = 700;
    sfSprite_setPosition(menu->sp[i].oiseau, menu->sp[i].pos);
    menu->sp[0].move.x = 0;
    menu->sp[0].move.y = 0;
    return 0;
}

int click_hitbox(menu_t *menu, window_t *w1)
{
    sfVector2i mouse;
    int i = 0;

    mouse = sfMouse_getPositionRenderWindow(w1->window);
    if (sfFloatRect_contains(&menu->sp[i].hitbox_sprite, mouse.x, mouse.y)) {
        menu->sp[i].pos = (sfVector2f) {-100, (rand() % 900 + 1)};
        menu->sp[i].move.x = menu->sp[i].pos.x;
        menu->score++;
        sfSprite_setPosition(menu->sp[i].oiseau, menu->sp[i].pos);
        menu->speed += 50;
    }
    return 0;
}

int game_background(window_t *w1, menu_t *menu, game_t *game)
{
    game->background = sfSprite_create();
    game->background_texture = sfTexture_createFromFile("fond2.jpg", NULL);
    sfSprite_setTexture(game->background, game->background_texture, sfFalse);
    sfRenderWindow_drawSprite(w1->window, game->background, NULL);
    return 0;
}

int setup(menu_t *menu, window_t *w1, game_t *game)
{
    game_background(w1, menu, game);
    sprite_game(menu);
    menu->sp->clock = sfClock_create();
    menu->speed = 500;
    menu->secondes = 0;
    set_pos_spawn(menu);
    return 0;
}

static int suite_game_screen(menu_t *menu, window_t *w1, game_t *game)
{
    close_window(w1);
    sfRenderWindow_clear(w1->window, sfBlack);
    deplacement(menu);
    sfRenderWindow_drawSprite(w1->window, game->background, NULL);
    display_sprite(menu, w1);
    sfRenderWindow_drawSprite(w1->window, menu->sp[1].oiseau, NULL);
    sfRenderWindow_display(w1->window);
    return 0;
}

int game_screen(menu_t *menu, window_t *w1)
{
    game_t game;
    int i = 0;
    int j = 0;

    setup(menu, w1, &game);
    display_hb(menu, w1, &i);
    menu->sp->i = 0;
    while (sfRenderWindow_isOpen(w1->window)) {
        if (w1->event1.type == sfEvtMouseButtonPressed)
            click_hitbox(menu, w1);
        if (menu->sp[j].move.x > 1920) {
            menu->sp[j].move.x = -50;
            menu->sp[j].pos.y = (rand() % 900 + 1);
            display_hb(menu, w1, &i);
        }
        if (i >= 5)
            game_over(menu, w1);
        suite_game_screen(menu, w1, &game);
    }
    return 0;
}
