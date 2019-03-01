/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** scene_set
*/

#include "msf/msf.h"

void scene_set_cam_speed(void *scene, float sx, float sy)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene);
    st_scene->cam_speed.x = sx;
    st_scene->cam_speed.y = sy;
}

void scene_set_cam_pos(void *scene, float x, float y)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene);
    st_scene->cam_pos.x = x;
    st_scene->cam_pos.y = y;
}

void scene_set_sound_buffer(void *scene, void *buffer)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene || !buffer);
    if (st_scene->sound)
        sfSound_destroy(st_scene->sound);
    st_scene->sound = sfSound_create();
    sfSound_setBuffer(st_scene->sound, buffer);
}

void scenes_set_volume(void *scene, float volume)
{
    scene_t *st_scenes = scene;
    scene_t *next = st_scenes ? st_scenes->next : NULL;

    FAIL_IF_VOID(!st_scenes || !next || volume < 0.0 || volume > 100.0);
    while (next != st_scenes) {
        if (next->sound != NULL)
            sfSound_setVolume(next->sound, volume);
        next = next->next;
    }
    if (next->sound != NULL)
        sfSound_setVolume(next->sound, volume);
}