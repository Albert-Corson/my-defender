/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** emeny_set
*/

#include "defender.h"

void enemy_set_size(void *obj, sfVector2u size)
{
    anim_obj_t *st_anim_obj = obj;
    enemy_data_t *extra = st_anim_obj->extra;
    sfVector2f actual_scale;
    sfVector2u actual_size;
    sfVector2f new_scale;

    FAIL_IF_VOID(!st_anim_obj);
    actual_scale = anim_obj_get_scale(obj);
    actual_size = anim_obj_get_size(obj);
    FAIL_IF_VOID(actual_size.x == 0 || actual_size.y == 0);
    new_scale.x = size.x * actual_scale.x / actual_size.x;
    new_scale.y = size.y * actual_scale.y / actual_size.y;
    st_anim_obj->physics->size.x = actual_size.x * new_scale.x;
    st_anim_obj->physics->size.y = actual_size.y * new_scale.y;
    anim_obj_set_scale(obj, new_scale);
    anim_obj_set_scale(obj, new_scale);
    size.y = size.x * 0.15;
    size.x = size.x - (size.x * 0.15);
    extra->lifebar_size = size.x;
    VFUNC(extra->lifebar, set_size, size);
}

void enemy_set_scale(void *obj, sfVector2f scale)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)obj;
    enemy_data_t *extra = st_anim_obj->extra;

    FAIL_IF_VOID(!st_anim_obj || extra);
    sfSprite_setScale(st_anim_obj->sprite, scale);
    VFUNC(extra->lifebar, set_scale, scale);
    extra->lifebar_size *= scale.x;
}

void enemy_set_position(void *obj, sfVector2f pos)
{
    anim_obj_t *anim = obj;
    enemy_data_t *extra = anim->extra;
    sfFloatRect box = VGET(anim, get_box);

    FAIL_IF_VOID(!anim || !extra || !extra->lifebar);
    anim_obj_set_position(anim, pos);
    pos.x = box.left + 3;
    pos.y = box.top - 10;
    rect_set_position(extra->lifebar, pos);
}