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

    FAIL_IF_VOID(!obj)
    if (obj->mouse_evt->active || KRELEASED(evt, sfKeyEscape)) {
        obj->mouse_evt->active = sfFalse;
        obj->mouse_evt->hover = sfFalse;
        rect_set_outline_color(obj->background, sfBlack);
        if (hub->scenes->sound)
            sfSound_play(hub->scenes->sound);
        hub->scenes = list_fetch(hub->scenes, "menu_scene");
        return;
    }
    if (!obj->mouse_evt->hover) {
        rect_set_outline_color(obj->background, sfBlack);
    } else if (rect_get_outline_color(obj->background).r != 255) {
        if (obj->sound)
            sfSound_play(obj->sound);
        rect_set_outline_color(obj->background, sfRed);
    }
}