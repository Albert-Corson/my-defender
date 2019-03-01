/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** menu_evt
*/

#include "defender.h"

void menu_show_pres(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyEscape)
        hub->scenes = list_fetch(hub->scenes, "pres_scene");
}

void place_arrow(hub_t *hub, sfEvent evt)
{
    scene_t *scene = list_fetch(hub->scenes, "menu_scene");
    obj_t *objs = scene ? scene->objs : NULL;
    obj_t *next = objs ? objs->next : NULL;
    anim_obj_t *arrow = objs ? list_fetch(objs, "arrow") : NULL;
    sfVector2f arr_pos = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    evt = evt;
    FAIL_IF_VOID(!scene || !arrow);
    while (next != objs) {
        if (next->type == input && next->mouse_evt->hover)
            objs = next;
        else
            next = next->next;
    }
    if (next->type != input || !next->mouse_evt->hover)
        return;
    box = input_obj_get_box(next);
    arr_pos = (sfVector2f){box.left - VGET(arrow, get_size).x - 20, box.top};
    VFUNC(arrow, set_position, arr_pos);
}