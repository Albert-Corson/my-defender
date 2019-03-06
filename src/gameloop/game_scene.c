/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** game_scene
*/

#include "defender.h"

void preview_defense_pos(hub_t *hub, sfEvent evt);

void game_scene_create(hub_t *hub)
{
    scene_t *game = scene_new();
    shape_obj_t *rect = rect_new(VECT2U(1600, 125), RGBA(255, 255, 255, 200));

    game->clear = sfYellow;
    scene_set_sound_buffer(hub, game, "mouse_click");
    VFUNC(rect, set_position, VECT2F(0, 775));
    scene_add_obj(game, rect, "hud_rect");
    rect_set_outline_thickness(rect, 5);
    rect_set_outline_color(rect, sfRed);
    game_create_buttons(game);
    scene_add_evt(game, evt_new(outline_focused_btn, inputs), "focused_btn");
    scene_add_evt(game, evt_new(game_pause, inputs), "pause");
    hub_add_scene(hub, game, "game_scene");
}