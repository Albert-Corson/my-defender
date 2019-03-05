/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "defender.h"

void create_scenes(hub_t *hub)
{
    pres_scene_create(hub);
    menu_scene_create(hub);
    options_scene_create(hub);
    game_scene_create(hub);
    pause_scene_create(hub);
    test_scene_create(hub);
}

int main(void)
{
    sfVector2i w_size = {1600, 900};
    hub_t *hub = hub_new("\n My Defender \n", w_size, sfDefaultStyle);
    window_set_icon(hub->window, "assets/img/icon.png");
    create_scenes(hub);
    sfEvent evt;

    while (sfRenderWindow_isOpen(hub->window)) {
        sfRenderWindow_clear(hub->window, sfBlack);
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