/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** is_tile_available
*/

#include "defender.h"

// if (grp != GR_DEFENSE && grp != GR_TOWER && grp != GR_ROAD)
static int check_tile(obj_t *tmp, sfFloatRect rect)
{
    sfVector2f pos;
    int grp = tmp->group;

    FAIL_IF(!tmp, 0);
    if (!tmp->is_alive)
        return (0);
    if (grp != GR_DEFENSE)
        return (0);
    pos = VGET(tmp, get_position);
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        return (0);
    return (1);
}

int is_tile_available(scene_t *scene, sfVector2f pos)
{
    obj_t *obj = scene->objs;
    obj_t *tmp = NULL;
    sfFloatRect rect = {pos.x, pos.y, 50, 50};

    while (list_poll(obj, (void **)&tmp)) {
        if (check_tile(tmp, rect))
            return (0);
    }
    return (1);
}