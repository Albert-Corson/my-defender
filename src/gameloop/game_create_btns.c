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