/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** anim_get
*/

#include "msf/msf.h"

sfFloatRect anim_obj_get_box(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    sfFloatRect box = sfSprite_getGlobalBounds(st_anim_obj->sprite);
    return (box);
}