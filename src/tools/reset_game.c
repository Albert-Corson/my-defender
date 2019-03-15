/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** reset_game
*/

#include "defender.h"

void reset_game(hub_t *hub)
{
    node_pop(list_fetch(hub->scenes, "game_scene"));
    game_scene_create(hub);
}