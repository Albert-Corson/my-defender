/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** enemy_evts
*/

#include "defender.h"

void enemy_follow_mouse(hub_t *hub, sfEvent evt)
{
    sfVector2f mouse = {0, 0};
    obj_t *enemy = list_fetch(((scene_t *)hub->scenes)->objs, "enemy");

    if (evt.type == sfEvtMouseMoved) {
        mouse.x = evt.mouseMove.x;
        mouse.y = evt.mouseMove.y;
        VFUNC(enemy, set_position, mouse);
    }
}