/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** how_to_scene
*/

#include "defender.h"

void how_to_scene_create(hub_t *hub)
{
    scene_t *how_to = scene_new();
    text_obj_t *title = text_obj_new("HOW TO PLAY", sfBlack, 70);
    input_obj_t *back = NULL;

    how_to->clear = sfYellow;
    scene_set_sound_buffer(hub, how_to, "mouse_click");
    back = create_btn(RECT(100, 840, 160, 80), sfBlack, 25, "BACK");
    back->on_active = back_btn_action;
    obj_set_sound_buffer(hub, back, "mouse_hover");
    rect_set_outline_thickness(back->background, -5);
    text_obj_set_font(title, "assets/font/blocks.ttf");
    VFUNC(title, set_position, VECT2F(550, 40));
    how_to_create_txt(how_to);
    scene_add_obj(how_to, title, "title");
    scene_add_obj(how_to, back, "back_btn");
    scene_add_evt(how_to, evt_new(mouse_evt_updater_evt, inputs), NULL);
    scene_add_evt(how_to, evt_new(options_show_menu, inputs), "show_menu");
    hub_add_scene(hub, how_to, "how_to_scene");
}