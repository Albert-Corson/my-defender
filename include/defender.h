/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** project
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <fcntl.h>
#include "msf/msf.h"

/*
**  ENUMS
*/
typedef enum {
    GR_DEFAULT,
    GR_TERRAIN,
    GR_DEFENSE,
    GR_ENEMY,
    GR_MISSILE
} group_e;

/*
**  STRUCTS
*/
typedef struct enemy_data_s {
    int level;
    sfBool aerial;
    sfBool ground;
    float max_hp;
    float hp;
    float speed;
} enemy_data_t;

typedef struct defense_obj_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    // msf_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfBool is_collider;
    obj_vtable_t *vtable;
    obj_physics_t *physics;
    obj_mouse_evt_t *mouse_evt;
    void *extra;
    void (*on_active)(hub_t *, void *);
    sfSound *sound;
    int nbr;
    sfBool is_alive;

    char *aspect;
    anim_obj_t *base;
    anim_obj_t *tower;
    obj_t *target;
    int level;
    sfInt64 firerate;
    float dps;
    float range;
    sfInt64 elapsed;
} defense_obj_t;

typedef struct missile_data_s {
    float speed;
    defense_obj_t *sender;
    obj_t *target;
} missile_data_t;

int gameloop(char *mappath);
void load_sound_buffers(hub_t *hub);

// PARSING
int check_map(char *mappath);
void parse_map(scene_t *scene, char *mappath);
char *get_grass_texture(char **map, sfVector2i coords);
char *get_grass_road_texture(char **map, sfVector2i coords);
char *get_tower_texture(char **map, sfVector2i coords);

// TOOLS
int readjust_nb(int nb, int min, int max);
int random_nbr(sfClock *random);
int random_clamp(sfClock *random, int min, int max);
void other_scenes_sound_apply(hub_t *hub, void (*func)(sfSound *));
void sfx_set_volume(scene_t *scene, float volume);
void outline_focused_btn(hub_t *hub, sfEvent evt);
void outline_hovered_btn(hub_t *hub, sfEvent evt);
void create_volume_slider(scene_t *options);
void create_scenes(hub_t *hub, char *mappath);
input_obj_t *create_btn(sfFloatRect box, sfColor bg, int txt_size, char *txt);
input_obj_t *create_img_btn(char *path, sfVector2f pos);
anim_obj_t *create_anim_obj(char *path, sfVector2f pos, int nb_frame, uint lim);
void create_defense(scene_t *scene, char *aspect, int lvl, sfVector2f pos);
void sell_defense(scene_t *scene, sfVector2f pos);
void upgrade_defense(scene_t *scene, sfVector2f pos);

// GAME NPC
void *missile_new(void *launcher, char *aspect);
    // DEFENSES
void *defense_new(char *aspect, int lvl, sfVector2f pos);
void defense_ctor(defense_obj_t *st_defense, int lvl);
void defense_dtor(void *defense);
void defense_destroy(void *defense);
void defense_obj_set_pos(void *obj, sfVector2f pos);
void defense_obj_set_origin(void *obj, sfVector2f origin);
void defense_obj_set_scale(void *obj, sfVector2f scale);
void defense_obj_set_rotation(void *obj, float angle);
void defense_obj_render(void *obj, hub_t *hub);
sfVector2f defense_obj_get_pos(void *obj);
sfVector2f defense_obj_get_origin(void *obj);
float defense_obj_get_rotation(void *obj);
sfVector2f defense_obj_get_scale(void *obj);
sfFloatRect defense_obj_get_box(void *obj);
void *defense_obj_vtable_new(void);
void defense_obj_vtable_destroy(void *obj_vtable);
void defense_lock_target(hub_t *hub, obj_t *obj);
void defense_fire(hub_t *hub, obj_t *obj);
void defense_update_evt(hub_t *hub, sfEvent evt);
    // ENEMY
void *enemy_new(char *aspect, sfVector2f pos, float life_multiplier);
void *enemy_data_new(float max_hp, float speed);
void enemy_follow_mouse(hub_t *hub, sfEvent evt);

// CREATE SCENES
void menu_scene_create(hub_t *hub);
void pres_scene_create(hub_t *hub);
void options_scene_create(hub_t *hub);
void game_scene_create(hub_t *hub, char *mappath);
void pause_scene_create(hub_t *hub);

void test_scene_create(hub_t *hub);

// PRESENTATION SCENE
void pres_animate_text(hub_t *hub, sfEvent evt);
void pres_show_menu(hub_t *hub, sfEvent evt);
void pres_quit_game(hub_t *hub, sfEvent evt);
void mini_game_txt(hub_t *hub, sfEvent evt);

// MENU SCENE
void menu_place_arrow(hub_t *hub, sfEvent evt);
void menu_quit_game(hub_t *hub, void *obj);
void menu_show_options(hub_t *hub, void *obj);
void menu_show_game(hub_t *hub, void *obj);
void menu_show_pres(hub_t *hub, sfEvent evt);

// OPTIONS SCENE
void options_show_menu(hub_t *hub, sfEvent evt);
void change_volume_slider(hub_t *hub, void *obj);
void change_sfx_slider(hub_t *hub, void *obj);
void change_music_slider(hub_t *hub, void *obj);

// GAME SCENE
void game_pause(hub_t *hub, sfEvent evt);
input_obj_t *create_img_btn(char *path, sfVector2f pos);
void game_create_buttons(scene_t *game);
void create_positioning_preview(scene_t *game);
sfVector2f get_positioning(sfRenderWindow *window);
input_obj_t *get_focused_btn(hub_t *hub);
void select_defenses(hub_t *hub, sfEvent evt);
void hide_previews(hub_t *hub);
void towers_preview(hub_t *hub, sfEvent evt);
void emp_preview(hub_t *hub, sfEvent evt);
int tool_preview(hub_t *hub, sfEvent evt);
void create_tower_lifebar(scene_t *game);
void create_price_txts(scene_t *game);

// PAUSE SCENE
void pause_menu_action(hub_t *hub, void *obj);
void pause_quit_action(hub_t *hub, void *obj);
void pause_resume_action(hub_t *hub, void *obj);
void pause_esc_key(hub_t *hub, sfEvent evt);

#define KRELEASED(evt, keycode)\
    ((evt.type == sfEvtKeyReleased && evt.key.code == keycode) ? 1 : 0)

#define CLICK(evt, keycode)\
    ((evt.mouseButton.type == sfEvtMouseButtonReleased && \
    evt.mouseButton.button == keycode) ? 1 : 0)

#endif /* !DEFENDER_H_ */