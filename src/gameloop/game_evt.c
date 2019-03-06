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

    if (KRELEASED(evt, sfKeyEscape)) {
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = list_fetch(hub->scenes, "pause_scene");
        slider = list_fetch(hub->scenes->objs, "general_sldr");
        VFUNC(slider, set_size, VECT2U(8 * sfListener_getGlobalVolume(), 80));
    }
}

void outline_focused_btn(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    input_obj_t *st_input = scene->objs;
    input_obj_t *next = NULL;
    input_obj_t *tmp = NULL;
    sfColor save;

    evt = evt;
    FAIL_IF_VOID(!st_input);
    while (list_poll(st_input, (void **)&next)) {
        if (next->type == input && next->mouse_evt->focus) {
            tmp = next;
            save = rect_get_outline_color(next->background);
            rect_set_outline_color(next->background, sfBlack);
        } else if (next->type == input)
            rect_set_outline_color(next->background, RGBA(0, 0, 0, 0));
    }
    if (save.a != 255 && tmp)
        scene_sound_apply(hub->scenes, sfSound_play);
}