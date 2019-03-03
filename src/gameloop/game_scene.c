/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** game_scene
*/

#include "defender.h"

void game_show_menu(hub_t *hub, sfEvent evt);

void game_create_buttons(scene_t *game)
{
    game = game;
}

void game_scene_create(hub_t *hub)
{
    scene_t *game = scene_new();
    sfColor color = sfRed;
    color.a = 100;
    // shape_obj_t *rect = rect_new(VECT2U(1600, 100), RGBA(0, 0, 0, 150));
    shape_obj_t *rect = rect_new(VECT2U(1600, 125), color);

    VFUNC(rect, set_position, VECT2F(0, 775));
    game_create_buttons(game);
    scene_add_obj(game, rect, "rect");
    // scene_add_evt(game, evt_new(game_pause, inputs), "pause");
    scene_add_evt(game, evt_new(game_show_menu, inputs), "pause");
    hub_add_scene(hub, game, "game_scene");
}