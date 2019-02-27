/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "defender.h"

static void animate_text(hub_t *hub, sfEvent evt)
{
    text_obj_t *txt = list_fetch(((scene_t *)hub->scenes)->objs, "press_a_key");
    sfColor color = sfText_getColor(txt->text);

    evt = evt;
    if (txt->nbr == 0)
        txt->nbr = 2;
    if (color.a + 2 >= 255)
        txt->nbr = -2;
    if (color.a - 2 <= 0)
        txt->nbr = 2;
    color.a += txt->nbr;
    text_obj_set_color(txt, color);
}

static void leave_scene(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyReleased || evt.type == sfEvtMouseButtonReleased)
        hub->scenes = ((scene_t *)hub->scenes)->next;
}

void pres_scene_create(hub_t *hub)
{
    scene_t *menu = scene_new();
    anim_t *tower = anim_new("assets/img/icon.png", 1, 0);
    anim_obj_t *icon = anim_obj_new();
    text_obj_t *press_text = text_obj_new("Press a key to start", sfRed, 30);
    text_obj_t *game_name = text_obj_new("TOWER DEFENSE", sfWhite, 100);

    anim_obj_add_anim(icon, tower, "tower");
    anim_obj_set_position(icon, (sfVector2f){672, 322});
    text_obj_set_font(game_name, "assets/font/blocks.ttf");
    VFUNC(game_name, set_position, (sfVector2f){335, 100});
    VFUNC(press_text, set_position, (sfVector2f){600, 650});
    scene_add_obj(menu, press_text, "press_a_key");
    scene_add_obj(menu, icon, "tower");
    scene_add_obj(menu, game_name, "game_name");
    scene_add_evt(menu, evt_new(leave_scene, inputs), "leave_scene");
    scene_add_evt(menu, evt_new(animate_text, context), "transparency");
    hub_add_scene(hub, menu, "menu");
}