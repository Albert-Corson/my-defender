/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** enemy_evts
*/

#include "defender.h"

void enemy_follow_mouse(hub_t *hub, sfEvent evt)
{
    sfVector2f mouse = {0, 0};
    obj_t *enemy = list_fetch(((scene_t *)hub->scenes)->objs, "enemy");

    if (evt.type == sfEvtMouseMoved) {
        mouse.x = evt.mouseMove.x;
        mouse.y = evt.mouseMove.y;
        VFUNC(enemy, set_position, mouse);
    }
}

void enemy_update_lifebar(anim_obj_t *enemy)
{
    enemy_data_t *extra = enemy->extra;
    sfVector2u size = rect_get_size(extra->lifebar);

    size.x = (extra->hp / extra->max_hp) * extra->lifebar_size;
    rect_set_size(extra->lifebar, size);
}

void enemy_move(hub_t *hub, obj_t *enemy)
{
    int step = ((enemy_data_t *)enemy->extra)->tile_step;
    obj_t *begin = ((scene_t *)hub->scenes)->objs;
    obj_t *curr = NULL;
    game_scene_data_t *data = ((scene_t *)hub->scenes)->extra;
    sfVector2f speed = {0, 0};
    float distance = 0;

    FAIL_IF_VOID(!enemy->state);
    while (list_poll(begin, (void **)&curr)) {
        distance = objs_distance(enemy, curr);
        if (curr->group == GR_ROAD && curr->nbr == step + 1 && distance <= 51) {
            ((enemy_data_t *)enemy->extra)->tile_step++;
            speed = vector_normalize(objs_vector(enemy, curr));
            obj_set_speed(enemy, speed.x * 100, speed.y * 100);
        }
        if (enemy->state && curr->group == GR_TOWER && distance < 10) {
            data->tower_hp -= 100;
            obj_set_state(enemy, sfFalse);
        }
    }
}