/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** project
*/

#ifndef PROJECT_H_
#define PROJECT_H_

#include "msf/msf.h"

// SCENES
void menu_scene_create(hub_t *hub);
void pres_scene_create(hub_t *hub);
void controls_scene_create(hub_t *hub);
void options_scene_create(hub_t *hub);

// TOOLS
int readjust_nb(int nb, int min, int max);
int random_nbr(sfClock *random);
int random_clamp(sfClock *random, int min, int max);
void scene_sound_apply(scene_t *scene, void (*func)(sfSound *));
void other_scenes_sound_apply(hub_t *hub, void (*func)(sfSound *));
void list_set_volume(void *obj, float volume);
void sfx_set_volume(scene_t *scene, float volume);

#endif /* !PROJECT_H_ */