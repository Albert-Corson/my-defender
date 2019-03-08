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
}