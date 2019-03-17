/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "defender.h"

int random_between(int min, int max)
{
    return (((float)rand() / RAND_MAX) * ((max - min) + 1) + min);
}