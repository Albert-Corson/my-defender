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

    FAIL_IF_VOID(!obj);
    if (st_input->mouse_evt->active) {
        st_input->mouse_evt->active = sfFalse;
        st_input->mouse_evt->hover = sfFalse;
        st_input->mouse_evt->focus = sfFalse;
        hub->scenes = list_fetch(hub->scenes, "game_scene");
    }
}

void pause_quit_action(hub_t *hub, void *obj)
{
    input_obj_t *st_input = obj;

    FAIL_IF_VOID(!obj);
    if (st_input->mouse_evt->active)
        sfRenderWindow_close(hub->window);
}

void pause_menu_action(hub_t *hub, void *obj)
{
    input_obj_t *st_input = obj;

    FAIL_IF_VOID(!obj);
    if (st_input->mouse_evt->active) {
        st_input->mouse_evt->active = sfFalse;
        st_input->mouse_evt->hover = sfFalse;
        st_input->mouse_evt->focus = sfFalse;
        hub->scenes = list_fetch(hub->scenes, "menu_scene");
    }
}