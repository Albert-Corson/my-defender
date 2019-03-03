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
    char *aspect;
    int level;
    sfBool aerial;
    sfBool ground;
    float max_hp;
    float hp;
    float speed;
} ennemy_data_t;

typedef struct defense_data_s {
    char *aspect;
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

void *defense_vtable_new(void);
void defense_vtable_destroy(void *obj_vtable);
void menu_create(hub_t *hub);
void *ennemy_new(char *aspect, sfVector2f pos);
void *defense_new(scene_t *scene, char *aspect, int lvl, sfVector2f pos);
void defense_ctor(anim_obj_t *defense, char *aspect, int lvl);
void defense_dtor(void *defense);
void defense_destroy(void *defense);
void turret_create(hub_t *hub);
void *missile_new(void *launcher, char *aspect);

// SCENES
void menu_scene_create(hub_t *hub);
void pres_scene_create(hub_t *hub);
void controls_scene_create(hub_t *hub);
void options_scene_create(hub_t *hub);
void game_scene_create(hub_t *hub);
void test_scene_create(hub_t *hub);

// TOOLS
int readjust_nb(int nb, int min, int max);
int random_nbr(sfClock *random);
int random_clamp(sfClock *random, int min, int max);
void other_scenes_sound_apply(hub_t *hub, void (*func)(sfSound *));
void sfx_set_volume(scene_t *scene, float volume);

#endif /* !PROJECT_H_ */