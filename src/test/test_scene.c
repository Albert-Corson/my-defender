/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** test_scene
*/

#include "defender.h"

void defense_update_evt(hub_t *hub, sfEvent evt);

void enemy_move_evt(hub_t *hub, sfEvent evt);

void test_scene_create(hub_t *hub)
{
    scene_t *scene = scene_new();
    // defense_obj_t *t2_2 = defense_new("mg", 2, VECT2F(800, 450));
    // anim_obj_t *enemy = enemy_new("mothership_2", VECT2F(0, 0), 1);

    // scene_add_obj(scene, t2_2, "defense");
    // scene_add_obj(scene, enemy, "enemy");
    // scene_add_evt(scene, evt_new(defense_update_evt, context), NULL);
    // scene_add_evt(scene, evt_new(enemy_follow_mouse, inputs), NULL);
    hub_add_scene(hub, scene, "test_scene");
}