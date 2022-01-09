/*
** EPITECH PROJECT, 2022
** create_colors
** File description:
** Functions to init colors
*/

#include "runner.h"
#include <stdlib.h>

char **t_dino_d(void)
{
    char **texturedinodead = malloc(sizeof(char *)* 4);
    texturedinodead[0] = "./sprites/dino_dead_blue.png";
    texturedinodead[1] = "./sprites/dino_dead_red.png";
    texturedinodead[2] = "./sprites/dino_dead_yellow.png";
    texturedinodead[3] = "./sprites/dino_dead_green.png";
    return texturedinodead;
}

sfTexture **t_sprite_dino_d(runner_t *runner)
{
    sfTexture **all_t_dino_d = malloc(sizeof(sfTexture *)* 4);
    all_t_dino_d[0] = sfTexture_createFromFile(runner->path_tdino_d[0], NULL);
    all_t_dino_d[1] = sfTexture_createFromFile(runner->path_tdino_d[1], NULL);
    all_t_dino_d[2] = sfTexture_createFromFile(runner->path_tdino_d[2], NULL);
    all_t_dino_d[3] = sfTexture_createFromFile(runner->path_tdino_d[3], NULL);
    return all_t_dino_d;
}
