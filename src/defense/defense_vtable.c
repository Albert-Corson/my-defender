/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** defense_obj_vtable
*/

#include "defender.h"

void defense_obj_vtable_ctor_met(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = defense_obj_render;
}

void defense_obj_vtable_ctor_set(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->set_fill_color = NULL;
    st_obj_vtable->set_origin = defense_obj_set_origin;
    st_obj_vtable->set_outline_color = NULL;
    st_obj_vtable->set_outline_thickness = NULL;
    st_obj_vtable->set_position = defense_obj_set_pos;
    st_obj_vtable->set_rotation = defense_obj_set_rotation;
    st_obj_vtable->set_scale = defense_obj_set_scale;
    st_obj_vtable->set_size = defense_obj_set_size;
    st_obj_vtable->set_radius = NULL;
    st_obj_vtable->set_texture = NULL;
}

void defense_obj_vtable_ctor_get(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->get_fill_color = NULL;
    st_obj_vtable->get_origin = defense_obj_get_origin;
    st_obj_vtable->get_outline_color = NULL;
    st_obj_vtable->get_outline_thickness = NULL;
    st_obj_vtable->get_position = defense_obj_get_pos;
    st_obj_vtable->get_rotation = defense_obj_get_rotation;
    st_obj_vtable->get_scale = defense_obj_get_scale;
    st_obj_vtable->get_size = NULL;
    st_obj_vtable->get_radius = NULL;
    st_obj_vtable->get_texture = NULL;
    st_obj_vtable->get_box = defense_obj_get_box;
}

void *defense_obj_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    defense_obj_vtable_ctor_met(st_obj_vtable);
    defense_obj_vtable_ctor_set(st_obj_vtable);
    defense_obj_vtable_ctor_get(st_obj_vtable);
    return ((void *)st_obj_vtable);
}