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
    // anim_obj_t *t1_1 = defense_new(scene, "canon", 1, VECT2F(200, 200));
    // anim_obj_t *t1_2 = defense_new(scene, "canon", 2, VECT2F(200, 450));
    // anim_obj_t *t1_3 = defense_new(scene, "canon", 3, VECT2F(200, 700));
    // anim_obj_t *t2_1 = defense_new(scene, "mg", 1, VECT2F(800, 200));
    // defense_obj_t *t2_2 = defense_new("mg", 2, VECT2F(800, 450));
    // anim_obj_t *t2_3 = defense_new(scene, "mg", 3, VECT2F(800, 700));
    // anim_obj_t *t3_1 = defense_new(scene, "rocket", 1, VECT2F(1400, 200));
    // anim_obj_t *t3_2 = defense_new(scene, "rocket", 2, VECT2F(1400, 450));
    // anim_obj_t *t3_3 = defense_new(scene, "rocket", 3, VECT2F(1400, 700));

    // anim_obj_t *enemy = enemy_new("mothership_2", VECT2F(0, 0), 1);

    // scene_add_obj(scene, t1_1, NULL);
    // scene_add_obj(scene, t2_1, NULL);
    // scene_add_obj(scene, t3_1, NULL);
    // scene_add_obj(scene, t1_2, NULL);
    // scene_add_obj(scene, t2_2, "defense");
    // scene_add_obj(scene, t3_2, NULL);
    // scene_add_obj(scene, t1_3, NULL);
    // scene_add_obj(scene, t2_3, NULL);
    // scene_add_obj(scene, t3_3, NULL);
    // scene_add_obj(scene, enemy, "enemy");
    scene_add_evt(scene, evt_new(defense_update_evt, context), NULL);
    // scene_add_evt(scene, evt_new(enemy_follow_mouse, inputs), NULL);
    hub_add_scene(hub, scene, "test_scene");
}