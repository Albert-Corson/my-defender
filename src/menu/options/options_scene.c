/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** controls
*/

#include "defender.h"

void create_volume_slider(scene_t *options)
{
    text_obj_t *text = text_obj_new("GENERAL VOLUME", sfRed, 50);
    shape_obj_t *back_sldr = rect_new(VECT2U(810, 90), sfBlack);
    shape_obj_t *slider = NULL;

    slider = rect_new(VECT2U(800, 80), sfWhite);
    VFUNC(back_sldr, set_position, VECT2F(395, 295));
    VFUNC(slider, set_position, VECT2F(400, 300));
    VFUNC(text, set_position, VECT2F(400, 240));
    back_sldr->on_active = change_volume_slider;
    scene_add_obj(options, text, "general_txt");
    scene_add_obj(options, back_sldr, "general_sldr_bg");
    scene_add_obj(options, slider, "general_sldr");
}

static void create_sfx_slider(scene_t *options)
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
static void create_music_slider(scene_t *options)
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
    text_obj_t *title = text_obj_new("OPTIONS", sfBlack, 70);
    input_obj_t *back = NULL;

    options->clear = sfYellow;
    scene_set_sound_buffer(hub, options, "mouse_click");
    back = create_btn(RECT(100, 840, 160, 80), sfBlack, 25, "BACK");
    back->on_active = back_btn_action;
    obj_set_sound_buffer(hub, back, "mouse_hover");
    rect_set_outline_thickness(back->background, -5);
    create_volume_slider(options);
    create_sfx_slider(options);
    create_music_slider(options);
    text_obj_set_font(title, "assets/font/blocks.ttf");
    VFUNC(title, set_position, VECT2F(120, 90));
    scene_add_obj(options, title, "title");
    scene_add_obj(options, back, "back_btn");
    scene_add_evt(options, evt_new(mouse_evt_updater_evt, inputs), NULL);
    scene_add_evt(options, evt_new(options_show_menu, inputs), "show_menu");
    hub_add_scene(hub, options, "options_scene");
}