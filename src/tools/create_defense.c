/*
** EPITECH PROJECT, 2019
** my_defender.c
** File description:
** create_defense
*/

#include "defender.h"

defense_obj_t *get_defense_on_click(scene_t *scene, sfVector2f pos)
{
    obj_t *objs = scene->objs;
    obj_t *tmp = NULL;
    sfVector2f tmp_pos;
    sfFloatRect rect = {pos.x, pos.y, 50, 50};

    while (list_poll(objs, (void **)&tmp)) {
        if (tmp->group == GR_DEFENSE) {
            tmp_pos = VGET(tmp, get_position);
            objs = sfFloatRect_contains(&rect, tmp_pos.x, tmp_pos.y) ? NULL : objs;
        }
    }
    if (objs)
        return (NULL);
    return ((defense_obj_t *)tmp);
}

void upgrade_defense(scene_t *scene, sfVector2f pos)
{
    defense_obj_t *defense = get_defense_on_click(scene, pos);
    int lvl = defense ? defense->level : 10;
    char *aspect = defense ? defense->aspect : NULL;

    FAIL_IF_VOID(!defense || lvl >= 3 || !aspect);
    defense->is_alive = sfFalse;
    create_defense(scene, aspect, lvl + 1, pos);
}

void sell_defense(scene_t *scene, sfVector2f pos)
{
    defense_obj_t *defense = get_defense_on_click(scene, pos);

    FAIL_IF_VOID(!defense);
    defense->is_alive = sfFalse;
}

int check(scene_t *scene, sfVector2f pos)
{
    obj_t *obj = scene->objs;
    obj_t *tmp = NULL;
    sfFloatRect rect = {pos.x, pos.y, 50, 50};
    sfVector2f xy;

    while (list_poll(obj, (void **)&tmp)) {
        xy = tmp->group == GR_DEFENSE ? VGET(tmp, get_position) : xy;
        if (sfFloatRect_contains(&rect, xy.x, xy.y) && tmp->group == GR_DEFENSE && tmp->is_alive)
            return(0);
    }
    return (1);
}

void create_defense(scene_t *scene, char *aspect, int lvl, sfVector2f pos)
{
    defense_obj_t *defense = 0;
    sfVector2u size;
    sfVector2f good_pos;
    float ratio = 0;

    FAIL_IF_VOID(!check(scene, pos));
    good_pos = VECT2F(pos.x + 25, pos.y + 25);
    defense = defense_new(aspect, lvl, good_pos);
    size = VGET(defense->base, get_size);
    ratio = (size.x > size.y ? size.x : size.y);
    ratio = 50 / ratio;
    defense_obj_set_scale(defense, VECT2F(ratio, ratio));
    scene_add_obj(scene, defense, NULL);
}