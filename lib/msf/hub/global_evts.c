/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** global_evts
*/

#include "msf/msf.h"

void window_close_evt(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(hub->window);
}

void mouse_evt_update_move(void *obj, sfEvent evt)
{
    obj_t *st_obj = (obj_t *)obj;
    sfVector2f mouse = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    mouse = VECT2F(evt.mouseMove.x, evt.mouseMove.y);
    box = VGET(obj, get_box);
    if (sfFloatRect_contains(&box, mouse.x, mouse.y)) {
        st_obj->mouse_evt->hover = sfTrue;
        st_obj->mouse_evt->x = mouse.x;
        st_obj->mouse_evt->y = mouse.y;
    } else {
        st_obj->mouse_evt->hover = sfFalse;
    }
}

void mouse_evt_update_button(void *obj, sfEvent evt)
{
    obj_t *st_obj = (obj_t *)obj;
    sfVector2f mouse = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    if (evt.type == sfEvtMouseButtonPressed) {
        mouse = VECT2F(evt.mouseButton.x, evt.mouseButton.y);
        box = VGET(obj, get_box);
        if (sfFloatRect_contains(&box, mouse.x, mouse.y)) {
            st_obj->mouse_evt->active = sfTrue;
            st_obj->mouse_evt->focus = sfTrue;
            st_obj->mouse_evt->x = mouse.x;
            st_obj->mouse_evt->y = mouse.y;
        } else {
            st_obj->mouse_evt->active = sfFalse;
            st_obj->mouse_evt->focus = sfFalse;
        }
    } else if (evt.type == sfEvtMouseButtonReleased) {
        st_obj->mouse_evt->active = sfFalse;
    }
}

void mouse_evt_updater(void *obj, sfEvent evt)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj);
    if (evt.type == sfEvtMouseMoved) {
        mouse_evt_update_move(obj, evt);
    }
    if (evt.type == 9 || evt.type == 10) {
        mouse_evt_update_button(obj, evt);
    }
}

void launch_on_active_func(hub_t *hub, void *obj)
{
    obj_t *st_obj = obj;

    if (st_obj->on_active) {
        if (st_obj->mouse_evt->active || st_obj->mouse_evt->hover)
            st_obj->on_active(hub, st_obj);
        else if (st_obj->mouse_evt->focus)
            st_obj->on_active(hub, st_obj);
    }
}

void mouse_evt_updater_evt(hub_t *hub, sfEvent evt)
{
    obj_t *begin = ((scene_t *)hub->scenes)->objs;
    obj_t *curr = NULL;

    FAIL_IF_VOID(evt.type != 11 && evt.type != 9 && evt.type != 10);
    FAIL_IF_VOID(!hub || !hub->scenes || !((scene_t *)hub->scenes)->objs);
    while (list_poll((void *)begin, (void **)&curr)) {
        mouse_evt_updater(curr, evt);
        launch_on_active_func(hub, curr);
    }
}