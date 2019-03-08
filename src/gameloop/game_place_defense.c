/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game_place_defense
*/

#include "defender.h"

sfVector2f get_positioning(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f rtn = VECT2F(mouse.x - (mouse.x % 60), mouse.y - (mouse.y % 60));

    if (rtn.y >= 780)
        return (VECT2F(-1, -1));
    return (rtn);
}