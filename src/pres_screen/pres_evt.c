/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** pres_evt
*/

#include "defender.h"
#include <SFML/Window/Keyboard.h>

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
    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyEscape)
        sfRenderWindow_close(hub->window);
}

void pres_show_menu(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyReleased || evt.type == sfEvtMouseButtonReleased) {
        hub->scenes = list_fetch((scene_t *)hub->scenes, "menu_scene");
        FAIL_IF_VOID(!hub->scenes || !((scene_t *)hub->scenes)->sound);
        sfSound_play(((scene_t *)hub->scenes)->sound);
    }
}