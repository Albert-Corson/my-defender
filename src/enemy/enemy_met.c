/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** enemy_met
*/

#include "defender.h"

void enemy_render(void *obj, hub_t *hub)
{
    anim_obj_t *anim = obj;
    enemy_data_t *data = anim ? anim->extra : NULL;

    FAIL_IF_VOID(!anim);
    anim_obj_render(anim, hub);
    rect_render(data->lifebar, hub);
}