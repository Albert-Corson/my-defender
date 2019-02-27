/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "project.h"

int main(void)
{
    sfVector2i w_size = {1600, 900};
    hub_t *hub = hub_new("\n My Defender \n", w_size, sfDefaultStyle);
    menu_create(hub);
    sfEvent evt;

    while (sfRenderWindow_isOpen(hub->window)) {
        sfRenderWindow_clear(hub->window, sfWhite);
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