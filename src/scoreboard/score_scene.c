/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** score
*/

#include "defender.h"

void update_score_scene(hub_t *hub, scene_t *game_scene)
{
    game_scene_data_t *data = game_scene->extra;
    scene_t *score = list_fetch(hub->scenes, "score_scene");
    text_obj_t *score_txt = list_fetch(score, "score_text");
    text_obj_t *wave = list_fetch(score, "wave_txt");
    char *str_1 = my_format("YOU SCORED %d POINTS", data->score);
    char *str_2 = my_format("WAVE %d", data->wave);

    text_obj_set_string(score_txt, str_1);
    text_obj_set_string(wave, str_2);
    free(str_1);
    free(str_2);
}

void score_scene_create(hub_t *hub)
{
    scene_t *score = scene_new();
    text_obj_t *skip = text_obj_new("Press a key to continue", sfRed, 30);
    text_obj_t *score_txt = text_obj_new("YOU SCORED X POINTS", sfWhite, 80);
    text_obj_t *wave = text_obj_new("WAVE X", sfWhite, 50);

    score->clear = sfBlack;
    scene_set_sound_buffer(hub, score, "mouse_click");
    text_obj_set_font(score_txt, "assets/font/blocks.ttf");
    VFUNC(score_txt, set_position, (sfVector2f){290, 225});
    VFUNC(wave, set_position, (sfVector2f){685, 450});
    VFUNC(skip, set_position, (sfVector2f){570, 700});
    scene_add_obj(score, skip, "press_a_key");
    scene_add_obj(score, score_txt, "score_text");
    scene_add_obj(score, wave, "wave_text");
    scene_add_evt(score, evt_new(pres_animate_text, context), "txt_anim");
    scene_add_evt(score, evt_new(score_show_menu, inputs), "show_menu");
    scene_add_evt(score, evt_new(pres_quit_game, inputs), "quit_game");
    hub_add_scene(hub, score, "score_scene");
}