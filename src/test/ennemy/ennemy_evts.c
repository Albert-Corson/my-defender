/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** ennemy_evts
*/

#include "defender.h"

void ennemy_move_evt(hub_t *hub, sfEvent evt)
{
    sfVector2f mouse = {0, 0};
    obj_t *ennemy = list_fetch(((scene_t *)hub->scenes)->objs, "ennemy");

    if (evt.type == sfEvtMouseMoved) {
        mouse.x = evt.mouseMove.x;
        mouse.y = evt.mouseMove.y;
        VFUNC(ennemy, set_position, mouse);
    }
}