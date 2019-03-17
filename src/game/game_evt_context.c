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

    evt = evt;
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
}

void update_tower_lifebar_evt(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    game_scene_data_t *data = scene->extra;
    obj_t *lifebar = list_fetch(scene->objs, "lifebar");
    obj_t *lifebar_back = list_fetch(scene->objs, "back_lifebar");
    sfVector2u size = {0, 0};

    evt = evt;
    FAIL_IF_VOID(!lifebar || !lifebar_back || !data);
    size = rect_get_size(lifebar_back);
    size = VECT2U(data->tower_hp * size.x / data->max_tower_hp, size.y);
    VFUNC(lifebar, set_size, size);
}