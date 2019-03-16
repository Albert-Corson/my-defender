/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game_evt_context
*/

#include "defender.h"

void update_cash(hub_t *hub, sfEvent evt)
{
    game_scene_data_t *data = ((scene_t *)hub->scenes)->extra;
    text_obj_t *text = list_fetch(((scene_t *)hub->scenes)->objs, "cash_text");
    char *str = NULL;
    int delay = 500;

    delay -= ((data->wave - (data->wave % 2)) / 2) * 10;
    delay = delay < 150 ? 150 : delay;
    data->elapsed += sfClock_getElapsedTime(hub->timer).microseconds;
    while (data->elapsed / 1000 > delay) {
        data->elapsed -= 1000 * delay;
        data->cash += 25;
        data->score += 25;
    }
    str = my_format("%d", data->cash);
    text_obj_set_string(text, str);
    free(str);
    evt = evt;
}

void update_tower_lifebar(hub_t *hub, sfEvent evt)
{
    anim_obj_t *tower = list_fetch(((scene_t *)hub->scenes)->objs, "tower");
    shape_obj_t *rect = list_fetch(((scene_t *)hub->scenes)->objs, "lifebar");
    enemy_data_t *data = tower ? tower->extra : NULL;
    shape_obj_t *bckg;
    sfVector2u size;

    evt = evt;
    bckg = list_fetch(((scene_t *)hub->scenes)->objs, "back_lifebar");
    FAIL_IF_VOID(!tower || !rect);
    size.x = (data->hp / data->max_hp) * VGET(bckg, get_size).x;
    VFUNC(rect, set_size, size);
}