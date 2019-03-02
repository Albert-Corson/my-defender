/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** pause_sound
*/

#include "defender.h"

void other_scenes_sound_apply(hub_t *hub, void (*func)(sfSound *))
{
    scene_t *tmp = ((scene_t *)(hub->scenes))->next;

    while (tmp != hub->scenes) {
        scene_sound_apply(tmp, func);
        tmp = tmp->next;
    }
}

void sfx_set_volume(scene_t *scene, float volume)
{
    scene_t *tmp = scene->next;

    FAIL_IF_VOID(!scene || volume > 100 || volume < 0);
    while (tmp != scene) {
        objs_set_volume(tmp->objs, volume);
        tmp = tmp->next;
    }
    objs_set_volume(tmp->objs, volume);
}