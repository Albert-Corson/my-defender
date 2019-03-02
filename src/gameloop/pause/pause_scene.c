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
void change_sfx_slider(hub_t *hub, void *obj);
void change_music_slider(hub_t *hub, void *obj);

void create_volume_slider(scene_t *options)
{
    text_obj_t *text = text_obj_new("GENERAL VOLUME", sfRed, 50);
    shape_obj_t *back_sldr = rect_new(VECT2U(800, 80), sfBlack);
    shape_obj_t *slider = rect_new(VECT2U(800, 80), sfWhite);

    VFUNC(back_sldr, set_position, VECT2F(400, 300));
    VFUNC(slider, set_position, VECT2F(400, 300));
    VFUNC(text, set_position, VECT2F(400, 240));
    back_sldr->on_active = change_volume_slider;
    scene_add_obj(options, text, "general_txt");
    scene_add_obj(options, back_sldr, "general_sldr_bg");
    scene_add_obj(options, slider, "general_sldr");
}

void create_sfx_slider(scene_t *options)
{
    text_obj_t *text = text_obj_new("Effects volume", sfRed, 35);
    shape_obj_t *back_sldr = rect_new(VECT2U(600, 60), sfBlack);
    shape_obj_t *slider = rect_new(VECT2U(600, 60), sfWhite);

    VFUNC(back_sldr, set_position, VECT2F(400, 450));
    VFUNC(slider, set_position, VECT2F(400, 450));
    VFUNC(text, set_position, VECT2F(400, 400));
    back_sldr->on_active = change_sfx_slider;
    scene_add_obj(options, text, "sfx_txt");
    scene_add_obj(options, back_sldr, "sfx_sldr_bg");
    scene_add_obj(options, slider, "sfx_sldr");
}
void create_music_slider(scene_t *options)
{
    text_obj_t *text = text_obj_new("Music volume", sfRed, 35);
    shape_obj_t *back_sldr = rect_new(VECT2U(600, 60), sfBlack);
    shape_obj_t *slider = rect_new(VECT2U(600, 60), sfWhite);

    VFUNC(back_sldr, set_position, VECT2F(400, 580));
    VFUNC(slider, set_position, VECT2F(400, 580));
    VFUNC(text, set_position, VECT2F(400, 530));
    back_sldr->on_active = change_music_slider;
    scene_add_obj(options, text, "music_txt");
    scene_add_obj(options, back_sldr, "music_sldr_bg");
    scene_add_obj(options, slider, "music_sldr");
}

void options_scene_create(hub_t *hub)
{
    scene_t *options = scene_new();
    shape_obj_t *rect = rect_new(VECT2U(160, 80), sfBlack);
    text_obj_t *text = text_obj_new("BACK", sfWhite, 25);
    input_obj_t *back = input_obj_new(rect, text, VECT2F(100, 840));
    text_obj_t *name = text_obj_new("OPTIONS", sfBlack, 70);

    text_obj_set_font(name, "assets/font/blocks.ttf");
    VFUNC(name, set_position, VECT2F(120, 90));
    scene_add_obj(options, name, "name");
    rect_set_outline_thickness(rect, -5);
    create_volume_slider(options);
    create_sfx_slider(options);
    create_music_slider(options);
    scene_add_obj(options, back, "back_btn");
    scene_add_evt(options, evt_new(options_show_menu, inputs), "show_menu");
    hub_add_scene(hub, options, "options_scene");
}