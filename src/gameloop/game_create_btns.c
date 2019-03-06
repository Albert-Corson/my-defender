/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game_create_btns
*/

#include "defender.h"

void create_img_btn(scene_t *game, char *path, sfVector2f pos, char *label)
{
    shape_obj_t *rect = rect_new(VECT2U(100, 100), RGBA(0, 0, 0, 150));
    anim_t *img = anim_new(path, 1, 0);
    anim_obj_t *sprite = anim_obj_new();
    input_obj_t *obj = NULL;

    anim_obj_add_anim(sprite, img, NULL);
    anim_obj_set_scale(sprite, VECT2F(0.7, 0.7));
    obj = input_obj_new(rect, sprite, pos);
    rect_set_outline_thickness(obj->background, -5);
    scene_add_obj(game, obj, label);
}

void game_create_buttons(scene_t *game)
{
    sfVector2f pos = VECT2F(950, 837.5);

    create_img_btn(game, "assets/img/mg_1.png", pos, "mg_btn");
    pos = VECT2F(1075, 837.5);
    create_img_btn(game, "assets/img/canon_1.png", pos, "canon_btn");
    pos = VECT2F(1200, 837.5);
    create_img_btn(game, "assets/img/rocket_1.png", pos, "rocket_btn");
    pos = VECT2F(1325, 837.5);
    create_img_btn(game, "assets/img/emp.png", pos, "emp_btn");
    pos = VECT2F(1450, 837.5);
    create_img_btn(game, "assets/img/mg_3.png",  pos, "upgrade_btn");
}