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

    if (!extra->target->is_alive) {
        obj_kill(missile);
        return;
    }
    angle = objs_angle(missile, extra->target);
    rot = VGET(missile, get_rotation);
    if (ABS(angle) <= 15 || rot <= 5 || rot >= 355)
        rot += angle;
    else if (angle < 180)
        rot += 3.0;
    else
        rot -= 3.0;
    VFUNC(missile, set_rotation, rot);
    obj_set_speed(missile, -cos(RAD(rot)) * speed, -sin(RAD(rot)) * speed);
}

void missile_update(hub_t *hub, obj_t *missile)
{
    obj_t *target = ((missile_data_t *)missile->extra)->target;
    defense_obj_t *sender = ((missile_data_t *)missile->extra)->sender;
    enemy_data_t *target_extra = target->extra;
    sfVector2f pos = VGET(missile, get_position);
    sfFloatRect target_box = VGET(target, get_box);

    if (sfFloatRect_contains(&target_box, pos.x, pos.y)) {
        if (target->state)
            target_extra->hp -= sender->dps;
        if (target_extra->hp <= 0)
            enemy_kill(hub->scenes, target, sfTrue);
        obj_kill(missile);
    } else
        missile_follow_target(missile);
}