/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game_data
*/

#include "defender.h"

void game_scene_create_data(scene_t *scene)
{
    game_scene_data_t *data = malloc(sizeof(game_scene_data_t));

    data->map = NULL;
    data->wave = 1;
    data->cash = 500;
    data->elapsed = 0;
    data->elapsed_wave = 0;
    data->max_tower_hp = 10000;
    data->enemies_count = 3;
    data->alive_enemies = 0;
    data->tower_hp = 10000;
    data->dtor = game_scene_data_dtor;
    scene->extra = data;
}

void game_scene_data_dtor(void *extra)
{
    game_scene_data_t *data = extra;
    int line = 0;

    while (line < 16) {
        free(data->map[line]);
        ++line;
    }
    free(data->map);
    data->elapsed = 0;
    data->elapsed_wave = 0;
    data->wave = 0;
    data->cash = 0;
}