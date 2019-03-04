/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "defender.h"

void menu_create_buttons(scene_t *menu)
{
    input_obj_t *play = NULL;
    input_obj_t *optn = NULL;
    input_obj_t *quit = NULL;

    play = create_btn(RECT(1075, 250, 500, 100), sfBlack, 50, "Play");
    optn = create_btn(RECT(1075, 425, 500, 100), sfBlack, 50, "Options");
    quit = create_btn(RECT(1075, 600, 500, 100), sfBlack, 50, "Quit");
    quit->on_active = menu_quit_game;
    optn->on_active =  menu_show_options;
    play->on_active = menu_show_game;
    scene_add_obj(menu, play, "play_btn");
    scene_add_obj(menu, optn, "opt_btn");
    scene_add_obj(menu, quit, "quit_btn");
}

void menu_scene_create(hub_t *hub)
{
    scene_t *menu = scene_new();
    anim_t *tower_img = anim_new("assets/img/icon.png", 1, 0);
    anim_obj_t *tower = anim_obj_new();
    anim_t *arrow_img = anim_new("assets/img/arrow.png", 1, 0);
    anim_obj_t *arrow = anim_obj_new();
    sound_buffer_t *ahhh = sound_buffer_new("assets/ahhh.wav");

    hub_add_buffer(hub, ahhh, "background");
    scene_set_sound_buffer(hub, menu, "background");
    menu_create_buttons(menu);
    anim_obj_add_anim(arrow, arrow_img, "arrow");
    anim_obj_add_anim(tower, tower_img, "tower");
    anim_obj_set_position(tower, (sfVector2f){100, 170});
    anim_obj_set_position(arrow, (sfVector2f){-100, 0});
    anim_obj_set_scale(tower, (sfVector2f){2.2, 2.2});
    scene_add_obj(menu, tower, "tower");
    scene_add_obj(menu, arrow, "arrow");
    scene_add_evt(menu, evt_new(menu_place_arrow, inputs), "place_arrow");
    scene_add_evt(menu, evt_new(menu_show_pres, inputs), "show_pres");
    hub_add_scene(hub, menu, "menu_scene");
}