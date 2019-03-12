/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_scenes
*/

#include "defender.h"

void create_scenes(hub_t *hub, char *mappath)
{
    pres_scene_create(hub);
    menu_scene_create(hub);
    options_scene_create(hub);
    game_scene_create(hub, mappath);
    pause_scene_create(hub);
    test_scene_create(hub);
}