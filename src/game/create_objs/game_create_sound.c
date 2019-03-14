/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_sound
*/

#include "defender.h"

void game_create_sounds(hub_t *hub, scene_t *game)
{
    sound_obj_t *new = sound_obj_new(hub, "place_defense");

    scene_add_obj(game, new, "sfx_place");
    new = sound_obj_new(hub, "erease");
    scene_add_obj(game, new, "sfx_erease");
    new = sound_obj_new(hub, "emp_explo");
    scene_add_obj(game, new, "sfx_explosion");
    new = sound_obj_new(hub, "missile_explo");
    scene_add_obj(game, new, "sfx_missile_explo");
    new = sound_obj_new(hub, "upgrade");
    scene_add_obj(game, new, "sfx_upgrade");
}