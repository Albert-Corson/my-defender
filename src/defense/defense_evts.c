/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** defense_evts
*/

#include "defender.h"

void acquire_target(hub_t *hub, defense_obj_t *defense)
{
    obj_t *begin = ((scene_t *)hub->scenes)->objs;
    obj_t *curr = NULL;
    enemy_data_t *data = NULL;
    float range = defense->range;
    float distance = 0;
    sfBool in_range = sfFalse;
    sfBool compatible = sfFalse;

    while (list_poll((void *)begin, (void **)&curr)) {
        data = curr->extra;
        distance = objs_distance((obj_t *)defense, curr);
        in_range = distance <= range;
        compatible = curr->group == GR_ENEMY && curr->state && data;
        compatible = compatible && (data->aerial ? defense->aerial : sfTrue);
        compatible = compatible && (data->ground ? defense->ground : sfTrue);
        if (compatible && in_range) {
            defense->target = curr;
            return;
        }
    }
}

void defense_lock_target(hub_t *hub, obj_t *obj)
{
    defense_obj_t *defense = (defense_obj_t *)obj;
    obj_t *target = defense->target;
    anim_obj_t *tower = defense->tower;
    float range = defense->range;

    if (target) {
        if (!target->state || objs_distance(obj, target) > range) {
            defense->target = NULL;
        } else {
            VFUNC(defense, set_rotation, objs_angle((obj_t *)tower, target));
            return;
        }
    }
    acquire_target(hub, defense);
}

void defense_fire(hub_t *hub, obj_t *obj)
{
    defense_obj_t *defense = (defense_obj_t *)obj;
    sfInt64 delay = 0;
    anim_obj_t *missile = NULL;

    FAIL_IF_VOID(!hub || !defense || !defense->target);
    delay = sfClock_getElapsedTime(hub->timer).microseconds / 1000;
    delay += defense->elapsed;
    if (delay >= defense->firerate) {
        missile = missile_new(defense, defense->aspect);
        scene_add_obj(hub->scenes, missile, NULL);
        delay -= defense->firerate;
    }
    defense->elapsed = delay;
}

void defense_update_evt(hub_t *hub, sfEvent evt)
{
    obj_t *begin = ((scene_t *)hub->scenes)->objs;
    obj_t *curr = NULL;

    evt = evt;
    FAIL_IF_VOID(!hub || !hub->scenes || !((scene_t *)hub->scenes)->objs);
    while (list_poll((void *)begin, (void *)&curr)) {
        if (curr->state && curr->group == GR_DEFENSE) {
            defense_lock_target(hub, curr);
            defense_fire(hub, curr);
        } else if (curr->state && curr->group == GR_MISSILE) {
            missile_update(hub, curr);
        }
        if (curr->state && curr->group == GR_ENEMY) {
            enemy_update_lifebar((void *)curr);
            enemy_move(hub, (obj_t *)curr);
        }
    }
}