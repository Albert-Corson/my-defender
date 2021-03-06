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
    enemy_data_t *extra = st_enemy->extra;

    FAIL_IF_VOID(!st_enemy || !st_enemy->extra);
    rect_destroy(extra->lifebar);
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
    enemy->extra = enemy_data_new(400 * life_multiplier, aspect);
    path = my_format("assets/img/mob/%s.png", aspect);
    anim = anim_new(path, 1, 0);
    anim_obj_add_anim(enemy, anim, NULL);
}

void *enemy_data_new(float max_hp, char *aspect)
{
    enemy_data_t *extra = malloc(sizeof(enemy_data_t));

    extra->aerial = (*aspect == 'f');
    extra->ground = (*aspect != 'f');
    extra->hp = max_hp;
    extra->max_hp = max_hp;
    extra->speed = (*aspect == 'f' ? 5 : 3);
    extra->tile_step = 0;
    extra->lifebar = rect_new(VECT2U(50, 7.5), sfRed);
    extra->lifebar_size = 50;
    return (extra);
}

void *enemy_new(char *aspect, sfVector2f pos, float life_multiplier)
{
    anim_obj_t *st_enemy = malloc(sizeof(anim_obj_t));

    FAIL_IF(!aspect || !st_enemy, NULL);
    enemy_ctor(st_enemy, aspect, life_multiplier);
    st_enemy->vtable->set_size = enemy_set_size;
    st_enemy->vtable->set_scale = enemy_set_scale;
    st_enemy->vtable->set_position = enemy_set_position;
    st_enemy->vtable->render = enemy_render;
    VFUNC(st_enemy, set_position, pos);
    return ((void *)st_enemy);
}

void enemy_spawn(scene_t *scene, char *aspect, float multiplier)
{
    game_scene_data_t *data = scene->extra;
    sfVector2f pos = VECT2F(31 * 50, 0);
    anim_obj_t *enemy = NULL;

    FAIL_IF_VOID(!data || !data->map);
    pos.y = find_spawn_y(data->map) * 50;
    enemy = enemy_new(aspect, pos, multiplier);
    VFUNC(enemy, set_size, VECT2U(50, 50));
    VFUNC(enemy, set_origin, VECT2F(25, 25));
    scene_add_obj(scene, enemy, NULL);
}