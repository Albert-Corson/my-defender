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
    defense_data_t *extra = NULL;
    obj_t *curr = NULL;

    FAIL_IF_VOID(!defense || !defense->extra);
    extra = defense->extra;
    if (extra->target) {
        if (objs_distance(defense, extra->target) > extra->range) {
            extra->target = NULL;
        } else {
            VFUNC(defense, set_rotation, objs_angle(defense, extra->target));
            return;
        }
    }
    while (list_poll(((scene_t *)hub->scenes)->objs, (void *)&curr)) {
        if (curr->group == 2 && objs_distance(defense, curr) <= extra->range) {
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
    obj_t *curr = NULL;

    evt = evt;
    FAIL_IF_VOID(!hub || !hub->scenes || !((scene_t *)hub->scenes)->objs);
    while (list_poll(((scene_t *)hub->scenes)->objs, (void *)&curr)) {
        if (curr->state && curr->group == 3) {
            defense_lock_target(hub, curr);
            defense_fire(hub, curr);
        } else if (curr->state && curr->group == 4) {
            missile_update(curr);
        }
    }
}