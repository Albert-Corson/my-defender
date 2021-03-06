/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** sound_obj_vtable
*/

#include "msf/msf.h"

void *sound_obj_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    sound_obj_vtable_ctor_met(st_obj_vtable);
    sound_obj_vtable_ctor_set(st_obj_vtable);
    sound_obj_vtable_ctor_get(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void sound_obj_vtable_ctor_met(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = sound_obj_render;
}

void sound_obj_vtable_ctor_set(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->set_fill_color = NULL;
    st_obj_vtable->set_origin = NULL;
    st_obj_vtable->set_outline_color = NULL;
    st_obj_vtable->set_outline_thickness = NULL;
    st_obj_vtable->set_position = NULL;
    st_obj_vtable->set_rotation = NULL;
    st_obj_vtable->set_scale = NULL;
    st_obj_vtable->set_size = NULL;
    st_obj_vtable->set_radius = NULL;
    st_obj_vtable->set_texture = NULL;
}

void sound_obj_vtable_ctor_get(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->get_fill_color = NULL;
    st_obj_vtable->get_origin = NULL;
    st_obj_vtable->get_outline_color = NULL;
    st_obj_vtable->get_outline_thickness = NULL;
    st_obj_vtable->get_position = NULL;
    st_obj_vtable->get_rotation = NULL;
    st_obj_vtable->get_scale = NULL;
    st_obj_vtable->get_size = NULL;
    st_obj_vtable->get_radius = NULL;
    st_obj_vtable->get_texture = NULL;
    st_obj_vtable->get_box = NULL;
}

void sound_obj_vtable_destroy(void *obj_vtable)
{
    free(obj_vtable);
}