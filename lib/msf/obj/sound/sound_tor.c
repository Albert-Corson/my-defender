/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** sound_obj_tor
*/

#include "msf/msf.h"

void *sound_obj_new(hub_t *hub, char *buffer)
{
    sound_obj_t *st_sound = malloc(sizeof(sound_obj_t));

    FAIL_IF(!st_sound, NULL);
    sound_obj_ctor(st_sound, hub, buffer);
    return ((void *)st_sound);
}

void sound_obj_ctor(void *obj, hub_t *hub, char *buffer)
{
    sound_obj_t *st_sound = (sound_obj_t *)obj;

    FAIL_IF_VOID(!st_sound);
    obj_ctor(st_sound, sound, sfTrue);
    st_sound->vtable = sound_obj_vtable_new();
    st_sound->physics = NULL;
    st_sound->loop = sfFalse;
    st_sound->repeat_delay = 0;
    st_sound->elapsed = 0;
    st_sound->dtor = obj_dtor;
    obj_set_sound_buffer(hub, obj, buffer);
}

void sound_obj_destroy(void *shape_obj)
{
    obj_dtor(shape_obj);
    free(shape_obj);
}