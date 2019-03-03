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
    float speed = extra->speed;
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
    obj_set_speed(missile, -cos(RAD(rot)) * speed, -sin(RAD(rot)) * speed);
}

void missile_update(obj_t *missile)
{
    missile_data_t *extra = missile->extra;
    obj_t *target = extra->target;
    defense_data_t *sender_extra = extra->sender->extra;
    ennemy_data_t *target_extra = extra->target->extra;
    sfVector2f pos = {0, 0};
    sfFloatRect target_box = VGET(extra->target, get_box);

    pos = VGET(missile, get_position);
    if (!target->state || sfFloatRect_contains(&target_box, pos.x, pos.y)) {
        if (target->state)
            target_extra->hp -= sender_extra->dps;
        if (target_extra->hp <= 0) {
            target_extra->hp = 0;
            obj_set_state(target, sfFalse);
        }
        obj_set_state(missile, sfFalse);
        return;
    } else {
        missile_follow_target(missile);
    }
}