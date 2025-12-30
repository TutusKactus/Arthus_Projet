/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/


#ifndef MY_H
    #define MY_H

    #include "SFML/Graphics.h"
    #include "stdbool.h"

typedef struct window {
    sfRenderWindow *window;
    sfVideoMode video;
    sfEvent event1;
} window_t;

typedef struct game {
    sfSprite *background;
    sfTexture *background_texture;
} game_t;

typedef struct sprite {
    sfSprite *oiseau;
    sfTexture *oiseau_texture;
    sfFloatRect hitbox_sprite;
    sfClock *clock;
    sfTime elapsed;
    sfVector2f move;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    int i;
} sp_t;

typedef struct menu {
    sfSprite *start;
    sfTexture *start_texture;
    sfVector2f scale_start;
    sfSprite *background;
    sfTexture *background_texture;
    sfVector2f pos_start;
    sfSprite *exit;
    sfTexture *exit_texture;
    sfVector2f scale_exit;
    sfVector2f pos_exit;
    sfFont *score_font;
    sfText *score_text;
    char score_stockage[50];
    int score;
    int temp;
    int count;
    sp_t *sp;
    float secondes;
    float speed;
} menu_t;

int my_putchar(char c);
int game_screen(menu_t *menu, window_t *w1);
int close_window(window_t *w1);
int sprite_game(menu_t *menu);
int deplacement(menu_t *menu);
int display_sprite(menu_t *menu, window_t *w1);
int set_pos(menu_t *menu);
int display_hb(menu_t *menu, window_t *w1, int *i);
int game_over(menu_t *menu, window_t *w1);
int menu_game(window_t *w1);
int score_display(menu_t *menu);
int my_putstr(char const *str);
int flagh(void);

#endif
