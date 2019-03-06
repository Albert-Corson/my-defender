/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** project
*/

#ifndef PROJECT_H_
#define PROJECT_H_

#include "msf/msf.h"

/*
**  STRUCTS
*/
typedef struct ennemy_data_s {
    int level;
    sfBool aerial;
    sfBool ground;
    float max_hp;
    float hp;
    float speed;
} ennemy_data_t;

typedef struct defense_data_s {
    int level;
    sfInt64 firerate;
    float dps;
    float range;
    sfClock *timer;
    obj_t *base;
    obj_t *target;
} defense_data_t;

typedef struct missile_data_s {
    float speed;
    obj_t *sender;
    obj_t *target;
} missile_data_t;

void load_sound_buffers(hub_t *hub);
void create_scenes(hub_t *hub);

// TOOLS
int readjust_nb(int nb, int min, int max);
int random_nbr(sfClock *random);
int random_clamp(sfClock *random, int min, int max);
void other_scenes_sound_apply(hub_t *hub, void (*func)(sfSound *));
void sfx_set_volume(scene_t *scene, float volume);
void outline_focused_btn(hub_t *hub, sfEvent evt);
void outline_hovered_btn(hub_t *hub, sfEvent evt);
void create_volume_slider(scene_t *options);
input_obj_t *create_btn(sfFloatRect box, sfColor bg, int txt_size, char *txt);

// GAME NPC
void *ennemy_new(char *aspect, sfVector2f pos);
void *ennemy_data_new(float max_hp, float speed);
void *defense_new(scene_t *scene, char *aspect, int lvl, sfVector2f pos);
void defense_ctor(anim_obj_t *defense, char *aspect, int lvl);
void defense_dtor(void *defense);
void defense_destroy(void *defense);
void *missile_new(void *launcher, char *aspect);
void defense_update_evt(hub_t *hub, sfEvent evt);
void ennemy_move_evt(hub_t *hub, sfEvent evt);

// CREATE SCENES
void menu_scene_create(hub_t *hub);
void pres_scene_create(hub_t *hub);
void options_scene_create(hub_t *hub);
void game_scene_create(hub_t *hub);
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
void create_img_btn(scene_t *game, char *path, sfVector2f pos, char *label);
void game_create_buttons(scene_t *game);

// PAUSE SCENE
void pause_menu_action(hub_t *hub, void *obj);
void pause_quit_action(hub_t *hub, void *obj);
void pause_resume_action(hub_t *hub, void *obj);
void pause_esc_key(hub_t *hub, sfEvent evt);

#define KRELEASED(evt, keycode)\
    ((evt.type == sfEvtKeyReleased && evt.key.code == keycode) ? 1 : 0)

#endif /* !PROJECT_H_ */