/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "defender.h"

static void leave_scene(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyReleased || evt.type == sfEvtMouseButtonReleased)
        hub->scenes = ((scene_t *)hub->scenes)->next;
}

void menu_scene_create(hub_t *hub)
{
    scene_t *menu = scene_new();
    anim_t *tower = anim_new("assets/img/icon.png", 1, 0);
    anim_obj_t *icon = anim_obj_new();

    anim_obj_add_anim(icon, tower, "tower");
    anim_obj_set_position(icon, (sfVector2f){80, 170});
    anim_obj_set_scale(icon, (sfVector2f){2.2, 2.2});
    scene_add_obj(menu, icon, "tower");
    scene_add_evt(menu, evt_new(leave_scene, inputs), "leave_scene");
    hub_add_scene(hub, menu, "menu");
}