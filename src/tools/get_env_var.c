/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** get_env_var
*/

#include "defender.h"

char *get_env_var(char **envp, char *goal)
{
    int i = 0;
    int len = my_memlen(goal, sizeof(char));

    while (envp[i]) {
        if (my_memcmp(envp[i], goal, len) == 0)
            return (envp[i]);
        ++i;
    }
    return (NULL);
}