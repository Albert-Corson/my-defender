/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** missile_evts
*/

#include "defender.h"

void missile_follow_target(obj_t *missile)
{
    missile_data_t *extra = missile->extra;
    float angle = 0;
    float rot = 0;

    angle = objs_angle(missile, extra->target);
    rot = VGET(missile, get_rotation);
    if (ABS(angle) < 5)
        rot += angle;
    else if (angle < 180)
        rot += 1.5;
    else
        rot -= 1.5;
    VFUNC(missile, set_rotation, rot);
    obj_set_speed(missile, -cos(RAD(rot)) * 5, -sin(RAD(rot)) * 5);
}

void missile_update(obj_t *missile)
{
    missile_data_t *extra = missile->extra;
    sfVector2f pos = {0, 0};
    sfFloatRect target_box = VGET(extra->target, get_box);

    pos = VGET(missile, get_position);
    if (sfFloatRect_contains(&target_box, pos.x, pos.y)) {
        obj_set_state(missile, sfFalse);
        return;
    } else {
        missile_follow_target(missile);
    }
}