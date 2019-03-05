/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** input_met
*/

#include "msf/msf.h"

void input_obj_render(void *input_obj, hub_t *hub)
{
    input_obj_t *st_input_obj = input_obj;

    FAIL_IF_VOID(!st_input_obj);
    VFUNC(st_input_obj->background, render, hub);
    VFUNC(st_input_obj->foreground, render, hub);
}

void input_obj_recenter(void *input_obj)
{
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;
    obj_t *bg = st_input_obj ? st_input_obj->background : NULL;
    obj_t *fg = st_input_obj ? st_input_obj->foreground : NULL;
    sfVector2u size;
    sfVector2f ori;
    sfVector2f scale;

    if (bg) {
        scale = VGET(bg, get_scale);
        size = VGET(bg, get_size);
        ori.x = size.x / 2 / scale.x;
        ori.y = size.y / 2 / scale.y;
        VFUNC(bg, set_origin, ori);
    }
    if (fg) {
        scale = VGET(fg, get_scale);
        size = VGET(fg, get_size);
        ori.x = size.x / 2 / scale.x;
        ori.y = size.y / ((fg->type == text) ? 1 : 2) / scale.y;
        VFUNC(fg, set_origin, ori);
    }
}