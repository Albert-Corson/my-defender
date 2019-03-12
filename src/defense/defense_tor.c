/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create
*/

#include "defender.h"

void *defense_new(char *aspect, int lvl, sfVector2f pos)
{
    defense_obj_t *st_defense = malloc(sizeof(*st_defense));
    char *path_tower = NULL;
    char *path_base = NULL;

    FAIL_IF(!aspect || !st_defense || lvl > 3 || lvl < 0, NULL);
    defense_ctor(st_defense, lvl);
    path_tower = my_format("assets/img/mob/%s_%d.png", aspect, lvl);
    path_base = my_format("assets/img/mob/base_%d.png", lvl);
    st_defense->tower = create_anim_obj(path_tower, pos, 1, -1);
    st_defense->base = create_anim_obj(path_base, pos, 1, -1);
    obj_recenter_origin(st_defense->tower);
    obj_recenter_origin( st_defense->base);
    free(path_tower);
    free(path_base);
    st_defense->aspect = aspect;
    st_defense->physics = physics_new(st_defense);
    return (st_defense);
}

void defense_ctor(defense_obj_t *st_defense, int lvl)
{
    FAIL_IF_VOID(!st_defense || lvl < 0 || lvl > 3);
    obj_ctor(st_defense, custom, sfFalse);
    st_defense->vtable = defense_obj_vtable_new();
    st_defense->label = NULL;
    st_defense->dtor = defense_dtor;
    st_defense->group = GR_DEFENSE;
    st_defense->level = lvl;
    st_defense->dps = 100;
    st_defense->range = 400;
    st_defense->target = NULL;
    st_defense->firerate = 1000;
    st_defense->elapsed = 0;
}

void defense_dtor(void *defense)
{
    defense_obj_t *st_defense = defense;

    FAIL_IF_VOID(!st_defense);
    obj_dtor(st_defense);
    node_destroy(st_defense->tower);
    node_destroy(st_defense->base);
}

void defense_destroy(void *defense)
{
    FAIL_IF_VOID(!defense);
    defense_dtor(defense);
    free(defense);
}