/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** get_focused_btn
*/

#include "defender.h"

input_obj_t *get_focused_btn(hub_t *hub)
{
    input_obj_t *obj = NULL;
    input_obj_t *next = NULL;

    FAIL_IF(!hub || !hub->scenes, NULL);
    obj = ((scene_t *)hub->scenes)->objs;
    while (list_poll(obj, (void **)&next)) {
        if (next->type == input && next->mouse_evt->focus)
            obj = NULL;
    }
    if (next && next->type == input && next->mouse_evt->focus)
        return (next);
    return (NULL);
}