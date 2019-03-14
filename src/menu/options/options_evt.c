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
    if (KRELEASED(evt, sfKeyEscape)) {
        obj->mouse_evt->active = sfFalse;
        obj->mouse_evt->hover = sfFalse;
        obj->mouse_evt->focus = sfTrue;
        rect_set_outline_color(obj->background, sfBlack);
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = list_fetch(hub->scenes, "menu_scene");
        return;
    }
    if (!obj->mouse_evt->hover) {
        rect_set_outline_color(obj->background, sfBlack);
    } else if (rect_get_outline_color(obj->background).r != 255) {
        obj_sound_apply((obj_t *)obj, sfSound_play);
        rect_set_outline_color(obj->background, sfRed);
    }
}