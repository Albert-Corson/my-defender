/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** defense_set
*/

#include "defender.h"

void defense_obj_set_pos(void *obj, sfVector2f pos)
{
    defense_obj_t *defense = obj;

    FAIL_IF_VOID(!obj);
    anim_obj_set_position(defense->tower, pos);
    anim_obj_set_position(defense->base, pos);
}

void defense_obj_set_origin(void *obj, sfVector2f origin)
{
    defense_obj_t *defense = obj;

    FAIL_IF_VOID(!obj);
    anim_obj_set_origin(defense->tower, origin);
    anim_obj_set_origin(defense->base, origin);
}

void defense_obj_set_scale(void *obj, sfVector2f scale)
{
    defense_obj_t *defense = obj;

    FAIL_IF_VOID(!obj);
    anim_obj_set_scale(defense->tower, scale);
    anim_obj_set_scale(defense->base, scale);
}

void defense_obj_set_rotation(void *obj, float angle)
{
    defense_obj_t *defense = obj;

    FAIL_IF_VOID(!obj);
    anim_obj_set_rotation(defense->tower, angle);
}