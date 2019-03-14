/*
** EPITECH PROJECT, 2019
** cpy
** File description:
** check_path
*/

#include "defender.h"

int find_spawn_y(char **map)
{
    int line = 0;

    while (line < 16) {
        if (map[line][31] == ' ') {
            return (line);
        }
        ++line;
    }
    return (-1);
}

anim_obj_t *get_tile_at_coords(anim_obj_t *begin, sfVector2f dest)
{
    anim_obj_t *tile = NULL;
    sfVector2f coords = VECT2F(0, 0);

    FAIL_IF(dest.x < 0 || dest.x >= 32, NULL);
    FAIL_IF(dest.y < 0 || dest.y >= 16, NULL);
    while (list_poll(begin, (void **)&tile)) {
        if (coords.x == dest.x && coords.y == dest.y)
            return (tile);
        ++coords.x;
        if (coords.x >= 32) {
            ++coords.y;
            coords.x = 0;
        }
    }
    FAIL_IF(!tile || tile->group != GR_TERRAIN, NULL);
    return (tile);
}

anim_obj_t *get_next_tile(anim_obj_t *begin, sfVector2f *coords)
{
    sfVector2f tmp = {coords->x, coords->y};
    anim_obj_t *up = get_tile_at_coords(begin, VECT2F(tmp.x, tmp.y - 1));
    anim_obj_t *down = get_tile_at_coords(begin, VECT2F(tmp.x, tmp.y + 1));
    anim_obj_t *left = get_tile_at_coords(begin, VECT2F(tmp.x - 1, tmp.y));
    anim_obj_t *right = get_tile_at_coords(begin, VECT2F(tmp.x + 1, tmp.y));
    anim_obj_t *tile = NULL;

    tile = (up && up->nbr == -1 ? up : tile);
    tile = (down && down->nbr == -1 ? down : tile);
    tile = (left && left->nbr == -1 ? left : tile);
    tile = (right && right->nbr == -1 ? right : tile);
    *coords = (tile == up ? VECT2F(tmp.x, tmp.y - 1) : *coords);
    *coords = (tile == down ? VECT2F(tmp.x, tmp.y + 1) : *coords);
    *coords = (tile == left ? VECT2F(tmp.x - 1, tmp.y) : *coords);
    *coords = (tile == right ? VECT2F(tmp.x + 1, tmp.y) : *coords);
    return (tile);
}

int is_near_tower(char **map, sfVector2f coords)
{
    char up = map[(int)coords.y - 1][(int)coords.x];
    char down = map[(int)coords.y + 1][(int)coords.x];
    char left = map[(int)coords.y][(int)coords.x - 1];
    char right = map[(int)coords.y][(int)coords.x + 1];

    return (up == 'O' || down == 'O' || left == 'O' || right == 'O');
}

int check_path(char **map, anim_obj_t *tile)
{
    sfVector2f coords = {31, find_spawn_y(map)};
    anim_obj_t *tmp = get_tile_at_coords(tile, coords);
    int order = 0;
    int ended = 0;

    FAIL_IF(!tmp || coords.y == -1, 0);
    while (!ended) {
        tmp->nbr = order;
        tmp = get_next_tile(tile, &coords);
        ended = (tmp == NULL);
        ++order;
    }
    return (is_near_tower(map, coords));
}