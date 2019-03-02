/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** options_evt
*/

#include "defender.h"

void options_show_menu(hub_t *hub, sfEvent evt)
{
    input_obj_t *obj = list_fetch(((scene_t *)hub->scenes)->objs, "back_btn");

    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyEscape)
        hub->scenes = list_fetch(hub->scenes, "menu_scene");
    FAIL_IF_VOID(!obj)
    if (!obj->mouse_evt->hover || obj->mouse_evt->active)
        rect_set_outline_color(obj->background, sfBlack);
    else
        rect_set_outline_color(obj->background, sfRed);
    if (obj->mouse_evt->active) {
        obj->mouse_evt->active = sfFalse;
        obj->mouse_evt->hover = sfFalse;
        hub->scenes = list_fetch(hub->scenes, "menu_scene");
    }
}