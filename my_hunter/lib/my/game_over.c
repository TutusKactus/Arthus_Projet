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

int game_over_sprite(sp_t *sp_go)
{
    sp_go->oiseau = sfSprite_create();
    sp_go->oiseau_texture = sfTexture_createFromFile("game over.png", NULL);
    sfSprite_setTexture(sp_go->oiseau, sp_go->oiseau_texture, sfFalse);
    sp_go->pos.x = 630;
    sp_go->pos.y = -30;
    sfSprite_setPosition(sp_go->oiseau, sp_go->pos);
    sp_go->scale = (sfVector2f) {0.5, 0.35};
    sfSprite_setScale(sp_go->oiseau, sp_go->scale);
    return 0;
}

int restart(window_t *w1, menu_t *menu)
{
    sfSprite_destroy(menu->background);
    sfSprite_destroy(menu->start);
    sfTexture_destroy(menu->background_texture);
    sfTexture_destroy(menu->start_texture);
    menu_game(w1);
    return 0;
}

int restart_button(window_t *w1, menu_t *menu)
{
    menu->sp[4].oiseau = sfSprite_create();
    menu->sp[4].oiseau_texture = sfTexture_createFromFile("menu_button.png",
        NULL);
    sfSprite_setTexture(menu->sp[4].oiseau, menu->sp[4].oiseau_texture,
        sfFalse);
    menu->sp[4].pos.x = 730;
    menu->sp[4].pos.y = 300;
    sfSprite_setPosition(menu->sp[4].oiseau, menu->sp[4].pos);
    menu->sp[4].scale = (sfVector2f) {0.35, 0.35};
    sfSprite_setScale(menu->sp[4].oiseau, menu->sp[4].scale);
    return 0;
}

static int button_pressed(window_t *w1, menu_t *menu)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(w1->window);
    if (mouse.x <= 1101 && mouse.x >= 806 && mouse.y >= 596 && mouse.y <= 709)
        sfRenderWindow_close(w1->window);
    if (mouse.x <= 1119 && mouse.x >= 794 && mouse.y >= 375 && mouse.y <= 523)
        restart(w1, menu);
    return 0;
}

static int exit_button(window_t *w1, menu_t *menu)
{
    menu->sp[3].oiseau = sfSprite_create();
    menu->sp[3].oiseau_texture = sfTexture_createFromFile("exit_button.png",
        NULL);
    sfSprite_setTexture(menu->sp[3].oiseau, menu->sp[3].oiseau_texture,
        sfFalse);
    menu->sp[3].pos.x = 800;
    menu->sp[3].pos.y = 500;
    sfSprite_setPosition(menu->sp[3].oiseau, menu->sp[3].pos);
    menu->sp[3].scale = (sfVector2f) {0.3, 0.3};
    sfSprite_setScale(menu->sp[3].oiseau, menu->sp[3].scale);
    return 0;
}

static int tab(menu_t *menu)
{
    menu->sp[2].oiseau = sfSprite_create();
    menu->sp[2].oiseau_texture = sfTexture_createFromFile("tableau_go.png",
        NULL);
    sfSprite_setTexture(menu->sp[2].oiseau, menu->sp[2].oiseau_texture,
        sfFalse);
    menu->sp[2].pos.x = 200;
    menu->sp[2].pos.y = 200;
    sfSprite_setPosition(menu->sp[2].oiseau, menu->sp[2].pos);
    menu->sp[2].scale = (sfVector2f) {1.2, 1.2};
    sfSprite_setScale(menu->sp[2].oiseau, menu->sp[2].scale);
    return 0;
}

static int create_menu_go(menu_t *menu, window_t *w1)
{
    tab(menu);
    exit_button(w1, menu);
    restart_button(w1, menu);
    return 0;
}

static int setupgo(menu_t *menu, window_t *w1)
{
    create_menu_go(menu, w1);
    return 0;
}

int suite(menu_t *menu, window_t *w1, sp_t *sp_go)
{
    sfRenderWindow_clear(w1->window, sfBlack);
    sfRenderWindow_drawSprite(w1->window, menu->background, NULL);
    sfRenderWindow_drawSprite(w1->window, menu->sp[2].oiseau, NULL);
    sfRenderWindow_drawSprite(w1->window, menu->sp[3].oiseau, NULL);
    sfRenderWindow_drawSprite(w1->window, menu->sp[4].oiseau, NULL);
    sfRenderWindow_drawSprite(w1->window, sp_go->oiseau, NULL);
    sfRenderWindow_display(w1->window);
    return 0;
}

int game_over(menu_t *menu, window_t *w1)
{
    sp_t sp_go;

    setupgo(menu, w1);
    game_over_sprite(&sp_go);
    while (sfRenderWindow_isOpen(w1->window)) {
        close_window(w1);
        if (w1->event1.type == sfEvtMouseButtonPressed)
            button_pressed(w1, menu);
        suite(menu, w1, &sp_go);
    }
    return 0;
}
