/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** game_scene
*/

#include "defender.h"

void game_create_buttons(scene_t *game)
{

}

void game_scene_create(hub_t *hub)
{
    scene_t *game = scene_new();
    shape_obj_t *rect = rect_new(VECT2U(1600, 125), RGBA(0, 0, 0, 150));

    VFUNC(rect, set_position, VECT2F(0, 775));
    game_create_buttons(game);
    scene_add_obj(game, rect, "rect");
    scene_add_evt(game, evt_new(outline_focused_btn, inputs), "focused_btn");
    scene_add_evt(game, evt_new(game_pause, inputs), "pause");
    hub_add_scene(hub, game, "game_scene");
}