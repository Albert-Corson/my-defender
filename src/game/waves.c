/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** waves
*/

#include "defender.h"

void spawn_appropriate_enemy(scene_t *scene)
{
    game_scene_data_t *data = scene->extra;
    char enemies[5][32];
    my_memcpy(enemies[0], "tank_1", -1);
    my_memcpy(enemies[1], "tank_2", -1);
    my_memcpy(enemies[2], "tank_3", -1);
    my_memcpy(enemies[3], "mothership", -1);
    my_memcpy(enemies[4], "fighter", -1);

    if (data->wave < 3)
        enemy_spawn(scene, enemies[random_between(0, 2)], 1);
    else if (data->wave < 5)
        enemy_spawn(scene, enemies[random_between(0, 3)], 1);
    else
        enemy_spawn(scene, enemies[random_between(0, 4)], 1);
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
        spawn_appropriate_enemy(hub->scenes);
        data->enemies_count--;
        data->alive_enemies++;
    }
}