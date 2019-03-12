/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** defense_met
*/

#include "defender.h"

void defense_obj_render(void *obj, hub_t *hub)
{
    defense_obj_t *defense = obj;

    FAIL_IF_VOID(!defense);
    anim_obj_render(defense->base, hub);
    anim_obj_render(defense->tower, hub);
}