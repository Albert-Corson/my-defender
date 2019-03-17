/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** how_to_create_txt_2
*/

#include "defender.h"

void canon_txt(scene_t *how_to)
{
    char *str_1 = "Canon:\nshoots slow, but hits hard. It can only take";
    char *str_2 = " out ground targets\ncosts: $350";
    char *str = my_format("%s%s", str_1, str_2);
    text_obj_t *txt = text_obj_new(str, sfBlack, 20);
    anim_obj_t *canon = NULL;
    sfVector2f pos = VECT2F(100, 320);

    canon = create_anim_obj("assets/img/mob/canon_1.png", pos, 1, -1);
    anim_obj_set_size(canon, VECT2U(60, 60));
    VFUNC(txt, set_position, VECT2F(200, pos.y));
    scene_add_obj(how_to, txt, NULL);
    scene_add_obj(how_to, canon, "main_txt");
    free(str);
}

void rocket_txt(scene_t *how_to)
{
    char *str_1 = "Rocket:\nshoots slow, but hits hard. It can only take";
    char *str_2 = " out aerial targets\ncost: $350";
    char *str = my_format("%s%s", str_1, str_2);
    text_obj_t *txt = text_obj_new(str, sfBlack, 20);
    anim_obj_t *rocket = NULL;
    sfVector2f pos = VECT2F(100, 420);

    rocket = create_anim_obj("assets/img/mob/rocket_1.png", pos, 1, -1);
    anim_obj_set_size(rocket, VECT2U(60, 60));
    VFUNC(txt, set_position, VECT2F(200, pos.y));
    scene_add_obj(how_to, txt, NULL);
    scene_add_obj(how_to, rocket, "main_txt");
    free(str);
}

void emp_txt(scene_t *how_to)
{
    char *str_1 = "EMP:\nProduces a hight damage blast on any targets.";
    char *str_2 = "It has a slight reload time\ncost: $500";
    char *str = my_format("%s%s", str_1, str_2);
    text_obj_t *txt = text_obj_new(str, sfBlack, 20);
    anim_obj_t *emp = NULL;
    sfVector2f pos = VECT2F(100, 520);

    emp = create_anim_obj("assets/img/mob/emp.png", pos, 1, -1);
    anim_obj_set_size(emp, VECT2U(60, 60));
    VFUNC(txt, set_position, VECT2F(200, pos.y));
    scene_add_obj(how_to, txt, NULL);
    scene_add_obj(how_to, emp, "main_txt");
    free(str);
}

void upgrade_txt(scene_t *how_to)
{
    char *str_1 = "UPGRADE DEFENSES:\nFirst level gives better firerate,";
    char *str_2 = " second level improves damages\ncost: $300";
    char *str = my_format("%s%s", str_1, str_2);
    text_obj_t *txt = text_obj_new(str, sfBlack, 20);
    anim_obj_t *up = NULL;
    sfVector2f pos = VECT2F(100, 620);

    up = create_anim_obj("assets/img/hud/upgrade.png", pos, 1, -1);
    anim_obj_set_size(up, VECT2U(60, 60));
    VFUNC(txt, set_position, VECT2F(200, pos.y));
    scene_add_obj(how_to, txt, NULL);
    scene_add_obj(how_to, up, "main_txt");
    free(str);
}

void sell_txt(scene_t *how_to)
{
    char *str_1 = "SELL DEFENSES:\nRemove a defenses from the field and gives";
    char *str_2 = " you $100 back";
    char *str = my_format("%s%s", str_1, str_2);
    text_obj_t *txt = text_obj_new(str, sfBlack, 20);
    anim_obj_t *sell = NULL;
    sfVector2f pos = VECT2F(100, 720);

    sell = create_anim_obj("assets/img/hud/destroy.png", pos, 1, -1);
    anim_obj_set_size(sell, VECT2U(60, 60));
    VFUNC(txt, set_position, VECT2F(200, pos.y));
    scene_add_obj(how_to, txt, NULL);
    scene_add_obj(how_to, sell, "main_txt");
    free(str);
}