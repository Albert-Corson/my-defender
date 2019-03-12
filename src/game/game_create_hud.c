/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game_create_hub
*/

#include "defender.h"

void game_create_buttons(scene_t *game)
{
    input_obj_t *tmp = NULL;

    tmp = create_img_btn("assets/img/mob/mg_1.png", VECT2F(980, 852.5));
    anim_obj_set_scale(tmp->foreground, VECT2F(0.6, 0.6));
    scene_add_obj(game, tmp, "btn_mg");
    tmp = create_img_btn("assets/img/mob/canon_1.png", VECT2F(1080, 852.5));
    anim_obj_set_scale(tmp->foreground, VECT2F(0.6, 0.6));
    scene_add_obj(game, tmp, "btn_canon");
    tmp = create_img_btn("assets/img/mob/rocket_1.png", VECT2F(1180, 852.5));
    anim_obj_set_scale(tmp->foreground, VECT2F(0.6, 0.6));
    scene_add_obj(game, tmp, "btn_rocket");
    tmp = create_img_btn("assets/img/mob/emp.png", VECT2F(1280, 852.5));
    input_obj_auto_scale_fg(tmp);
    scene_add_obj(game, tmp, "btn_emp");
    tmp = create_img_btn("assets/img/hud/upgrade.png", VECT2F(1380, 852.5));
    input_obj_auto_scale_fg(tmp);
    scene_add_obj(game, tmp, "btn_upgrade");
    tmp = create_img_btn("assets/img/hud/destroy.png", VECT2F(1510, 852.5));
    input_obj_auto_scale_fg(tmp);
    scene_add_obj(game, tmp, "btn_destroy");
}

void create_defenses_prev(scene_t *game)
{
    shape_obj_t *range = circle_new(0, 50, sfTransparent);
    anim_t * mg = anim_new("assets/img/mob/mg_1.png", 1, -1);
    anim_t * rocket = anim_new("assets/img/mob/rocket_1.png", 1, -1);
    anim_t * canon = anim_new("assets/img/mob/canon_1.png", 1, -1);
    anim_obj_t *prev_defense = anim_obj_new();
    sfVector2u scale;
    float ratio = 0;

    circle_set_outline_thickness(range, -3);
    circle_set_outline_color(range, sfBlack);
    anim_obj_add_anim(prev_defense, mg, "mg");
    anim_obj_add_anim(prev_defense, rocket, "rocket");
    anim_obj_add_anim(prev_defense, canon, "canon");
    scale = anim_obj_get_size(prev_defense);
    ratio = scale.x > scale.y ? scale.x : scale.y;
    ratio = 50 / ratio;
    anim_obj_set_scale(prev_defense, VECT2F(ratio, ratio));
    prev_defense->state = sfFalse;
    scene_add_obj(game, prev_defense, "prev_defenses");
    scene_add_obj(game, range, "prev_range");
}

void create_positioning_preview(scene_t *game)
{
    shape_obj_t *tool = rect_new(VECT2U(50, 50), RGBA(0, 0, 0, 150));
    anim_t *emp = anim_new("assets/img/mob/emp.png", 1, -1);
    anim_obj_t *prev_emp = anim_obj_new();
    sfVector2u tmp;

    prev_emp->state = sfFalse;
    anim_obj_add_anim(prev_emp, emp, "emp");
    tmp = anim_obj_get_size(prev_emp);
    anim_obj_set_origin(prev_emp, VECT2F(tmp.x / 2, tmp.y / 2));
    scene_add_obj(game, prev_emp, "prev_emp");
    scene_add_obj(game, tool, "prev_tools");
    create_defenses_prev(game);
}