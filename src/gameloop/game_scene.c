/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** game_scene
*/

#include "defender.h"

void game_create_buttons(scene_t *game)
{
    sfVector2f pos = VECT2F(950, 837.5);

    create_img_btn(game, "assets/img/mg_1.png", pos, "mg_btn");
    pos = VECT2F(1075, 837.5);
    create_img_btn(game, "assets/img/canon_1.png", pos, "canon_btn");
    pos = VECT2F(1200, 837.5);
    create_img_btn(game, "assets/img/rocket_1.png", pos, "rocket_btn");
    pos = VECT2F(1325, 837.5);
    create_img_btn(game, "assets/img/mg_2.png", pos, "emp_btn");
    pos = VECT2F(1450, 837.5);
    create_img_btn(game, "assets/img/mg_3.png",  pos, "upgrade_btn");
}

void game_scene_create(hub_t *hub)
{
    scene_t *game = scene_new();
    shape_obj_t *rect = rect_new(VECT2U(1600, 125), RGBA(255, 255, 255, 200));

    VFUNC(rect, set_position, VECT2F(0, 775));
    scene_add_obj(game, rect, "hud_rect");
    rect_set_outline_thickness(rect, 5);
    rect_set_outline_color(rect, sfRed);
    game_create_buttons(game);
    scene_add_evt(game, evt_new(outline_focused_btn, inputs), "focused_btn");
    scene_add_evt(game, evt_new(game_pause, inputs), "pause");
    hub_add_scene(hub, game, "game_scene");
}