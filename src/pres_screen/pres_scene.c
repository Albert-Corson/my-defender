/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** presentation
*/

#include "defender.h"

// EVENTS FUNCTIONS
void pres_animate_text(hub_t *hub, sfEvent evt);
void pres_show_menu(hub_t *hub, sfEvent evt);
void pres_quit_game(hub_t *hub, sfEvent evt);

void pres_scene_create(hub_t *hub)
{
    scene_t *pres = scene_new();
    anim_t *tower = anim_new("assets/img/icon.png", 1, 0);
    anim_obj_t *icon = anim_obj_new();
    text_obj_t *press_text = text_obj_new("Press a key to start", sfRed, 30);
    text_obj_t *game_name = text_obj_new("TOWER DEFENSE", sfWhite, 100);

    anim_obj_add_anim(icon, tower, "tower");
    anim_obj_set_position(icon, (sfVector2f){672, 322});
    text_obj_set_font(game_name, "assets/font/blocks.ttf");
    VFUNC(game_name, set_position, (sfVector2f){335, 100});
    VFUNC(press_text, set_position, (sfVector2f){600, 650});
    scene_add_obj(pres, press_text, "press_a_key");
    scene_add_obj(pres, icon, "tower");
    scene_add_obj(pres, game_name, "game_name");
    scene_add_evt(pres, evt_new(pres_show_menu, inputs), "show_menu");
    scene_add_evt(pres, evt_new(pres_quit_game, inputs), "quit_game");
    scene_add_evt(pres, evt_new(pres_animate_text, context), "txt_anim");
    hub_add_scene(hub, pres, "pres_scene");
}