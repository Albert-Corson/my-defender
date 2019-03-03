/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** controls
*/

#include "defender.h"

void controls_show_menu(hub_t *hub, sfEvent evt);

void controls_scene_create(hub_t *hub)
{
    scene_t *controls = scene_new();

    scene_add_evt(controls, evt_new(controls_show_menu, inputs), "show_menu");
    hub_add_scene(hub, controls, "controls_scene");
}