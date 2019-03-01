/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** scene_set
*/

#include "msf/msf.h"

void obj_set_sound_buffer(void *obj, sfSoundBuffer *buffer)
{
    obj_t *st_obj = obj;
    sfSound *sound = NULL;

    FAIL_IF_VOID(!st_obj || !buffer);
    sound = st_obj->sound;
    st_obj->sound = NULL;
    if (sound)
        sfSound_destroy(sound);
    st_obj->sound = sfSound_create();
    sfSound_setBuffer(st_obj->sound, buffer);
}

void obj_set_sound_loop(void *obj, sfBool loop)
{
    obj_t *st_obj = obj;

    FAIL_IF_VOID(!st_obj || st_obj->sound);
    sfSound_setLoop(st_obj->sound, loop);
}