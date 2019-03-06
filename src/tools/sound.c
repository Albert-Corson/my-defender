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
        scene_global_sound_apply(tmp, func);
        tmp = tmp->next;
    }
}