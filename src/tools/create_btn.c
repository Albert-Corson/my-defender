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