/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_scenes
*/

#include "defender.h"

int create_scenes(hub_t *hub)
{
    int parsing_failure = 0;

    pres_scene_create(hub);
    menu_scene_create(hub);
    options_scene_create(hub);
    parsing_failure = game_scene_create(hub);
    pause_scene_create(hub);
    score_scene_create(hub);
    return (1);
    return (parsing_failure);
}