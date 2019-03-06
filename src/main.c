/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "defender.h"

int main(void)
{
    sfVector2i w_size = {1600, 900};
    hub_t *hub = hub_new("\n My Defender \n", w_size, sfDefaultStyle);
    window_set_icon(hub->window, "assets/img/icon.png");
    load_sound_buffers(hub);
    hub_set_sound_buffer(hub, "bg_music");
    if (hub->sound)
        sfSound_setLoop(hub->sound, sfTrue);
    create_scenes(hub);
    sfEvent evt;

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