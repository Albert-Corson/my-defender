/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "defender.h"

// EVENTS FUNCTIONS
void place_arrow(hub_t *hub, sfEvent evt);
void quit_game(hub_t *hub, sfEvent evt);

void menu_create_buttons(scene_t *menu)
{
    shape_obj_t *rect_play = rect_new((sfVector2u){380, 70}, sfWhite);
    shape_obj_t *rect_quit = rect_new((sfVector2u){380, 70}, sfWhite);
    shape_obj_t *rect_opt = rect_new((sfVector2u){380, 70}, sfWhite);
    shape_obj_t *rect_ctrl = rect_new((sfVector2u){380, 70}, sfWhite);
    text_obj_t *text_play = text_obj_new("Play", sfBlack, 50);
    text_obj_t *text_quit = text_obj_new("Quit", sfBlack, 50);
    text_obj_t *text_opt = text_obj_new("Options", sfBlack, 50);
    text_obj_t *text_ctrl = text_obj_new("Controls", sfBlack, 50);
    input_obj_t *play = NULL;
    input_obj_t *ctrl = NULL;
    input_obj_t *opt = NULL;
    input_obj_t *quit = NULL;

    play = input_obj_new(rect_play, text_play, (sfVector2f){1025, 250});
    ctrl = input_obj_new(rect_ctrl, text_ctrl, (sfVector2f){1025, 375});
    opt = input_obj_new (rect_opt, text_opt, (sfVector2f){1025, 500});
    quit = input_obj_new(rect_quit, text_quit, (sfVector2f){1025, 625});
    scene_add_obj(menu, play, "play_btn");
    scene_add_obj(menu, quit, "quit_btn");
    scene_add_obj(menu, opt, "opt_btn");
    scene_add_obj(menu, ctrl, "ctrl_btn");
}

void menu_scene_create(hub_t *hub)
{
    scene_t *menu = scene_new();
    anim_t *tower_img = anim_new("assets/img/icon.png", 1, 0);
    anim_obj_t *tower = anim_obj_new();
    anim_t *arrow_img = anim_new("assets/img/arrow.png", 1, 0);
    anim_obj_t *arrow = anim_obj_new();

    menu_create_buttons(menu);
    anim_obj_add_anim(arrow, arrow_img, "arrow");
    anim_obj_add_anim(tower, tower_img, "tower");
    anim_obj_set_position(tower, (sfVector2f){100, 170});
    anim_obj_set_position(arrow, (sfVector2f){-100, 0});
    anim_obj_set_scale(tower, (sfVector2f){2.2, 2.2});
    scene_add_obj(menu, tower, "tower");
    scene_add_obj(menu, arrow, "arrow");
    scene_add_evt(menu, evt_new(quit_game, inputs), "quit_game");
    scene_add_evt(menu, evt_new(place_arrow, inputs), "place_arrow");
    hub_add_scene(hub, menu, "menu");
}