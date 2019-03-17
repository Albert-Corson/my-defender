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

void update_wave_evt(hub_t *hub, sfEvent evt)
{
    game_scene_data_t *data = ((scene_t *)hub->scenes)->extra;
    data->elapsed_wave += sfClock_getElapsedTime(hub->timer).microseconds;
    int delay = 500 - (20 * data->wave);
    sfBool end_of_wave = data->alive_enemies <= 0 && data->enemies_count <= 0;

    evt = evt;
    delay = delay < 100 ? 100 : delay;
    if (end_of_wave && data->elapsed_wave / 1000 > 2000) {
        data->elapsed_wave -= 2000 * 1000;
        data->wave++;
        data->enemies_count = data->wave * 2;
    }
    while (data->enemies_count > 0 && data->elapsed_wave / 1000 > delay) {
        data->elapsed_wave -= 1000 * delay;
        enemy_spawn(hub->scenes, "tank_1", 1);
        data->enemies_count--;
        data->alive_enemies++;
    }
}

void update_wave_text(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    game_scene_data_t *data = scene ? scene->extra : NULL;
    text_obj_t *text = list_fetch(scene->objs, "wave_text");
    char *str = my_format("WAVE: %d", data ? data->wave : 0);

    evt = evt;
    FAIL_IF_VOID(!scene || !text);
    text_obj_set_string(text, str);
    free(str);
}

void check_tower_life(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    game_scene_data_t *data = scene ? scene->extra : NULL;
    scene_t *score = list_fetch(hub->scenes, "score_scene");

    evt = evt;
    FAIL_IF_VOID(data->tower_hp > 0 || !score);
    hub->scenes = score;
}