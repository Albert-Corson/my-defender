/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** options_btn_action
*/

#include "defender.h"

void change_volume_slider(hub_t *hub, void *obj)
{
    obj_t *slider;
    sfVector2i mouse;
    sfVector2f rect;

    FAIL_IF_VOID(!obj || !hub || !((obj_t *)obj)->mouse_evt->active);
    slider = list_fetch(((scene_t *)hub->scenes)->objs, "general_sldr");
    mouse = sfMouse_getPositionRenderWindow(hub->window);
    rect = VGET(obj, get_position);
    rect.x = mouse.x - rect.x;
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x > 800)
        rect.x = 800;
    rect_set_size(slider, VECT2U(rect.x, VGET(slider, get_size).y));
    sfListener_setGlobalVolume((rect.x / 800) * 100);
}

void change_sfx_slider(hub_t *hub, void *obj)
{
    obj_t *slider;
    sfVector2i mouse;
    sfVector2f rect;

    FAIL_IF_VOID(!obj || !hub || !((obj_t *)obj)->mouse_evt->active);
    slider = list_fetch(((scene_t *)hub->scenes)->objs, "sfx_sldr");
    mouse = sfMouse_getPositionRenderWindow(hub->window);
    rect = VGET(obj, get_position);
    rect.x = mouse.x - rect.x;
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x > 600)
        rect.x = 600;
    if (sfSound_getStatus(((scene_t *)hub->scenes)->sound) != sfPlaying)
        scene_sound_apply(hub->scenes, sfSound_play);
    rect_set_size(slider, VECT2U(rect.x, VGET(obj, get_size).y));
    scenes_set_global_volume(hub->scenes, (rect.x / 600) * 100);
}

void change_music_slider(hub_t *hub, void *obj)
{
    obj_t *slider;
    sfVector2i mouse;
    sfVector2f rect;

    FAIL_IF_VOID(!obj || !hub || !((obj_t *)obj)->mouse_evt->active);
    slider = list_fetch(((scene_t *)hub->scenes)->objs, "music_sldr");
    mouse = sfMouse_getPositionRenderWindow(hub->window);
    rect = VGET(obj, get_position);
    rect.x = mouse.x - rect.x;
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x > 600)
        rect.x = 600;
    rect_set_size(slider, VECT2U(rect.x, VGET(obj, get_size).y));
    hub_set_volume(hub, (rect.x / 600) * 100);
}

void back_btn_action(hub_t *hub, void *btn)
{
    scene_t *menu = list_fetch(hub->scenes, "menu_scene");
    input_obj_t *st_btn = btn;
    sfBool hover = st_btn->mouse_evt->hover;
    sfBool focus = st_btn->mouse_evt->focus;
    sfBool active = st_btn->mouse_evt->active;

    if (focus && !active && hover) {
        rect_set_outline_color(st_btn->background, sfBlack);
        scene_sound_apply(hub->scenes, sfSound_play);
        hub->scenes = menu ? menu : hub->scenes;
    }
    if (active && hover)
        rect_set_fill_color(st_btn->background, RGBA(100, 100, 100, 255));
    else if (focus)
        rect_set_fill_color(st_btn->background, sfBlack);
    if (focus && !active)
        st_btn->mouse_evt->focus = sfFalse;
}

void change_fps_slider(hub_t *hub, void *obj)
{
    obj_t *slider;
    text_obj_t *text;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hub->window);
    sfVector2f rect = VGET(obj, get_position);
    char *str = NULL;
    uint fps = 0;

    FAIL_IF_VOID(!hub || !((obj_t *)obj)->mouse_evt->active);
    slider = list_fetch(((scene_t *)hub->scenes)->objs, "fps_sldr");
    text = list_fetch(((scene_t *)hub->scenes)->objs, "fps_txt");
    rect.x = mouse.x - rect.x;
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x > 800)
        rect.x = 800;
    rect_set_size(slider, VECT2U(rect.x, VGET(slider, get_size).y));
    fps = (((800 - rect.x) / 800) * 30) + ((rect.x / 800) * 144);
    hub_set_framerate(hub, fps);
    str = my_format("FPS LIMIT: %d", fps);
    text_obj_set_string(text, str);
    free(str);
}