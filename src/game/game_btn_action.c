/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** btn_action
*/

#include "defender.h"

void hide_previews(hub_t *hub)
{
    scene_t *scene = hub->scenes;
    anim_obj_t *rect = list_fetch(scene->objs, "prev_tools");

    ((anim_obj_t *)list_fetch(scene->objs, "prev_defenses"))->state = sfFalse;
    ((anim_obj_t *)list_fetch(scene->objs, "prev_range"))->state = sfFalse;
    ((anim_obj_t *)list_fetch(scene->objs, "prev_emp"))->state = sfFalse;
    rect_set_fill_color(rect, RGBA(0, 0, 0, 0));
}

void towers_preview(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    input_obj_t *focused = get_focused_btn(hub);
    anim_obj_t *defenses = list_fetch(scene->objs, "prev_defenses");
    shape_obj_t *circle = list_fetch(scene->objs, "prev_range");
    sfVector2f pos = get_positioning(hub->window);

    FAIL_IF_VOID(!focused || pos.y == -1);
    defenses->state = sfTrue;
    defenses->anims = list_fetch(defenses->anims, focused->label + 4);
    circle->state = sfTrue;
    VFUNC(defenses, set_position, pos);
    VFUNC(circle, set_position, VECT2F(pos.x + 25, pos.y + 25));
    if (CLICK(evt, sfMouseLeft))
        create_defense(hub->scenes, focused->label + 4, 1, pos);
}

void emp_preview(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    input_obj_t *emp_btn = list_fetch(scene->objs, "btn_emp");
    anim_obj_t *prev_emp = list_fetch(scene->objs, "prev_emp");
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hub->window);
    sfVector2f pos;

    FAIL_IF_VOID(!emp_btn->mouse_evt->focus || mouse.y >= 780);
    prev_emp->state = sfTrue;
    prev_emp->anims = list_fetch(prev_emp->anims, "emp");
    pos = VECT2F(mouse.x, mouse.y);
    VFUNC(prev_emp, set_position, pos);
    if (CLICK(evt, sfMouseLeft))
        drop_emp_explosion(scene, pos);
}

int tool_preview(hub_t *hub, sfEvent evt)
{
    input_obj_t *focused = get_focused_btn(hub);
    anim_obj_t *rect = list_fetch(((scene_t *)hub->scenes)->objs, "prev_tools");
    void (*func[2])(scene_t *, sfVector2f) = {sell_defense, upgrade_defense};
    sfVector2f pos = get_positioning(hub->window);
    char c;

    FAIL_IF(!focused || pos.y == -1, 0);
    c = (focused->label + 4)[0];
    FAIL_IF(c == 'e', 0);
    rect_set_position(rect, pos);
    rect_set_fill_color(rect, RGBA(0, 0, 0, 150));
    FAIL_IF(c == 'm' || c == 'r' || c == 'c', 2);
    if (c == 'd')
        rect_set_fill_color(rect, RGBA(255, 0, 0, 150));
    else if (c == 'u')
        rect_set_fill_color(rect, RGBA(0, 0, 200, 150));
    if (CLICK(evt, sfMouseLeft))
        func[c == 'd' ? 0 : 1](hub->scenes, pos);
    return (1);
}

sfVector2f get_positioning(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f rtn = VECT2F(mouse.x - (mouse.x % 50), mouse.y - (mouse.y % 50));

    if (rtn.y >= 780)
        return (VECT2F(-1, -1));
    return (rtn);
}