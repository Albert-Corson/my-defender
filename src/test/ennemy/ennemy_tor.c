/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** ennemy_tor
*/

#include "defender.h"

void ennemy_ctor(anim_obj_t *ennemy, char *aspect);

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
    ennemy->group = 2;
    path = my_format("assets/img/%s.png", aspect);
    anim = anim_new(path, 1, 0);
    anim_obj_add_anim(ennemy, anim, NULL);
}