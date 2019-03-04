/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** controls
*/

#include "defender.h"

void pause_create_btn(scene_t *pause)
{
    input_obj_t *quit = NULL;
    input_obj_t *resume = NULL;
    input_obj_t *menu = NULL;

    resume = create_btn(RECT(800, 475, 800, 100), sfBlack, 50, "RESUME");
    menu = create_btn(RECT(800, 600, 800, 100), sfBlack, 50, "MENU");
    quit = create_btn(RECT(800, 725, 800, 100), sfBlack, 50, "QUIT");
    resume->on_active = pause_resume_action;
    menu->on_active = pause_menu_action;
    quit->on_active = pause_quit_action;
    rect_set_outline_thickness(resume->background, -5);
    rect_set_outline_thickness(menu->background, -5);
    rect_set_outline_thickness(quit->background, -5);
    scene_add_obj(pause, resume, "resume_btn");
    scene_add_obj(pause, menu, "menu_btn");
    scene_add_obj(pause, quit, "quit_btn");

}

void pause_scene_create(hub_t *hub)
{
    scene_t *pause = scene_new();
    text_obj_t *title = text_obj_new("PAUSED", sfBlack, 70);

    text_obj_set_font(title, "assets/font/blocks.ttf");
    VFUNC(title, set_position, VECT2F(120, 90));
    create_volume_slider(pause);
    pause_create_btn(pause);
    scene_add_obj(pause, title, "title");
    scene_add_evt(pause, evt_new(outline_hovered_btn, inputs), "outline_btn");
    hub_add_scene(hub, pause, "pause_scene");
}