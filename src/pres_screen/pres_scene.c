/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "defender.h"

// EVENTS FUNCTIONS
void animate_text(hub_t *hub, sfEvent evt);
void leave_pres(hub_t *hub, sfEvent evt);

void pres_scene_create(hub_t *hub)
{
    scene_t *pres_screen = scene_new();
    anim_t *tower = anim_new("assets/img/icon.png", 1, 0);
    anim_obj_t *icon = anim_obj_new();
    text_obj_t *press_text = text_obj_new("Press a key to start", sfRed, 30);
    text_obj_t *game_name = text_obj_new("TOWER DEFENSE", sfWhite, 100);

    anim_obj_add_anim(icon, tower, "tower");
    anim_obj_set_position(icon, (sfVector2f){672, 322});
    text_obj_set_font(game_name, "assets/font/blocks.ttf");
    VFUNC(game_name, set_position, (sfVector2f){335, 100});
    VFUNC(press_text, set_position, (sfVector2f){600, 650});
    scene_add_obj(pres_screen, press_text, "press_a_key");
    scene_add_obj(pres_screen, icon, "tower");
    scene_add_obj(pres_screen, game_name, "game_name");
    scene_add_evt(pres_screen, evt_new(leave_pres, inputs), "leave_scene");
    scene_add_evt(pres_screen, evt_new(animate_text, context), "transparency");
    hub_add_scene(hub, pres_screen, "pres_screen");
}