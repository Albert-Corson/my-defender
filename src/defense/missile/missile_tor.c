/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** missile
*/

#include "defender.h"

void *missile_new(void *launcher, char *aspect)
{
    anim_obj_t *missile = malloc(sizeof(anim_obj_t));

    anim_obj_ctor(missile);
    missile->dtor = missile_dtor;
    missile_set_data(missile, launcher);
    missile_ctor(missile, launcher, aspect);
    anim_obj_set_scale(missile, VGET(launcher, get_scale));
    return ((void *)missile);
}

void missile_ctor(void *missile, void *launcher, char *aspect)
{
    anim_obj_t *st_missile = (anim_obj_t *)missile;
    float speed = ((missile_data_t *)st_missile->extra)->speed;
    char *path = my_format("assets/img/mob/%s.png", aspect);
    anim_t *anim = anim_new(path, 1, 0);
    sfVector2f pos = VGET(launcher, get_position);
    sfVector2u b_size = VGET(missile, get_size);
    sfFloatRect t_box = VGET(launcher, get_box);
    float rot = VGET(launcher, get_rotation);

    st_missile->group = GR_MISSILE;
    anim_obj_add_anim(st_missile, anim, NULL);
    pos.x = t_box.left + t_box.width / 2 - cos(RAD(rot)) * t_box.width / 2.5; 
    pos.y = t_box.top + t_box.height / 2 - sin(RAD(rot)) * t_box.height / 2.5;
    VFUNC(st_missile, set_position, pos);
    VFUNC(st_missile, set_rotation, rot);
    obj_set_speed(st_missile, -cos(RAD(rot)) * speed, -sin(RAD(rot)) * speed);
    free(path);
}

void missile_set_data(void *missile, void *launcher)
{
    anim_obj_t *st_missile = (anim_obj_t *)missile;
    defense_obj_t *st_launcher = launcher;
    missile_data_t *missile_extra = malloc(sizeof(missile_data_t));

    st_missile->extra = missile_extra;
    missile_extra->speed = 550;
    missile_extra->sender = st_launcher;
    missile_extra->target = st_launcher->target;
}

void missile_dtor(void *missile)
{
    anim_obj_t *st_missile = (anim_obj_t *)missile;

    FAIL_IF_VOID(!st_missile || !st_missile->extra);
    free(st_missile->extra);
    anim_obj_dtor(missile);
}