/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game_evt
*/

#include "defender.h"

void game_show_menu(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtKeyReleased && evt.key.code == sfKeyEscape)
        hub->scenes = list_fetch(hub->scenes, "menu_scene");
}