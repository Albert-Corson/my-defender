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

void upgrade_defense(hub_t *hub, sfVector2f pos)
{
    scene_t *scene = hub->scenes;
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
    create_defense(hub, aspect, lvl + 1, pos);
}

void sell_defense(hub_t *hub, sfVector2f pos)
{
    scene_t *scene = hub->scenes;
    defense_obj_t *defense = get_defense_on_click(scene, pos);
    sound_obj_t *sound = list_fetch(scene->objs, "sfx_erease");

    FAIL_IF_VOID(!defense);
    ((game_scene_data_t *)scene->extra)->cash += 100;
    obj_sound_apply((obj_t *)sound, sfSound_play);
    defense->is_alive = sfFalse;
}

void create_defense(hub_t *hub, char *aspect, int lvl, sfVector2f pos)
{
    scene_t *scene = hub->scenes;
    defense_obj_t *defense = NULL;
    sound_obj_t *sound = list_fetch(scene->objs, "sfx_place");
    sfVector2f good_pos;
    int price = 250 + (aspect[0] == 'c' || aspect[0] == 'r' ? 100 : 0);

    FAIL_IF_VOID(price > ((game_scene_data_t *)scene->extra)->cash);
    FAIL_IF_VOID(!is_tile_available(scene, pos));
    ((game_scene_data_t *)scene->extra)->cash -= price;
    obj_sound_apply((obj_t *)sound, sfSound_play);
    good_pos = VECT2F(pos.x + 25, pos.y + 25);
    defense = defense_new(aspect, lvl, good_pos);
    obj_set_sound_buffer(hub, defense, "missile_explo");
    VFUNC(defense, set_size, VECT2U(50, 50));
    scene_add_obj(scene, defense, NULL);
}