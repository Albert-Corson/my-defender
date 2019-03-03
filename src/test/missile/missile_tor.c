/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** missile
*/

#include "defender.h"

void missile_ctor(void *missile, void *launcher, char *aspect);

void missile_set_data(void *missile, void *launcher);

void missile_dtor(void *missile);

void *missile_new(void *launcher, char *aspect)
{
    anim_obj_t *missile = malloc(sizeof(anim_obj_t));

    anim_obj_ctor(missile);
    missile->dtor = missile_dtor;
    missile_set_data(missile, launcher);
    missile_ctor(missile, launcher, aspect);
    return ((void *)missile);
}

void missile_ctor(void *missile, void *launcher, char *aspect)
{
    anim_obj_t *st_missile = (anim_obj_t *)missile;
    float speed = ((missile_data_t *)st_missile->extra)->speed;
    char *path = my_format("assets/img/%s.png", aspect);
    anim_t *anim = anim_new(path, 1, 0);
    sfVector2f pos = VGET(launcher, get_position);
    sfVector2u b_size = VGET(missile, get_size);
    sfFloatRect t_box = VGET(launcher, get_box);
    float rot = VGET(launcher, get_rotation);

    st_missile->group = 4;
    anim_obj_add_anim(st_missile, anim, NULL);
    pos.x = t_box.left - cos(RAD(rot)) * (t_box.width / 2 - b_size.x);
    pos.y = t_box.top - sin(RAD(rot)) * (t_box.height / 2 - b_size.y);
    VFUNC(st_missile, set_position, pos);
    VFUNC(st_missile, set_rotation, rot);
    obj_set_speed(st_missile, -cos(RAD(rot)) * speed, -sin(RAD(rot)) * speed);
}

void missile_set_data(void *missile, void *launcher)
{
    anim_obj_t *st_missile = (anim_obj_t *)missile;
    anim_obj_t *st_launcher = (anim_obj_t *)launcher;
    defense_data_t *launcher_extra = st_launcher->extra;
    missile_data_t *missile_extra = malloc(sizeof(missile_data_t));

    st_missile->extra = missile_extra;
    missile_extra->speed = 5;
    missile_extra->sender = launcher;
    missile_extra->target = launcher_extra->target;
}

void missile_dtor(void *missile)
{
    anim_obj_t *st_missile = (anim_obj_t *)missile;

    FAIL_IF_VOID(!st_missile || !st_missile->extra);
    free(st_missile->extra);
    anim_obj_dtor(missile);
}