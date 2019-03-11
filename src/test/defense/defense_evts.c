/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** defense_evts
*/

#include "defender.h"

void missile_update(obj_t *missile);

void defense_lock_target(hub_t *hub, obj_t *defense)
{
    defense_data_t *extra = defense->extra;
    float range = extra->range;
    obj_t *target = extra->target;
    obj_t *begin = ((scene_t *)hub->scenes)->objs;
    obj_t *curr = NULL;

    if (extra->target) {
        if (!target->state || objs_distance(defense, target) > range) {
            extra->target = NULL;
        } else {
            VFUNC(defense, set_rotation, objs_angle(defense, target));
            return;
        }
    }
    while (list_poll((void *)begin, (void *)&curr)) {
        if (curr->group == GR_ENEMY && objs_distance(defense, curr) <= range) {
            extra->target = curr;
            return;
        }
    }
}

void defense_fire(hub_t *hub, obj_t *defense)
{
    sfInt64 delay = 0;
    defense_data_t *extra = NULL;
    anim_obj_t *missile = NULL;

    FAIL_IF_VOID(!hub || !defense || !defense->extra);
    extra = defense->extra;
    FAIL_IF_VOID(!extra->target);
    delay = sfClock_getElapsedTime(extra->timer).microseconds;
    if (delay / 1000 >= extra->firerate) {
        missile = missile_new(defense, "bullet");
        scene_add_obj(hub->scenes, missile, NULL);
        sfClock_restart(extra->timer);
    }
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
    }
}