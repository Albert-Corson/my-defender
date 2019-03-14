/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** options_btn_action
*/

#include "defender.h"

void pause_resume_action(hub_t *hub, void *obj)
{
    input_obj_t *st_input = obj;
    scene_t *game = list_fetch(hub->scenes, "game_scene");
    sfBool hover = st_input->mouse_evt->hover;
    sfBool focus = st_input->mouse_evt->focus;
    sfBool active = st_input->mouse_evt->active;

    FAIL_IF_VOID(!obj || !game);
    if (focus && !active && hover) {
        rect_set_outline_color(st_input->background, sfBlack);
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = game;
    }
    if (active && hover)
        rect_set_fill_color(st_input->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_input->background, sfBlack);
    if (focus && !active)
        st_input->mouse_evt->focus = sfFalse;
}

void pause_quit_action(hub_t *hub, void *obj)
{
    input_obj_t *st_input = obj;
    sfBool hover = st_input->mouse_evt->hover;
    sfBool focus = st_input->mouse_evt->focus;
    sfBool active = st_input->mouse_evt->active;

    FAIL_IF_VOID(!obj);
    if (focus && !active && hover) {
        scene_sound_apply(hub->scenes, sfSound_play);
        sfRenderWindow_close(hub->window);
    }
    if (active && hover)
        rect_set_fill_color(st_input->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_input->background, sfBlack);
    if (focus && !active)
        st_input->mouse_evt->focus = sfFalse;
}

void pause_menu_action(hub_t *hub, void *obj)
{
    input_obj_t *st_input = obj;
    scene_t *menu = list_fetch(hub->scenes, "menu_scene");
    sfBool hover = st_input->mouse_evt->hover;
    sfBool focus = st_input->mouse_evt->focus;
    sfBool active = st_input->mouse_evt->active;

    FAIL_IF_VOID(!obj || !menu);
    if (focus && !active && hover) {
        rect_set_outline_color(st_input->background, sfBlack);
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = menu;
    }
    if (active && hover)
        rect_set_fill_color(st_input->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_input->background, sfBlack);
    if (focus && !active)
        st_input->mouse_evt->focus = sfFalse;
}