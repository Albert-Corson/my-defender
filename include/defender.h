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

// TOOLS
int readjust_nb(int nb, int min, int max);
int random_nbr(sfClock *random);
int random_clamp(sfClock *random, int min, int max);

#endif /* !PROJECT_H_ */