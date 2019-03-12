/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_btn
*/

#include "defender.h"

input_obj_t *create_btn(sfFloatRect box, sfColor bg, int txt_size, char *txt)
{
    shape_obj_t *rect = rect_new(VECT2U(box.width, box.height), bg);
    text_obj_t *text = text_obj_new(txt, sfWhite, txt_size);
    input_obj_t *btn = input_obj_new(rect, text, VECT2F(box.left, box.top));

    return (btn);
}

input_obj_t *create_img_btn(char *path, sfVector2f pos)
{
    shape_obj_t *rect = rect_new(VECT2U(65, 65), RGBA(0, 0, 0, 150));
    anim_t *img = anim_new(path, 1, 0);
    anim_obj_t *sprite = anim_obj_new();
    input_obj_t *obj = NULL;

    anim_obj_add_anim(sprite, img, NULL);
    obj = input_obj_new(rect, sprite, pos);
    rect_set_outline_thickness(obj->background, -3);
    return (obj);
}