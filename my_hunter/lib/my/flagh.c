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

int flagh(void)
{
    my_putstr("GOAL :");
    my_putchar('\n');
    my_putstr("    Click on the bird, it's easy, you will get point ");
    my_putstr("when you kill one");
    my_putchar('\n');
    my_putstr("    You have 4 lives, if a bird touch the right ");
    my_putstr("side of your screen, you lose one life\n");
    return 0;
}
