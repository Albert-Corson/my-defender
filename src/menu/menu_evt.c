/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** menu_evt
*/

#include "defender.h"

void menu_show_pres(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyEscape) {
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = list_fetch(hub->scenes, "pres_scene");
    }
}

void menu_place_arrow(hub_t *hub, sfEvent evt)
{
    scene_t *scene = list_fetch(hub->scenes, "menu_scene");
    obj_t *objs = scene ? scene->objs : NULL;
    obj_t *next = NULL;
    anim_obj_t *arrow = objs ? list_fetch(objs, "arrow") : NULL;
    sfVector2f arr_pos = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    evt = evt;
    FAIL_IF_VOID(!scene || !arrow);
    arr_pos = VGET(arrow, get_position);
    while (list_poll(objs, (void **)&next)) {
        if (next->type == input && next->mouse_evt->hover)
            objs = NULL;
    }
    FAIL_IF_VOID(next->type != input || !next->mouse_evt->hover)
    box = input_obj_get_box(next);
    if (next->sound && box.top + 15 != arr_pos.y)
        sfSound_play(next->sound);
    arr_pos = VECT2F(box.left - VGET(arrow, get_size).x - 20, box.top + 15);
    VFUNC(arrow, set_position, arr_pos);
}