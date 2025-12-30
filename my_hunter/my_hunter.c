/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/

#include "SFML/Graphics.h"
#include "include/my.h"
#include "stdlib.h"
#include "stdio.h"

static int click_start_button(menu_t *menu, window_t *w1)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow *) w1->window);

    if (mouse.x <= 1143 && mouse.x >= 760 && mouse.y >= 676 && mouse.y <= 830)
        if (w1->event1.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(w1->window);
        }
    if (mouse.x <= 1145 && mouse.x >= 762 && mouse.y >= 114 && mouse.y <= 275)
        if (w1->event1.type == sfEvtMouseButtonPressed) {
            game_screen(menu, w1);
        }
    return 0;
}

static int exit_sprite(menu_t *menu)
{
    menu->exit = sfSprite_create();
    menu->exit_texture = sfTexture_createFromFile("exit_button.png", NULL);
    menu->pos_exit = (sfVector2f) {750, 550};
    menu->scale_exit = (sfVector2f) {0.4, 0.4};
    sfSprite_setScale(menu->exit, menu->scale_exit);
    sfSprite_setPosition(menu->exit, menu->pos_exit);
    sfSprite_setTexture(menu->exit, menu->exit_texture, sfFalse);
    return 0;
}

int sprite_menu(menu_t *menu, window_t *w1)
{
    exit_sprite(menu);
    menu->background = sfSprite_create();
    menu->background_texture = sfTexture_createFromFile("fond.jpg", NULL);
    menu->start_texture = sfTexture_createFromFile("startv2.png", NULL);
    menu->start = sfSprite_create();
    menu->pos_start = (sfVector2f) {750, -10};
    menu->scale_start = (sfVector2f) {0.4, 0.4};
    sfSprite_setScale(menu->start, menu->scale_start);
    sfSprite_setPosition(menu->start, menu->pos_start);
    sfSprite_setTexture(menu->start, menu->start_texture, sfFalse);
    sfSprite_setTexture(menu->background, menu->background_texture, sfFalse);
    return 0;
}

int create_window(window_t *w1)
{
    w1->video = (sfVideoMode){1920, 1080, 32};
    w1->window = sfRenderWindow_create(w1->video, "1ere window", sfClose |
        sfResize, NULL);
    return 0;
}

int close_window(window_t *w1)
{
    while (sfRenderWindow_pollEvent(w1->window, &w1->event1)) {
        if (w1->event1.type == sfEvtClosed)
            sfRenderWindow_close(w1->window);
    }
    return 0;
}

int menu_game(window_t *w1)
{
    menu_t menu;

    menu.score = 0;
    sprite_menu(&menu, w1);
    sfRenderWindow_setFramerateLimit(w1->window, 60);
    while (sfRenderWindow_isOpen(w1->window)) {
        close_window(w1);
        sfRenderWindow_drawSprite(w1->window, menu.background, NULL);
        sfRenderWindow_drawSprite(w1->window, menu.start, NULL);
        sfRenderWindow_drawSprite(w1->window, menu.exit, NULL);
        click_start_button(&menu, w1);
        sfRenderWindow_display(w1->window);
    }
    return 0;
}

int main(int argc, char **argv)
{
    window_t w1;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        flagh();
        return 0;
    }
    create_window(&w1);
    menu_game(&w1);
    return 0;
}
