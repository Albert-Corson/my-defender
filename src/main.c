/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "defender.h"

int main(int ac, char *av[])
{
    char *mappath = NULL;
    int status = 0;

    if (ac != 2) {
        mappath = my_memdup("bonus/default", -1);
    } else if (ac == 2) {
        mappath = my_memdup(av[1], -1);
    } else {
        return (84);
    }
    if (check_map(mappath)) {
        status = gameloop(mappath);
    } else {
        status = my_perror("Error: bad map format.", 0);
    }
    free(mappath);
    return (status);
}

int gameloop(char *mappath)
{
    hub_t *hub = hub_new("\n My Defender \n", VECT2I(1600, 900), sfClose);
    sfEvent evt;

    window_set_icon(hub->window, "assets/img/hud/icon.png");
    load_sound_buffers(hub);
    hub_set_sound_buffer(hub, "bg_music");
    if (hub->sound)
        sfSound_setLoop(hub->sound, sfTrue);
    if (!create_scenes(hub, mappath))
        sfRenderWindow_close(hub->window);
    while (sfRenderWindow_isOpen(hub->window)) {
        scene_clear_objs(hub->scenes);
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