/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** options_evt
*/

#include "defender.h"

void outline_hovered_btn(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    input_obj_t *st_input = scene->objs;
    input_obj_t *next = NULL;

    evt = evt;
    FAIL_IF_VOID(!st_input);
    while (list_poll(st_input, (void **)&next)) {
        if (next->type == input && next->mouse_evt->hover)
            rect_set_outline_color(next->background, sfRed);
        else if (next->type == input && next->background)
            rect_set_outline_color(next->background, sfBlack);
    }
}

void pause_esc_key(hub_t *hub, sfEvent evt)
{
    evt = evt;
    FAIL_IF_VOID(!hub);
    if (KRELEASED(evt, sfKeyEscape))
        hub->scenes = list_fetch(hub->scenes, "game_scene");
}