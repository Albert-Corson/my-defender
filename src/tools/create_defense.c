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
    obj_t *next = NULL;
    sfVector2f tmp;
    sfFloatRect rect = {pos.x, pos.y, 50, 50};

    while (list_poll(objs, (void **)&next)) {
        if (next->group == GR_DEFENSE) {
            tmp = VGET(next, get_position);
            objs = sfFloatRect_contains(&rect, tmp.x, tmp.y) ? NULL : objs;
        }
    }
    if (objs)
        return (NULL);
    return ((defense_obj_t *)next);
}

void upgrade_defense(scene_t *scene, sfVector2f pos)
{
    defense_obj_t *defense = get_defense_on_click(scene, pos);
    sound_obj_t *sound = list_fetch(scene->objs, "sfx_upgrade");
    int lvl = defense ? defense->level : 10;
    char *aspect = defense ? defense->aspect : NULL;
    int price = 250;

    FAIL_IF_VOID(!defense || lvl >= 3 || !aspect);
    price += (aspect[0] == 'c' || aspect[0] == 'r' ? 100 : 0);
    FAIL_IF_VOID(300 > ((game_scene_data_t *)scene->extra)->cash);
    ((game_scene_data_t *)scene->extra)->cash -= 300 - price;
    obj_sound_apply((obj_t *)sound, sfSound_play);
    defense->is_alive = sfFalse;
    create_defense(scene, aspect, lvl + 1, pos);
}

void sell_defense(scene_t *scene, sfVector2f pos)
{
    defense_obj_t *defense = get_defense_on_click(scene, pos);
    sound_obj_t *sound = list_fetch(scene->objs, "sfx_erease");

    FAIL_IF_VOID(!defense);
    ((game_scene_data_t *)scene->extra)->cash += 100;
    obj_sound_apply((obj_t *)sound, sfSound_play);
    defense->is_alive = sfFalse;
}

void create_defense(scene_t *scene, char *aspect, int lvl, sfVector2f pos)
{
    defense_obj_t *defense = NULL;
    sound_obj_t *sound = list_fetch(scene->objs, "sfx_place");
    sfVector2u size;
    sfVector2f good_pos;
    float ratio = 0;
    int price = 250 + (aspect[0] == 'c' || aspect[0] == 'r' ? 100 : 0);

    FAIL_IF_VOID(price > ((game_scene_data_t *)scene->extra)->cash);
    ((game_scene_data_t *)scene->extra)->cash -= price;
    FAIL_IF_VOID(!is_tile_available(scene, pos));
    obj_sound_apply((obj_t *)sound, sfSound_play);
    good_pos = VECT2F(pos.x + 25, pos.y + 25);
    defense = defense_new(aspect, lvl, good_pos);
    size = VGET(defense->base, get_size);
    ratio = (size.x > size.y ? size.x : size.y);
    ratio = 50 / ratio;
    defense_obj_set_scale(defense, VECT2F(ratio, ratio));
    scene_add_obj(scene, defense, NULL);
}