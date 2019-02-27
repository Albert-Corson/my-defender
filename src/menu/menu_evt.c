/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** menu_evt
*/

#include "defender.h"

void quit_game(hub_t *hub, sfEvent evt)
{
    input_obj_t *btn = list_fetch(((scene_t *)hub->scenes)->objs, "quit_btn");

    evt = evt;
    if (btn && btn->mouse_evt->active)
        sfRenderWindow_close(hub->window);
}

void place_arrow(hub_t *hub, sfEvent evt)
{
    scene_t *scene = list_fetch(hub->scenes, "menu");
    anim_obj_t *arrow = list_fetch(scene->objs, "arrow");
    obj_t *next = ((obj_t *)scene->objs)->next;
    sfVector2f a_pos = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    evt = evt;
    while (next != scene->objs) {
        if (next->type == input && ((input_obj_t *)next)->mouse_evt->hover) {
            box = input_obj_get_box(next);
            a_pos = (sfVector2f){box.left - VGET(arrow, get_size).x, box.top};
            VFUNC(arrow, set_position, (sfVector2f){a_pos.x - 20, a_pos.y});
            return;
        }
        next = next->next;
    }
    if (next->type != input || !((input_obj_t *)next)->mouse_evt->hover)
        return;
    box = input_obj_get_box(next);
    a_pos = (sfVector2f){box.left - VGET(arrow, get_size).x - 20, box.top};
    VFUNC(arrow, set_position, a_pos);
}