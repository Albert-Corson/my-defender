/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_scenes
*/

#include "defender.h"

int create_scenes(hub_t *hub, char *mappath)
{
    int parsing_failure = 0;

    pres_scene_create(hub);
    menu_scene_create(hub);
    options_scene_create(hub);
    parsing_failure = game_scene_create(hub, mappath);
    pause_scene_create(hub);
    test_scene_create(hub);
    return (parsing_failure);
}