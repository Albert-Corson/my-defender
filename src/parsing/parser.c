/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** parser
*/

#include "defender.h"

char *get_tile_path(char **map, sfVector2i coords)
{
    char *path = NULL;

    path = (!path ? get_grass_texture(map, coords) : path);
    path = (!path ? get_grass_road_texture(map, coords) : path);
    path = (!path ? get_tower_texture(map, coords) : path);
    return (path);
}

anim_obj_t *create_tile(scene_t *scene, char **map, sfVector2i coords)
{
    char *tilepath = get_tile_path(map, coords);
    anim_obj_t *tile = NULL;
    anim_t *anim = NULL;

    FAIL_IF(!tilepath, NULL);
    tile = anim_obj_new();
    anim = anim_new(tilepath, 1, 0);
    anim_obj_add_anim(tile, anim, NULL);
    VFUNC(tile, set_size, VECT2U(50, 50));
    VFUNC(tile, set_position, VECT2F(coords.x * 50, coords.y * 50));
    tile->group = GR_TERRAIN;
    if (map[coords.y][coords.x] == ' ') {
        tile->group = GR_ROAD;
        tile->nbr = -1;
    } else if (map[coords.y][coords.x] == 'O') {
        tile->group = GR_TOWER;
    }
    scene_add_obj(scene, tile, NULL);
    free(tilepath);
    return (tile);
}

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