/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "defender.h"

int main(void)
{
    hub_t *hub = hub_new("\n My Defender \n", VECT2I(1600, 900), sfClose);
    sfEvent evt;

    window_set_icon(hub->window, "assets/img/icon.png");
    load_sound_buffers(hub);
    hub_set_sound_buffer(hub, "bg_music");
    if (hub->sound)
        sfSound_setLoop(hub->sound, sfTrue);
    create_scenes(hub);
    while (sfRenderWindow_isOpen(hub->window)) {
        sfRenderWindow_clear(hub->window, ((scene_t *)hub->scenes)->clear);
        hub_trigger_evts_scope(hub, context, evt);
        while (sfRenderWindow_pollEvent(hub->window, &evt)) {
            hub_trigger_evts_scope(hub, inputs, evt);
        }
        hub_render(hub);
        sfRenderWindow_display(hub->window);
    }
    hub_destroy(hub);
    return (0);
}