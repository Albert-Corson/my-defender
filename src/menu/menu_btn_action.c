/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** btn_action
*/

#include "defender.h"

void menu_quit_game(hub_t *hub, void *btn)
{
    input_obj_t *st_btn = btn;

    if (st_btn && st_btn->mouse_evt->active)
        sfRenderWindow_close(hub->window);
}

void menu_show_options(hub_t *hub, void *obj)
{
    obj_t *st_obj = obj;
    shape_obj_t *slider = NULL;

    if (st_obj && st_obj->mouse_evt->active) {
        st_obj->mouse_evt->active = sfFalse;
        hub->scenes = list_fetch(hub->scenes, "options_scene");
        slider = list_fetch(((scene_t *)hub->scenes)->objs, "general_sldr");
        VFUNC(slider, set_size, VECT2U(8 * sfListener_getGlobalVolume(), 80));
    }
}

void menu_show_game(hub_t *hub, void *obj)
{
    obj_t *st_obj = obj;

    if (st_obj && st_obj->mouse_evt->active) {
        st_obj->mouse_evt->active = sfFalse;
        hub->scenes = list_fetch(hub->scenes, "game_scene");
    }
}