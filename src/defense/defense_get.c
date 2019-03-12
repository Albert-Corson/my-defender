/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** defense_get
*/

#include "defender.h"

sfVector2f defense_obj_get_pos(void *obj)
{
    defense_obj_t *defense = obj;

    FAIL_IF(!obj, VECT2F(0, 0));
    return(anim_obj_get_position(defense->tower));
}

sfVector2f defense_obj_get_origin(void *obj)
{
    defense_obj_t *defense = obj;

    FAIL_IF(!obj, VECT2F(0, 0));
    return(anim_obj_get_origin(defense->tower));
}

sfFloatRect defense_obj_get_box(void *obj)
{
    defense_obj_t *defense = obj;

    FAIL_IF(!obj, RECT(0, 0, 0, 0));
    return(anim_obj_get_box(defense->tower));
}

float defense_obj_get_rotation(void *obj)
{
    defense_obj_t *defense = obj;

    FAIL_IF(!obj, 0);
    return(anim_obj_get_rotation(defense->tower));
}

sfVector2f defense_obj_get_scale(void *obj)
{
    defense_obj_t *defense = obj;

    FAIL_IF(!obj, VECT2F(0, 0));
    return(anim_obj_get_scale(defense->tower));
}