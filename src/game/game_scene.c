/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** game_scene
*/

#include "defender.h"

void game_scene_data_dtor(void *extra)
{
    game_scene_data_t *data = extra;
    int line = 0;

    while (line < 16) {
        free(data->map[line]);
        ++line;
    }
    free(data->map);
    data->wave = 0;
    data->cash = 0;
}

void game_scene_create_data(scene_t *scene)
{
    game_scene_data_t *data = malloc(sizeof(game_scene_data_t));

    data->map = NULL;
    data->wave = 1;
    data->cash = 500;
    data->elapsed = 0;
    data->dtor = game_scene_data_dtor;
    scene->extra = data;
}

void game_scene_add_evts(scene_t *game)
{
    scene_add_evt(game, evt_new(game_mouse_evt_update_btns, inputs), NULL);
    scene_add_evt(game, evt_new(outline_focused_btn, inputs), "focused_btn");
    scene_add_evt(game, evt_new(select_defenses, inputs), NULL);
    scene_add_evt(game, evt_new(defense_update_evt, context), NULL);
    scene_add_evt(game, evt_new(update_cash, context), NULL);
    scene_add_evt(game, evt_new(game_pause, inputs), "pause");
}

void game_scene_create_objs(scene_t *game, hub_t *hub)
{
    shape_obj_t *rect = rect_new(VECT2U(1600, 100), RGBA(255, 255, 255, 200));

    rect_set_outline_thickness(rect, 2);
    rect_set_outline_color(rect, sfRed);
    VFUNC(rect, set_position, VECT2F(0, 802));
    scene_add_obj(game, rect, "hud_rect");
    game_create_buttons(game);
    create_positioning_preview(game);
    create_tower_lifebar(game);
    create_price_txts(game);
    create_emp_anim(game, hub);
}

int game_scene_create(hub_t *hub)
{
    scene_t *game = scene_new();
    int status = 0;

    game->clear = sfYellow;
    scene_set_sound_buffer(hub, game, "mouse_click");
    game_scene_create_data(game);
    status = parse_map(game, hub->mappath);
    write(2, "Invalid map.\n", (status == 0 ? 14 : 0));
    game_scene_create_objs(game, hub);
    enemy_spawn(game);
    game_create_sounds(hub, game);
    game_scene_add_evts(game);
    hub_add_scene(hub, game, "game_scene");
    return (status);
}