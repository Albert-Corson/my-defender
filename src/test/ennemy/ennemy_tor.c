/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** ennemy_tor
*/

#include "defender.h"

void ennemy_ctor(anim_obj_t *ennemy, char *aspect);

void ennemy_dtor(void *ennemy);

void *ennemy_new(char *aspect, sfVector2f pos)
{
    anim_obj_t *st_ennemy = NULL;

    FAIL_IF(!aspect || !(st_ennemy = malloc(sizeof(anim_obj_t))), NULL);
    ennemy_ctor(st_ennemy, aspect);
    VFUNC(st_ennemy, set_position, pos);
    return ((void *)st_ennemy);
}

void ennemy_ctor(anim_obj_t *ennemy, char *aspect)
{
    char *path = NULL;
    anim_t *anim = NULL;

    FAIL_IF_VOID(!ennemy || !aspect);
    anim_obj_ctor(ennemy);
    ennemy->dtor = ennemy_dtor;
    ennemy->group = 2;
    ennemy->extra = ennemy_data_new(400, 3);
    path = my_format("assets/img/%s.png", aspect);
    anim = anim_new(path, 1, 0);
    anim_obj_add_anim(ennemy, anim, NULL);
}

void *ennemy_data_new(float max_hp, float speed)
{
    ennemy_data_t *extra = malloc(sizeof(ennemy_data_t));

    extra->aerial = sfFalse;
    extra->ground = sfTrue;
    extra->hp = max_hp;
    extra->max_hp = max_hp;
    extra->speed = speed;
    return (extra);
}

void ennemy_dtor(void *ennemy)
{
    anim_obj_t *st_ennemy = (anim_obj_t *)ennemy;

    FAIL_IF_VOID(!st_ennemy || !st_ennemy->extra);
    free(st_ennemy->extra);
    anim_obj_dtor(ennemy);
}