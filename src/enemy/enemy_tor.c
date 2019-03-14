/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** enemy_tor
*/

#include "defender.h"

void enemy_dtor(void *enemy)
{
    anim_obj_t *st_enemy = (anim_obj_t *)enemy;

    FAIL_IF_VOID(!st_enemy || !st_enemy->extra);
    free(st_enemy->extra);
    st_enemy->extra = NULL;
    anim_obj_dtor(enemy);
}

void enemy_ctor(anim_obj_t *enemy, char *aspect, float life_multiplier)
{
    char *path = NULL;
    anim_t *anim = NULL;

    FAIL_IF_VOID(!enemy || !aspect);
    anim_obj_ctor(enemy);
    enemy->dtor = enemy_dtor;
    enemy->group = GR_ENEMY;
    enemy->extra = enemy_data_new(400 * life_multiplier, 3);
    path = my_format("assets/img/mob/%s.png", aspect);
    anim = anim_new(path, 1, 0);
    anim_obj_add_anim(enemy, anim, NULL);
}

void *enemy_data_new(float max_hp, float speed)
{
    enemy_data_t *extra = malloc(sizeof(enemy_data_t));

    extra->aerial = sfFalse;
    extra->ground = sfTrue;
    extra->hp = max_hp;
    extra->max_hp = max_hp;
    extra->speed = speed;
    extra->tile_step = 0;
    return (extra);
}

void *enemy_new(char *aspect, sfVector2f pos, float life_multiplier)
{
    anim_obj_t *st_enemy = malloc(sizeof(anim_obj_t));

    FAIL_IF(!aspect || !st_enemy, NULL);
    enemy_ctor(st_enemy, aspect, life_multiplier);
    VFUNC(st_enemy, set_position, pos);
    return ((void *)st_enemy);
}

void enemy_spawn(scene_t *scene)
{
    game_scene_data_t *data = scene->extra;
    sfVector2f pos = VECT2F(31 * 50, 0);
    anim_obj_t *enemy = NULL;

    FAIL_IF_VOID(!data || !data->map);
    pos.y = find_spawn_y(data->map) * 50;
    enemy = enemy_new("mothership_2", pos, 1);
    VFUNC(enemy, set_size, VECT2U(50, 50));
    scene_add_obj(scene, enemy, NULL);
}