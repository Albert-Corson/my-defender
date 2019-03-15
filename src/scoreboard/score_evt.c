/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** pres_evt
*/

#include "defender.h"

void score_show_menu(hub_t *hub, sfEvent evt)
{
    scene_t *next = list_fetch((scene_t *)hub->scenes, "menu_scene");

    FAIL_IF_VOID(!next);
    if (evt.type == sfEvtKeyPressed || evt.type == sfEvtMouseButtonPressed) {
        if (((scene_t *)hub->scenes)->sound)
            sfSound_play(((scene_t *)hub->scenes)->sound);
        hub->scenes = next;
        reset_game(hub);
        FAIL_IF_VOID(!hub->sound)
        sfSound_play(hub->sound);
    }
}