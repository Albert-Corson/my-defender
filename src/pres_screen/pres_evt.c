/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** pres_evt
*/

#include "defender.h"

void mini_game_txt(hub_t *hub, sfEvent evt)
{
    shape_obj_t *me = list_fetch(((scene_t *)hub->scenes)->objs, "ennemy");
    text_obj_t *txt = list_fetch(((scene_t *)hub->scenes)->objs, "press_a_key");
    int hp = 0;

    evt = evt;
    FAIL_IF_VOID(!me || !txt);
    hp = ((ennemy_data_t *)me->extra)->hp;
    if (hp != 100) {
        ((ennemy_data_t *)me->extra)->hp = 100;
        ++me->nbr;
        text_obj_set_string(txt, my_format("HITS: %d", me->nbr));
        text_obj_set_position(txt, VECT2F(745, 775));
    }
}

void pres_animate_text(hub_t *hub, sfEvent evt)
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

void pres_quit_game(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
        sfRenderWindow_close(hub->window);
}

void pres_show_menu(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed || evt.type == sfEvtMouseButtonPressed) {
        hub->scenes = list_fetch((scene_t *)hub->scenes, "menu_scene");
        FAIL_IF_VOID(!hub->scenes || !((scene_t *)hub->scenes)->sound);
        sfSound_play(((scene_t *)hub->scenes)->sound);
    }
}