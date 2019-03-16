/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** defense_evts
*/

#include "defender.h"

void missile_update(obj_t *missile);

void defense_lock_target(hub_t *hub, obj_t *obj)
{
    defense_obj_t *defense = (defense_obj_t *)obj;
    float range = defense->range;
    obj_t *tower = (obj_t *)defense->tower;
    obj_t *target = defense->target;
    obj_t *begin = ((scene_t *)hub->scenes)->objs;
    obj_t *curr = NULL;

    if (target) {
        if (!target->state || objs_distance(obj, target) > range) {
            defense->target = NULL;
        } else {
            VFUNC(defense, set_rotation, objs_angle(tower, target));
            return;
        }
    }
    while (list_poll((void *)begin, (void **)&curr)) {
        if (curr->group == GR_ENEMY && objs_distance(obj, curr) <= range) {
            defense->target = curr;
            return;
        }
    }
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
        missile = missile_new(defense, "bullet");
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
            missile_update(curr);
        }
        if (curr->state && curr->group == GR_ENEMY) {
            enemy_update_lifebar((void *)curr);
            enemy_move(hub, (obj_t *)curr);
        }
    }
}