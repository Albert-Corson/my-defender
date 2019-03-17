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
    if (ABS(angle) <= 15 || rot <= 5 || rot >= 355) {
        rot += angle;
    } else if (angle < 180) {
        rot += 3.0;
    } else {
        rot -= 3.0;
    }
    VFUNC(missile, set_rotation, rot);
    obj_set_speed(missile, -cos(RAD(rot)) * speed, -sin(RAD(rot)) * speed);
}

void missile_update(hub_t *hub, obj_t *missile)
{
    missile_data_t *extra = missile->extra;
    obj_t *target = extra->target;
    defense_obj_t *sender = extra->sender;
    enemy_data_t *target_extra = target->extra;
    sfVector2f pos = VGET(missile, get_position);
    sfFloatRect target_box = VGET(extra->target, get_box);
    game_scene_data_t *data = ((scene_t *)hub->scenes)->extra;

    if (sfFloatRect_contains(&target_box, pos.x, pos.y)) {
        if (target->state)
            target_extra->hp -= sender->dps;
        if (target_extra->hp <= 0) {
            target_extra->hp = 0;
            data->cash += 50;
            data->score += 50;
            obj_set_state(target, sfFalse);
        }
        obj_set_state(missile, sfFalse);
        return;
    } else
        missile_follow_target(missile);
}