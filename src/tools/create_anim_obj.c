/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_anim_obj
*/

#include "defender.h"

anim_obj_t *create_anim_obj(char *path, sfVector2f pos, int nb_frame, uint lim)
{
    anim_t *anim = anim_new(path, nb_frame, lim);
    anim_obj_t *sprite = anim_obj_new();

    anim_obj_add_anim(sprite, anim, NULL);
    anim_obj_set_position(sprite, pos);
    return (sprite);
}