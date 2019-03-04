/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game_evt
*/

#include "defender.h"

void game_pause(hub_t *hub, sfEvent evt)
{
    shape_obj_t *slider = NULL;

    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyEscape) {
        hub->scenes = list_fetch(hub->scenes, "pause_scene");
        slider = list_fetch(((scene_t *)hub->scenes)->objs, "general_sldr");
        VFUNC(slider, set_size, VECT2U(8 * sfListener_getGlobalVolume(), 80));
    }
}

void outline_focused_btn(hub_t *hub, sfEvent evt)
{
    input_obj_t *st_input = ((scene_t *)hub->scenes)->objs;
    input_obj_t *next = st_input->next;

    evt = evt;
    FAIL_IF_VOID(!st_input || !next);
    while (next != st_input) {
        if (next->type == input && next->mouse_evt->focus)
            rect_set_outline_color(st_input->background, sfRed);
        else if (next->type == input)
            rect_set_outline_color(st_input->background, sfTransparent);
        next = next->next;
    }
    if (next->type == input && next->mouse_evt->focus)
        rect_set_outline_color(st_input->background, sfRed);
    else if (next->type == input)
        rect_set_outline_color(st_input->background, sfTransparent);
}