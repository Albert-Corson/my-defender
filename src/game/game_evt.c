/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game_evt
*/

#include "defender.h"

void game_pause(hub_t *hub, sfEvent evt)
{
    shape_obj_t *slider = NULL;

    if (KRELEASED(evt, sfKeyEscape)) {
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = list_fetch(hub->scenes, "pause_scene");
        slider = list_fetch(((scene_t *)hub->scenes)->objs, "general_sldr");
        VFUNC(slider, set_size, VECT2U(8 * sfListener_getGlobalVolume(), 80));
    }
}

void game_mouse_evt_update_btns(hub_t *hub, sfEvent evt)
{
    input_obj_t *focused_btn = get_focused_btn(hub);
    sfVector2i pos = sfMouse_getPositionRenderWindow(hub->window);
    input_obj_t *st_input = ((scene_t *)hub->scenes)->objs;
    input_obj_t *next = NULL;
    int check = 0;
    sfFloatRect box;

    FAIL_IF_VOID(!CLICK(evt, sfMouseLeft) || !st_input);
    while (list_poll(st_input, (void **)&next)) {
        box = next->type == input ? VGET(next, get_box) : RECT(0, 0, 0, 0);
        if (next->type == input && sfFloatRect_contains(&box, pos.x, pos.y)) {
            next->mouse_evt->focus = sfTrue;
            check = 1;
        }
    }
    if (focused_btn && check)
        focused_btn->mouse_evt->focus = sfFalse;
}

void outline_focused_btn(hub_t *hub, sfEvent evt)
{
    input_obj_t *st_input = ((scene_t *)hub->scenes)->objs;
    input_obj_t *next = NULL;
    input_obj_t *tmp = NULL;
    sfColor save;

    evt = evt;
    FAIL_IF_VOID(!st_input);
    while (list_poll(st_input, (void **)&next)) {
        if (next->type == input && next->mouse_evt->focus) {
            tmp = next;
            save = rect_get_outline_color(next->background);
            rect_set_outline_color(next->background, sfBlack);
        } else if (next->type == input)
            rect_set_outline_color(next->background, RGBA(0, 0, 0, 0));
    }
    if (save.a != 255 && tmp)
        scene_sound_apply(hub->scenes, sfSound_play);
}

void select_defenses(hub_t *hub, sfEvent evt)
{
    hide_previews(hub);
    int check = tool_preview(hub, evt);
    if (check == 2)
        towers_preview(hub, evt);
    else if (!check)
        emp_preview(hub, evt);
}

void update_cash(hub_t *hub, sfEvent evt)
{
    game_scene_data_t *data = ((scene_t *)hub->scenes)->extra;
    text_obj_t *text = list_fetch(((scene_t *)hub->scenes)->objs, "cash_text");
    float elapsed = sfClock_getElapsedTime(hub->timer).microseconds / 10;
    char *str = NULL;

    data->elapsed += elapsed;
    if (data->elapsed > 1000) {
        data->elapsed -= 1000;
        data->cash += 50;
    }
    str = my_format("%d", data->cash);
    text_obj_set_string(text, str);
    free(str);
    evt = evt;
}