/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create
*/

#include "defender.h"

obj_t *base_create(int lvl)
{
    anim_obj_t *obj = NULL;
    char *path = NULL;
    anim_t *anim = NULL;

    FAIL_IF(lvl < 0 || lvl > 3 || !(obj = anim_obj_new()), NULL);
    path = my_format("assets/img/mob/base_%d.png", lvl);
    if (!path || !(anim = anim_new(path, 1, 0))) {
        anim_obj_destroy(obj);
        return (NULL);
    }
    anim_obj_add_anim(obj, anim, NULL);
    return ((obj_t *)obj);
}

void *defense_new(scene_t *scene, char *aspect, int lvl, sfVector2f pos)
{
    anim_obj_t *st_defense = NULL;
    defense_data_t *extra = NULL;

    FAIL_IF(!aspect || !(st_defense = malloc(sizeof(anim_obj_t))), NULL);
    defense_ctor(st_defense, aspect, lvl);
    extra = st_defense->extra;
    VFUNC(extra->base, set_origin, VECT2F(96, 96));
    VFUNC(st_defense, set_origin, VECT2F(96, 96));
    VFUNC(extra->base, set_position, pos);
    VFUNC(st_defense, set_position, pos);
    scene_add_obj(scene, extra->base, NULL);
    return ((void *)st_defense);
}

void defense_ctor(anim_obj_t *defense, char *aspect, int lvl)
{
    defense_data_t *extra = malloc(sizeof(defense_data_t));
    char *path = NULL;
    anim_t *anim = NULL;

    FAIL_IF_VOID(!defense || !aspect || lvl < 0 || lvl > 3);
    anim_obj_ctor(defense);
    defense->dtor = defense_dtor;
    defense->extra = extra;
    defense->group = GR_DEFENSE;
    extra->level = lvl;
    extra->dps = 100;
    extra->range = 400;
    extra->target = NULL;
    extra->firerate = 1000;
    extra->timer = sfClock_create();
    extra->base = base_create(lvl);
    path = my_format("assets/img/mob/%s_%d.png", aspect, lvl);
    anim = anim_new(path, 1, 0);
    anim_obj_add_anim(defense, anim, NULL);
}

void defense_dtor(void *defense)
{
    anim_obj_t *st_defense = (anim_obj_t *)defense;
    defense_data_t *extra = (defense_data_t *)st_defense->extra;

    FAIL_IF_VOID(!st_defense);
    anim_obj_dtor(defense);
    sfClock_destroy(extra->timer);
    free(extra);
}

void defense_destroy(void *defense)
{
    FAIL_IF_VOID(!defense);
    defense_dtor(defense);
    free(defense);
}