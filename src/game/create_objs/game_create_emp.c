/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_emp
*/

#include "defender.h"

void create_emp_anim(scene_t *game, hub_t *hub)
{
    anim_obj_t *emp;

    emp = create_anim_obj("assets/img/anim/explosion.png", VECT2F(0, 0), 7, 85);
    anim_set_loop(emp->anims, sfFalse);
    emp->state = sfFalse;
    obj_set_sound_buffer(hub, emp, "emp_explo");
    obj_recenter_origin(emp);
    scene_add_obj(game, emp, "explosion");
}

void drop_emp_explosion(scene_t *scene, sfVector2f pos)
{
    obj_t *explo = list_fetch(scene->objs, "explosion");
    obj_t *objs = scene->objs;
    obj_t *next = NULL;
    sfVector2u box = anim_obj_get_size(explo);

    FAIL_IF_VOID(500 > ((game_scene_data_t *)scene->extra)->cash);
    ((game_scene_data_t *)scene->extra)->cash -= 500;
    FAIL_IF_VOID(!explo || !explo->sound);
    FAIL_IF_VOID(sfSound_getStatus(explo->sound) == sfPlaying);
    obj_sound_apply((obj_t  *)explo, sfSound_play);
    anim_obj_set_position(explo, pos);
    explo->state = sfTrue;
    while (list_poll(objs, (void **)&next)) {
        if (next->group == GR_ENEMY && objs_distance(next, explo) < box.y / 2)
            ((enemy_data_t *)next->extra)->hp -= 200;
    }
}