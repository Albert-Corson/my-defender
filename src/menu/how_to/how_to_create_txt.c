/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** how_to_create_txt
*/

#include "defender.h"

static void mg_txt(scene_t *how_to)
{
    char *str_1 = "Machine gun:\nshoots fast, but with low damage. It can take";
    char *str_2 = " out both aerial or ground targets\ncost: $250";
    char *str = my_format("%s%s", str_1, str_2);
    text_obj_t *txt = text_obj_new(str, sfBlack, 20);
    anim_obj_t *mg = NULL;
    sfVector2f pos = VECT2F(100, 220);

    mg = create_anim_obj("assets/img/mob/mg_1.png", pos, 1, -1);
    anim_obj_set_size(mg, VECT2U(60, 60));
    VFUNC(txt, set_position, VECT2F(200, pos.y + 5));
    scene_add_obj(how_to, txt, NULL);
    scene_add_obj(how_to, mg, "main_txt");
    free(str);
}

static void create_main_txt(scene_t *how_to)
{
    char *str_1 = "The goal of this game is to prevent your tower from being";
    char *str_2 = " destroyed by pesky enemies\nTo do so you have";
    char *str_3 = " multiple tools at your disposal :";
    char *main_txt = my_format("%s%s%s", str_1, str_2, str_3);
    text_obj_t *txt = text_obj_new(main_txt, sfRed, 25);
    char *cash = "You earn monney with time and by destroying enemies";
    text_obj_t *txt_2 = text_obj_new(cash, sfRed, 20);

    VFUNC(txt, set_position, VECT2F(50, 150));
    VFUNC(txt_2, set_position, VECT2F(450, 825));
    scene_add_obj(how_to, txt, "main_txt");
    scene_add_obj(how_to, txt_2, "main_txt");
    free(main_txt);
}

void how_to_create_txt(scene_t *how_to)
{
    create_main_txt(how_to);
    mg_txt(how_to);
    canon_txt(how_to);
    rocket_txt(how_to);
    emp_txt(how_to);
    sell_txt(how_to);
    upgrade_txt(how_to);
}