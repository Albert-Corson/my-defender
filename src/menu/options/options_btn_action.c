/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** options_btn_action
*/

#include "defender.h"

void change_volume_slider(hub_t *hub, void *obj)
{
    obj_t *slider;
    sfVector2i mouse;
    sfVector2f rect;

    FAIL_IF_VOID(!obj || !hub || !((obj_t *)obj)->mouse_evt->active);
    slider = list_fetch(((scene_t *)hub->scenes)->objs, "general_sldr");
    mouse = sfMouse_getPositionRenderWindow(hub->window);
    rect = VGET(obj, get_position);
    rect.x = mouse.x - rect.x;
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x > 800)
        rect.x = 800;
    rect_set_size(slider, VECT2U(rect.x, VGET(slider, get_size).y));
    sfListener_setGlobalVolume((rect.x / 800) * 100);
}

void change_sfx_slider(hub_t *hub, void *obj)
{
    obj_t *slider;
    sfVector2i mouse;
    sfVector2f rect;

    FAIL_IF_VOID(!obj || !hub || !((obj_t *)obj)->mouse_evt->active);
    slider = list_fetch(((scene_t *)hub->scenes)->objs, "sfx_sldr");
    mouse = sfMouse_getPositionRenderWindow(hub->window);
    rect = VGET(obj, get_position);
    rect.x = mouse.x - rect.x;
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x > 600)
        rect.x = 600;
    rect_set_size(slider, VECT2U(rect.x, VGET(obj, get_size).y));
    sfx_set_volume(hub->scenes, (rect.x / 600) * 100);
}

void change_music_slider(hub_t *hub, void *obj)
{
    obj_t *slider;
    sfVector2i mouse;
    sfVector2f rect;

    FAIL_IF_VOID(!obj || !hub || !((obj_t *)obj)->mouse_evt->active);
    slider = list_fetch(((scene_t *)hub->scenes)->objs, "music_sldr");
    mouse = sfMouse_getPositionRenderWindow(hub->window);
    rect = VGET(obj, get_position);
    rect.x = mouse.x - rect.x;
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x > 600)
        rect.x = 600;
    rect_set_size(slider, VECT2U(rect.x, VGET(obj, get_size).y));
    scenes_set_volume(hub->scenes, (rect.x / 600) * 100);
}