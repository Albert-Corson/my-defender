/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "defender.h"

int main(int ac, char *av[], char *env[])
{
    char *mappath = NULL;

    if (!env || !get_env_var(env, "DISPLAY"))
        return (0);
    if (ac != 2)
        mappath = my_memdup("bonus/default", -1);
    if (ac == 2 && my_memcmp(av[1], "-h", -1) == 0) {
        show_usage();
        return (0);
    }
    else if (ac == 2)
        mappath = my_memdup(av[1], -1);
    if (check_map(mappath))
        init_game(mappath);
    else
        my_perror("Error: bad map format.", 0);
    free(mappath);
    return (0);
}

int init_game(char *mappath)
{
    hub_t *hub = hub_new("\n My Defender \n", VECT2I(1600, 900), sfClose);

    hub_set_framerate(hub, 144);
    window_set_icon(hub->window, "assets/img/hud/icon.png");
    load_sound_buffers(hub);
    hub_set_sound_buffer(hub, "bg_music");
    hub->mappath = my_memdup(mappath, -1);
    if (hub->sound)
        sfSound_setLoop(hub->sound, sfTrue);
    if (!create_scenes(hub))
        sfRenderWindow_close(hub->window);
    while (sfRenderWindow_isOpen(hub->window))
        gameloop(hub);
    hub_destroy(hub);
    return (0);
}

void gameloop(hub_t *hub)
{
    sfInt64 delay = sfClock_getElapsedTime(hub->timer).microseconds;
    sfEvent evt;

    if (delay / 1000 >= 1000 / hub->framerate) {
        scene_clear_objs(hub->scenes);
        sfRenderWindow_clear(hub->window, ((scene_t *)hub->scenes)->clear);
        hub_trigger_evts_scope(hub, context, evt);
        while (sfRenderWindow_pollEvent(hub->window, &evt)) {
            hub_trigger_evts_scope(hub, inputs, evt);
        }
        hub_render(hub);
        sfRenderWindow_display(hub->window);
    }
}