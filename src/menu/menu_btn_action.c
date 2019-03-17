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
    sfBool hover = st_btn->mouse_evt->hover;
    sfBool focus = st_btn->mouse_evt->focus;
    sfBool active = st_btn->mouse_evt->active;

    if (focus && !active && hover) {
        rect_set_fill_color(st_btn->background, sfBlack);
        scene_sound_apply(hub->scenes, sfSound_play);
        sfRenderWindow_close(hub->window);
    }
    if (active && hover)
        rect_set_fill_color(st_btn->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_btn->background, sfBlack);
    if (focus && !active)
        st_btn->mouse_evt->focus = sfFalse;
}

void menu_show_options(hub_t *hub, void *btn)
{
    scene_t *option = list_fetch(hub->scenes, "options_scene");
    shape_obj_t *slider = list_fetch(option->objs, "general_sldr");
    input_obj_t *st_btn = btn;
    sfBool hover = st_btn->mouse_evt->hover;
    sfBool focus = st_btn->mouse_evt->focus;
    sfBool active = st_btn->mouse_evt->active;

    if (focus && !active && hover) {
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = option ? option : hub->scenes;
        VFUNC(slider, set_size, VECT2U(8 * sfListener_getGlobalVolume(), 80));
    }
    if (active && hover)
        rect_set_fill_color(st_btn->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_btn->background, sfBlack);
    if (focus && !active)
        st_btn->mouse_evt->focus = sfFalse;
}

void menu_show_game(hub_t *hub, void *btn)
{
    scene_t *game = list_fetch(hub->scenes, "game_scene");
    input_obj_t *st_btn = btn;
    sfBool hover = st_btn->mouse_evt->hover;
    sfBool focus = st_btn->mouse_evt->focus;
    sfBool active = st_btn->mouse_evt->active;

    if (focus && !active && hover) {
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = game ? game : hub->scenes;
    }
    if (active && hover)
        rect_set_fill_color(st_btn->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_btn->background, sfBlack);
    if (focus && !active)
        st_btn->mouse_evt->focus = sfFalse;
}

void menu_show_how_to(hub_t *hub, void *btn)
{
    scene_t *game = list_fetch(hub->scenes, "how_to_scene");
    input_obj_t *st_btn = btn;
    sfBool hover = st_btn->mouse_evt->hover;
    sfBool focus = st_btn->mouse_evt->focus;
    sfBool active = st_btn->mouse_evt->active;

    if (focus && !active && hover) {
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = game ? game : hub->scenes;
    }
    if (active && hover)
        rect_set_fill_color(st_btn->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_btn->background, sfBlack);
    if (focus && !active)
        st_btn->mouse_evt->focus = sfFalse;
}