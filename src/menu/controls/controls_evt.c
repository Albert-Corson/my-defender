/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** controls_evt
*/

#include "defender.h"

void controls_show_menu(hub_t *hub, sfEvent evt)
{
    // if (evt.type == sfEvtKeyReleased && sfKeyboard_isKeyPressed(sfKeyEscape))
    if (evt.type == sfEvtKeyReleased)
        hub->scenes = list_fetch(hub->scenes, "menu_scene");
}