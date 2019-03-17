/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** enemy_met
*/

#include "defender.h"

void enemy_render(void *obj, hub_t *hub)
{
    anim_obj_t *anim = obj;
    enemy_data_t *data = anim ? anim->extra : NULL;

    FAIL_IF_VOID(!anim);
    anim_obj_render(anim, hub);
    rect_render(data->lifebar, hub);
}

void enemy_destroy_threats(scene_t *scene, obj_t *enemy)
{
    obj_t *begin = scene->objs;
    obj_t *curr = NULL;
    defense_obj_t *defense = NULL;
    missile_data_t *missile_data = NULL;

    while (list_poll(begin, (void **)&curr)) {
        defense = (defense_obj_t *)curr;
        missile_data = (missile_data_t *)curr->extra;
        if (curr->group == GR_MISSILE && missile_data->target == enemy)
            obj_kill(curr);
        else if (curr->group == GR_DEFENSE && defense->target == enemy)
            defense->target = NULL;
    }
}

void enemy_kill(scene_t *scene, obj_t *enemy, sfBool reward)
{
    game_scene_data_t *scene_data = scene->extra;
    enemy_data_t *enemy_data = enemy->extra;

    scene_data->alive_enemies--;
    enemy_data->hp = 0;
    if (reward) {
        scene_data->cash += 50;
        scene_data->score += 50;
    }
    obj_kill(enemy);
    enemy_destroy_threats(scene, enemy);
}