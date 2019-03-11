/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** checks
*/

#include "defender.h"

int check_map(char *mappath)
{
    int fd = open(mappath, O_RDONLY);
    sfVector2i coords = VECT2I(0, 0);
    char buf[34];
    int err = 0;

    FAIL_IF(fd < 2, 0);
    while (!err && read(fd, buf, 33)) {
        err = (!err ? coords.y >= 16 : err);
        err = (!err ? buf[32] != '\n' && buf[32] != '\0' : err);
        coords.x = 0;
        while (!err && coords.x < 32) {
            err = (!err ? !my_memchr("# O", buf[coords.x], -1) : err);
            buf[coords.x] = 0;
            ++coords.x;
        }
        ++coords.y;
    }
    err = (!err ? coords.y < 16 : err);
    close(fd);
    return (!err);
}