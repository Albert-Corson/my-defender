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

    tmp = create_img_btn("assets/img/mob/mg_1.png", VECT2F(1020, 845));
    anim_obj_set_scale(tmp->foreground, VECT2F(0.5, 0.5));
    scene_add_obj(game, tmp, "btn_mg");
    tmp = create_img_btn("assets/img/mob/canon_1.png", VECT2F(1120, 845));
    anim_obj_set_scale(tmp->foreground, VECT2F(0.5, 0.5));
    scene_add_obj(game, tmp, "btn_canon");
    tmp = create_img_btn("assets/img/mob/rocket_1.png", VECT2F(1220, 845));
    anim_obj_set_scale(tmp->foreground, VECT2F(0.5, 0.5));
    scene_add_obj(game, tmp, "btn_rocket");
    tmp = create_img_btn("assets/img/mob/emp.png", VECT2F(1320, 845));
    input_obj_auto_scale_fg(tmp);
    scene_add_obj(game, tmp, "btn_emp");
    tmp = create_img_btn("assets/img/hud/upgrade.png", VECT2F(1420, 845));
    input_obj_auto_scale_fg(tmp);
    scene_add_obj(game, tmp, "btn_upgrade");
    tmp = create_img_btn("assets/img/hud/destroy.png", VECT2F(1540, 845));
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

void create_positioning_preview(scene_t *game, hub_t *hub)
{
    shape_obj_t *tool = rect_new(VECT2U(50, 50), RGBA(0, 0, 0, 0));
    anim_t *crosshair = anim_new("assets/img/mob/emp.png", 1, -1);
    anim_obj_t *prev_emp = anim_obj_new();
    anim_obj_t *emp;
    sfVector2u tmp;

    obj_set_sound_buffer(hub, tool, "mouse_hover");
    emp = create_anim_obj("assets/img/anim/explosion.png", VECT2F(0, 0), 7, 70);
    anim_set_loop(emp->anims, sfTrue);
    emp->state = sfFalse;
    obj_set_sound_buffer(hub, emp, "explosion");
    scene_add_obj(game, emp, "explosion");
    prev_emp->state = sfFalse;
    anim_obj_add_anim(prev_emp, crosshair, "emp");
    tmp = anim_obj_get_size(prev_emp);
    anim_obj_set_origin(prev_emp, VECT2F(tmp.x / 2, tmp.y / 2));
    scene_add_obj(game, prev_emp, "prev_emp");
    scene_add_obj(game, tool, "prev_tools");
    create_defenses_prev(game);
}

void create_tower_lifebar(scene_t *game)
{
    sfVector2u size = VECT2U(650, 60);
    sfVector2f pos = VECT2F(30, 825);
    anim_obj_t *cash;
    text_obj_t *text = text_obj_new("0", RGBA(0, 200, 0, 220), 35);
    shape_obj_t *back_lifebar = rect_new(size, sfBlack);
    shape_obj_t *lifebar = rect_new(size, RGBA(200, 0, 0, 255));
    text_obj_t *wave = text_obj_new("WAVE 0", RGBA(255, 255, 255, 200), 40);

    VFUNC(back_lifebar, set_position, pos);
    VFUNC(lifebar, set_position, pos);
    pos = VECT2F(pos.x + (size.x / 2) - 80, pos.y + (size.y / 2) - 28);
    VFUNC(wave, set_position, pos);
    scene_add_obj(game, back_lifebar, "back_lifebar");
    scene_add_obj(game, lifebar, "lifebar");
    scene_add_obj(game, wave, "wave_text");
    VFUNC(text, set_position, VECT2F(795, 830));
    cash = create_anim_obj("assets/img/hud/money.png", VECT2F(730, 825), 1, -1);
    VFUNC(cash, set_scale, VECT2F(0.5, 0.5));
    scene_add_obj(game, cash, "cash_img");
    scene_add_obj(game, text, "cash_text");
}

void create_price_txts(scene_t *game)
{
    text_obj_t *mg = text_obj_new("$999", RGBA(200, 0, 0, 220), 15);
    text_obj_t *canon = text_obj_new("$999", RGBA(200, 0, 0, 220), 15);
    text_obj_t *rocket = text_obj_new("$999", RGBA(200, 0, 0, 220), 15);
    text_obj_t *emp = text_obj_new("$999", RGBA(200, 0, 0, 220), 15);
    text_obj_t *upgrade = text_obj_new("$999", RGBA(200, 0, 0, 220), 15);
    text_obj_t *sell = text_obj_new("$999", RGBA(0, 200, 0, 220), 15);

    VFUNC(mg, set_position, VECT2F(997, 880));
    VFUNC(canon, set_position, VECT2F(1097, 880));
    VFUNC(rocket, set_position, VECT2F(1197, 880));
    VFUNC(emp, set_position, VECT2F(1297, 880));
    VFUNC(upgrade, set_position, VECT2F(1397, 880));
    VFUNC(sell, set_position, VECT2F(1517, 880));
    scene_add_obj(game, mg, "mg_price");
    scene_add_obj(game, canon, "canon_price");
    scene_add_obj(game, rocket, "rocket_price");
    scene_add_obj(game, emp, "emp_price");
    scene_add_obj(game, upgrade, "_price");
    scene_add_obj(game, sell, "sell_price");
}