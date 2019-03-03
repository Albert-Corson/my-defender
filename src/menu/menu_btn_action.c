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
    scene_t *options_scene = NULL;

    if (st_obj && st_obj->mouse_evt->active) {
        st_obj->mouse_evt->active = sfFalse;
        options_scene = list_fetch(hub->scenes, "options_scene");
        FAIL_IF_VOID(!options_scene);
        hub->scenes = options_scene;
    }
}

void menu_show_controls(hub_t *hub, void *obj)
{
    obj_t *st_obj = obj;
    scene_t *controls_scene = NULL;

    if (st_obj && st_obj->mouse_evt->active) {
        controls_scene = list_fetch(hub->scenes, "controls_scene");
        FAIL_IF_VOID(!controls_scene);
        st_obj->mouse_evt->active = sfFalse;
        hub->scenes = controls_scene;
    }
}

void menu_show_game(hub_t *hub, void *obj)
{
    obj_t *st_obj = obj;
    scene_t *game_scene = NULL;

    if (st_obj && st_obj->mouse_evt->active) {
        game_scene = list_fetch(hub->scenes, "game_scene");
        FAIL_IF_VOID(!game_scene);
        st_obj->mouse_evt->active = sfFalse;
        hub->scenes = game_scene;
    }
}