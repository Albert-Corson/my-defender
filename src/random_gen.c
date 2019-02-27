/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "defender.h"

int readjust_nb(int nb, int min, int max)
{
    while (nb < min)
        nb -= (min - max) - 1;
    while (nb > max)
        nb += (min - max) - 1;
    return (nb);
}

int random_nbr(sfClock *random)
{
    srand(sfClock_getElapsedTime(random).microseconds);

    return (rand());
}

int random_clamp(sfClock *random, int min, int max)
{
    int nbr = random_nbr(random) / RAND_MAX;

    if (min == max)
        return (max);
    if (min > max)
        return (0);
    return (nbr * (max - min + 1) + min);
}