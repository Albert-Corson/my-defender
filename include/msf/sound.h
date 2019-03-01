/*
** EPITECH PROJECT, 2019
** msf
** File description:
** sound.h
*/

#include "msf.h"

struct msf_sound_buffer_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    sfSoundBuffer *buffer;
};

void *sound_buffer_new(char *path);
void sound_buffer_ctor(void *sound_buffer, char *path);
void sound_buffer_dtor(void *sound_buffer);
void sound_buffer_destroy(void *sound_buffer);

void obj_set_sound_buffer(void *obj, sfSoundBuffer *buffer);
void obj_set_sound_loop(void *obj, sfBool loop);