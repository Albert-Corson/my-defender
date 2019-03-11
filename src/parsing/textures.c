/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** textures
*/

#include "defender.h"

char *get_grass_texture(char **map, sfVector2i coords)
{
    char id = map[coords.y][coords.x];
    char *file = NULL;

    if (id == '#')
        file = my_memdup("assets/img/terrain/grass_1.png", -1);
    return (file);
}

char *get_grass_road_hor_ver(char **map, sfVector2i coords)
{
    sfBool left = (coords.x > 0 && map[coords.y][coords.x - 1] == ' ');
    sfBool right = (coords.x < 16 && map[coords.y][coords.x + 1] == ' ');
    char *file = NULL;

    if (left || right)
        file = my_memdup("assets/img/terrain/grass_road_hor.png", -1);
    else
        file = my_memdup("assets/img/terrain/grass_road_ver.png", -1);
    return (file);
}

char *get_grass_road_texture(char **map, sfVector2i coords)
{
    char *file = NULL;

    FAIL_IF(map[coords.y][coords.x] != ' ', NULL);
    if (coords.y > 0 && map[coords.y - 1][coords.x] == ' ') {
        if (coords.x > 0 && map[coords.y][coords.x - 1] == ' ')
            file = my_memdup("assets/img/terrain/grass_road_ul.png", -1);
        else if (coords.x < 32 && map[coords.y][coords.x + 1] == ' ')
            file = my_memdup("assets/img/terrain/grass_road_ur.png", -1);
        else
            file = get_grass_road_hor_ver(map, coords);
    } else if (coords.y < 16 && map[coords.y + 1][coords.x] == ' ') {
        if (coords.x > 0 &&map[coords.y][coords.x - 1] == ' ')
            file = my_memdup("assets/img/terrain/grass_road_ll.png", -1);
        else if (coords.x < 32 && map[coords.y][coords.x + 1] == ' ')
            file = my_memdup("assets/img/terrain/grass_road_lr.png", -1);
        else
            file = get_grass_road_hor_ver(map, coords);
    } else
        file = get_grass_road_hor_ver(map, coords);
    return (file);
}

char *get_tower_texture(char **map, sfVector2i coords)
{
    char id = map[coords.y][coords.x];
    char *file = NULL;

    if (id == 'O')
        file = my_memdup("assets/img/terrain/grass_bush_1.png", -1);
    return (file);
}