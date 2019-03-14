/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** load_sound
*/

#include "defender.h"

void load_sound_buffers(hub_t *hub)
{
    sound_buffer_t *buffer = sound_buffer_new("assets/audio/click.ogg");

    hub_add_buffer(hub, buffer, "mouse_click");
    buffer = sound_buffer_new("assets/audio/hover.ogg");
    hub_add_buffer(hub, buffer, "mouse_hover");
    buffer = sound_buffer_new("assets/audio/menu.ogg");
    hub_add_buffer(hub, buffer, "bg_music");
    buffer = sound_buffer_new("assets/audio/emp_explo.ogg");
    hub_add_buffer(hub, buffer, "emp_explo");
    buffer = sound_buffer_new("assets/audio/erease.ogg");
    hub_add_buffer(hub, buffer, "erease");
    buffer = sound_buffer_new("assets/audio/missile_explo.ogg");
    hub_add_buffer(hub, buffer, "missile_explo");
    buffer = sound_buffer_new("assets/audio/upgrade.ogg");
    hub_add_buffer(hub, buffer, "upgrade");
    buffer = sound_buffer_new("assets/audio/place_defense.ogg");
    hub_add_buffer(hub, buffer, "place_defense");
}