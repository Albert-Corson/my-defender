/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** parser
*/

#include "defender.h"

char **get_map(char *mappath)
{
    char **map = malloc(sizeof(char *) * 17);
    char buf = 0;
    sfVector2i coords = VECT2I(0, 0);
    int fd = open(mappath, O_RDONLY);

    while (coords.y < 16) {
        map[coords.y] = my_calloc(33, sizeof(char));
        read(fd, map[coords.y], 32);
        read(fd, &buf, 1);
        ++coords.y;
    }
    map[coords.y] = NULL;
    close(fd);
    return (map);
}

int parse_map(scene_t *scene, char *mappath)
{
    char **map = get_map(mappath);
    sfVector2i coords = VECT2I(0, 0);
    anim_obj_t *tile = NULL;

    while (coords.y < 16) {
        coords.x = 0;
        if (!tile) {
            tile = create_tile(scene, map, coords);
            ++coords.x;
        }
        while (coords.x < 32) {
            create_tile(scene, map, coords);
            ++coords.x;
        }
        ++coords.y;
    }
    ((game_scene_data_t *)scene->extra)->map = map;
    return (check_path(map, tile));
}