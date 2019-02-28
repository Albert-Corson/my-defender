/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** controls
*/

#include "defender.h"

// EVENTS FUNCTIONS
void options_show_menu(hub_t *hub, sfEvent evt);
void change_volume_slider(hub_t *hub, void *obj);

void create_volume_slider(scene_t *options)
{
    text_obj_t *volume = text_obj_new("VOLUME", sfRed, 50);
    shape_obj_t *back_sldr = rect_new(VECT2U(800, 80), sfBlack);
    shape_obj_t *slider = rect_new(VECT2U(800, 80), sfWhite);

    VFUNC(back_sldr, set_position, VECT2F(600, 250));
    VFUNC(slider, set_position, VECT2F(600, 250));
    VFUNC(volume, set_position, VECT2F(600, 190));
    back_sldr->on_active = change_volume_slider;
    scene_add_obj(options, volume, "volume_txt");
    scene_add_obj(options, back_sldr, "volume_sldr_bg");
    scene_add_obj(options, slider, "volume_sldr");
}

void options_scene_create(hub_t *hub)
{
    scene_t *options = scene_new();

    create_volume_slider(options);
    scene_add_evt(options, evt_new(options_show_menu, inputs), "show_menu");
    hub_add_scene(hub, options, "options_scene");
}