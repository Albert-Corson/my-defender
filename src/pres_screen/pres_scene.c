/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** presentation
*/

#include "defender.h"

static void ennemy_circle_dtor(void *obj)
{
    free(((obj_t *)obj)->extra);
    circle_dtor(obj);
}

void create_defense(scene_t *pres)
{
    anim_obj_t *defense = defense_new(pres, "rocket", 3, VECT2F(800, 290));
    shape_obj_t *ennemy = circle_new(10, 15, sfTransparent);

    ennemy->group = 2;
    ennemy->extra = ennemy_data_new(100, 3);
    ennemy->dtor = ennemy_circle_dtor;
    ((defense_data_t *)defense->extra)->dps = 1;
    ((defense_data_t *)defense->extra)->range = 700;
    scene_add_obj(pres, defense, "defense");
    scene_add_obj(pres, ennemy, "ennemy");
    scene_add_evt(pres, evt_new(defense_update_evt, context), NULL);
    scene_add_evt(pres, evt_new(ennemy_move_evt, inputs), NULL);
}

static void create_tower_icon(scene_t *pres)
{
    anim_t *tower = anim_new("assets/img/icon.png", 1, 0);
    anim_obj_t *icon = anim_obj_new();

    anim_obj_add_anim(icon, tower, "tower");
    anim_obj_set_position(icon, (sfVector2f){672, 450});
    scene_add_obj(pres, icon, "tower");
}

void pres_scene_create(hub_t *hub)
{
    scene_t *pres = scene_new();
    text_obj_t *press_text = text_obj_new("Press a key to start", sfRed, 30);
    text_obj_t *game_name = text_obj_new("TOWER DEFENSE", sfWhite, 100);

    pres->clear = sfYellow;
    scene_set_sound_buffer(hub, pres, "mouse_click");
    create_defense(pres);
    create_tower_icon(pres);
    text_obj_set_font(game_name, "assets/font/blocks.ttf");
    VFUNC(game_name, set_position, (sfVector2f){335, 50});
    VFUNC(press_text, set_position, (sfVector2f){600, 775});
    scene_add_obj(pres, press_text, "press_a_key");
    scene_add_obj(pres, game_name, "game_name");
    scene_add_evt(pres, evt_new(pres_show_menu, inputs), "show_menu");
    scene_add_evt(pres, evt_new(pres_quit_game, inputs), "quit_game");
    scene_add_evt(pres, evt_new(pres_animate_text, context), "txt_anim");
    scene_add_evt(pres, evt_new(mini_game_txt, context), "mini_game");
    hub_add_scene(hub, pres, "pres_scene");
}