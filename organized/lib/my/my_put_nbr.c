/*
** EPITECH PROJECT, 2025
** cpoolday03
** File description:
** task01
*/
#include "unistd.h"
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb >= 0 && nb < 10) {
        count += my_putchar(nb + 48);
    } else if (nb < 0) {
        count += my_putchar('-');
        my_put_nbr(nb * (-1));
    } else {
        count += my_put_nbr(nb / 10);
        count += my_put_nbr(nb % 10);
    }
    return count;
}
